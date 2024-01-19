#pragma once
#include "base.h"

inline void add_edge(int from, int to, double length, vector<Edge>* adj)
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
			int to = adj[now][i].start;
			if (d[now] + adj[now][i].weight < d[to])
			{
				d[to] = d[now] + adj[now][i].weight;
				q.push({ d[to], to });
			}
		}
	}

}
