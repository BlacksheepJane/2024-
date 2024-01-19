#pragma once
#include "base.h"
const int maxV = 40000, maxE = 100000, maxD = 100000;
void add_edge(int from, int to, double length, vector<Edge>* adj)
{
	adj[from].push_back(Edge{ from, to, length });
}
int dijkstra(int s, int t, int numv, vector<Edge>* adj)//D(s,t)
{
	bool visited[maxV];
	int d[maxV];
	for (int i = 1; i <= numv; i++)
		d[i] = maxD;
	memset(visited, 0, sizeof(visited));
	d[s] = 0;
	int mind = maxD;
	int now = 0;
	while (1) {
		mind = maxD;
		for (int i = 1; i <= numv; i++) {
			if (mind > d[i] && !visited[i])
			{
				mind = d[i];
				now = i;
			}
		}
		if (mind == maxD)
			return d[t];
		if (now == t)
			return d[t];
		visited[now] = 1;
		for (int i = 0; i < adj[now].size(); i++) {
			int to = adj[now][i].end;
			if (d[now] + adj[now][i].weight < d[to])
				d[to] = d[now] + adj[now][i].weight;
		}
	}

}
