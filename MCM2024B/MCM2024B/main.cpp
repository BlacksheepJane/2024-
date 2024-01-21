#include "init.h"

using namespace std;
int main() {
    std::srand(std::time(0));
    vector<Point> vertices = initvertices();
    numv = vertices.size();

    unordered_map<pair<int, int>, Edge, pair_hash> map;
    vector<Edge> edges[maxV];
    initedges(map, edges);

    unordered_map<pair<int, int>, Edge, pair_hash> prmap;
    initpr(prmap);

    pa now = { 5,1,1 };
    cout << now.a << ' ' << now.b << ' ' << now.c << endl;
    now = SA(now, prmap, map, edges, vertices);

    //cout << SIM(map,edges) << endl;

    return 0;
}