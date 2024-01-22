#pragma once
#include "base.h"
#include "dijkstra.h"
vector<Point> initvertices() {
    vector<Point> res;
    std::ifstream file("Case1-vertex.csv");
    // 逐行读取 CSV 文件
    string line;
    getline(file, line);
    while (getline(file, line)) {
        // 使用字符串流分割每行的内容
        stringstream ss(line);
        vector<string> row;

        // 逐个读取逗号分隔的值并存储到向量中
        string value;
        while (getline(ss, value, ',')) {
            row.push_back(value);
        }
        Point tmp(stod(row[1]), stod(row[2]));
        // 将当前行添加到数据向量中
        res.push_back(tmp);
    }

    // 关闭文件
    file.close();
    return res;
}
void initedges(unordered_map<pair<int, int>, Edge, pair_hash>& map, vector<Edge>* edges) {
    ifstream file("Case1-edge.csv");
    string line;
    getline(file, line);
    int lastu = 0, lastv = 0, u, v, length;
    while (getline(file, line)) {
        stringstream ss(line);
        vector<string> row;
        string value;
        while (getline(ss, value, ',')) {
            row.push_back(value);
        }
        u = stoi(row[0]), v = stoi(row[1]), length = stod(row[2]);
        if (lastu == u && lastv == v) continue;
        lastu = u, lastv = v;
        Edge tmp(u,v,length);
        // 将当前行添加到数据向量中
        edges[u].push_back(tmp);
        map[{u, v}] = tmp;
    }
    file.close();
}
void initpr(unordered_map<pair<int, int>, Edge, pair_hash>& prmap) {
    ifstream file("pr.csv");
    string line;
    getline(file, line);
    while (getline(file, line)) {
        stringstream ss(line);
        vector<string> row;
        string value;
        while (getline(ss, value, ',')) {
            row.push_back(value);
        }

        Edge tmp(stoi(row[0]), stoi(row[1]), stod(row[2]));
        // 将当前行添加到数据向量中
        prmap[{stoi(row[0]), stoi(row[1])}] = tmp;
    }

    file.close();
}
int numv;
static double SIM(unordered_map<pair<int, int>, Edge, pair_hash>& map, vector<Edge>* edges) {
    ifstream file("path.txt");
    string line;
    int simcnt = 0, cnt = 0, start0 = -1;
    int d[maxV];
    while (getline(file, line)) {
        istringstream ss(line);

        int pathlength = 0;
        int start, end;
        ss >> start;
        if (start0 != start) {
            dijkstra(start, d, numv, edges, map);
            start0 = start;
        }
        while (ss >> end) {
            pathlength += map[{start, end}].weight;
            start = end;
        }
        if (pathlength == d[end]) {
            simcnt++;
        }
        cnt++;
    }

    file.close();
    return 1.0 * simcnt / cnt;
}
static pa SA(pa now, unordered_map<pair<int, int>, Edge, pair_hash>& pr, unordered_map<pair<int, int>, Edge, pair_hash>& length, vector<Edge>* edges, vector<Point> v) {
    unordered_map<pair<int, int>, Edge, pair_hash> weight;
    ofstream myfile;
    myfile.open("res.csv", std::ios::app);
    cal_weight(now, weight, pr, length, v);
    double sim1, sim2, dsim;
    myfile << '\n';
    cout << now.a << ',' << now.b << ',' << now.c << endl;
    sim1 = SIM(weight, edges);
    myfile << now.a << ',' << now.b << ',' << now.c << ',' << sim1 << '\n';
    cout << now.a << ',' << now.b << ',' << now.c << ',' << sim1 << '\n';
    double T = 30, T_end = 1;
    while (T > T_end) {
        pa par = update(now);
        cal_weight(par, weight, pr, length, v);
        cout << par.a << ',' << par.b << ',' << par.c << endl;
        sim2 = SIM(weight, edges);

        dsim = (sim2 - sim1) * 10000;
        myfile << par.a << ',' << par.b << ',' << par.c << ',' << sim2 << ',' << dsim << ',' << T << ',';
        cout << par.a << ',' << par.b << ',' << par.c << ',' << sim2 << ',' << dsim << ',' << T << ',';
        if (dsim < 0) {
            double r;
            r = (double)rand() / RAND_MAX;
            if (r < exp(dsim / T)) {
                myfile << "accept" << '\n';
                cout << "accept" << '\n';
                now = par;
                sim1 = sim2;
            }
            else {
                myfile << "reject" << '\n';
                cout << "reject" << '\n';
            }
        }
        else {
            myfile << "accept" << '\n';
            cout << "accept" << '\n';
            now = par;
            sim1 = sim2;
        }
        T *= 0.9;
    }
    myfile.close();
    return now;
}