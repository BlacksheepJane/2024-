#pragma once
#include "base.h"

inline void add_Edge(int from, int to, double length, vector<Edge>* adj)
{
	adj[from].push_back(Edge{ from, to, length });
}
inline int dijkstra(int s, int t, int numv, vector<Edge>* adj)//D(s,t)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	int d[maxV];
	bool visited[maxV];
	for (int i = 1; i <= numv; i++)
		d[i] = maxD;
	memset(visited, 0, sizeof(visited));
	d[s] = 0;
	int mind = maxD;
	int now = 0;
	q.push({ 0, s });
	while (1) {
		mind = maxD;
		auto x = q.top();
		q.pop();
		int now = x.second, mind = x.first;
		if (visited[now])
			continue;
		if (mind == maxD)
			return d[t];
		if (now == t)
			return d[t];
		visited[now] = 1;
		for (int i = 0; i < adj[now].size(); i++) {
			int to = adj[now][i].end;
			if (d[now] + adj[now][i].weight < d[to])
			{
				d[to] = d[now] + adj[now][i].weight;
				q.push({ d[to], to });
			}
		}
	}

}
void Page_Rank(vector<Edge>* adj, vector<Edge>* antiadj, int numv, double* p,double a) {
	vector <Edge>new_Adj[maxV];
	vector <Edge>new_Antiadj[maxV];
	for (int i = 0; i < numv; i++) {
		double pr = 0;
		for (int k = 0; k < antiadj[i].size(); k++)
			pr += antiadj[i][k].weight;
		pr *= a;
		pr += p[i];
		pr /= adj[i].size();
		for (int j = 0; j < adj[i].size(); j++)
		{
			add_Edge(i, adj[i][j].end, pr, new_Adj);
			add_Edge(adj[i][j].end, i, pr, new_Antiadj);
		}
	}
	for (int i = 0; i < numv; i++)
	{
		for (int j = 0; j < adj[i].size(); j++)
			adj[i][j] = new_Adj[i][j];
		for (int j = 0; j < antiadj[i].size(); j++)
			antiadj[i][j] = new_Antiadj[i][j];
	}
}
void output(vector<Edge>* adj,int numv) {
	std::ofstream myfile;
	myfile.open("example.csv");
	for (int i = 0; i < numv; i++)
		for (int j = 0; j < adj[i].size(); j++)
		{
			myfile << i;
			myfile << ",";
			myfile << adj[i][j].end;
			myfile << ",";
			myfile << adj[i][j].weight;
			myfile << ",\n";
		}
	myfile.close();
}
