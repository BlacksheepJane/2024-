#pragma once
#include "base.h"
vector<int>	Edge e[maxE];
int djkstra(int s, int t, vector<Point>& vertices, vector<Edge>& edges)//D(s,t)
{
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
		for (int i = first[now]; i != 0; i = nxt[i]) {
			if (d[now] + edges[i].weight < d[edges[i].end])
				d[edges[i].end] = d[now] + edges[i].weight;
		}
	}
}