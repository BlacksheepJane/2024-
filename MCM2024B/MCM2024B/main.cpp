#include "init.h"

using namespace std;
int main() {
    vector<Point> vertices = initvertices();
    numv = vertices.size();
    unordered_map<pair<int, int>, Edge, pair_hash> map;
    vector<Edge> edges[maxV];
    initedges(map, edges);
    vector<Edge> paths[maxV];
    vector<pair<int, int>> pathse;
    //initpath(map, paths, pathse);
    cout << SIM(map, paths, edges) << endl;

    return 0;
}