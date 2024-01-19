#include<vector>
#include <fstream>
#include <queue>
#include<iostream>
#include<cstring> 
#include<iostream>
#include <sstream>
using namespace std;
const int maxV = 40000,maxE=100000,maxD=100000;
vector <int>p;
int first[maxV], nxt[maxE], d[maxV]; 
bool visited[maxV];
int numv=0,nume=0;
priority_queue<int, vector<int>, greater<int> > dd;
struct edge {
	int length;
	int from;
	int to;
};
edge e[maxE];
void add_edge(int from, int to, int length)
{
	e[++nume].from = from;
	e[nume].length = length;
	e[nume].to = to;
	nxt[nume] = first[from];
	first[from] = nume;
}
int djkstra(int s, int t)//D(s,t)
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
			if (mind > d[i]&&!visited[i])
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
		for (int i = first[now];i!=0 ; i = nxt[i]) {
			if (d[now] + e[i].length < d[e[i].to])
				d[e[i].to] = d[now] + e[i].length;
		}
	}
	
}
int main() {
	ifstream file("Case1-path.txt");
	string line;
	int n = 0;
	while (getline(file, line)) {
		n++;
	}
	cout << n;
	return 0;
}