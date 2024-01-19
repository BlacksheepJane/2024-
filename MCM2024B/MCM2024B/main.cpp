#include "init.h"
using namespace std;
int main() {
    vector<Point> vertices = initvertices();
    vector<Edge> edges = initedges();

    cout << vertices[100].x << endl << edges[10].weight << endl;

    return 0;
}