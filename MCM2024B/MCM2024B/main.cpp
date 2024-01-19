#include "init.h"

using namespace std;
const int maxV = 40000, maxE = 100000, maxD = 100000;
int main() {
    vector<Point> vertices = initvertices();
    unordered_map<pair<int, int>, Edge, pair_hash> map;
    vector<Edge> edges = initedges(map);
    vector<Edge> paths[maxV];
    vector<pair<int, int>> pathse;
    initpath(map, paths, pathse);
    cout << vertices[100].x << endl << edges[10].weight << endl << paths[11034][0].end << endl << pathse[0].first << ' ' << pathse[0].second << endl;

    return 0;
}