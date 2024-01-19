#pragma once
#include "base.h"
#include "dijkstra.h"
vector<Point> initvertices() {
    vector<Point> res;
    std::ifstream file("Case0-vertex.csv");
    // ���ж�ȡ CSV �ļ�
    string line;
    getline(file, line);
    while (getline(file, line)) {
        // ʹ���ַ������ָ�ÿ�е�����
        stringstream ss(line);
        vector<string> row;

        // �����ȡ���ŷָ���ֵ���洢��������
        string value;
        while (getline(ss, value, ',')) {
            row.push_back(value);
        }
        Point tmp(stod(row[1]), stod(row[2]));
        // ����ǰ����ӵ�����������
        res.push_back(tmp);
    }

    // �ر��ļ�
    file.close();
    return res;
}
void initedges(unordered_map<pair<int, int>, Edge, pair_hash>& map, vector<Edge>* edges) {
    ifstream file("Case0-edge.csv");
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
        // ����ǰ����ӵ�����������
        edges[stoi(row[0])].push_back(tmp);
        map[{stoi(row[0]), stoi(row[1])}] = tmp;
    }

    file.close();
}
int numv;
double SIM(unordered_map<pair<int, int>, Edge, pair_hash>& map, vector<Edge>* paths, vector<Edge>* edges) {
    ifstream file("Case0-path.txt");
    string line;
    int simcnt = 0, cnt = 0;

    while (getline(file, line)) {
        int pathlength = 0;
        int minlength = 0;
        stringstream ss(line);
        int s = stoi(line.substr(1)), t = stoi(line.substr(line.find_last_of(' ')));
        //pair<int, int> tmp;
        //tmp.first = stoi(line.substr(1));
        //tmp.second = stoi(line.substr(line.find_last_of(' ')));
        minlength = dijkstra(s, t, numv, edges);
        char discard;
        int start, end;

        while (ss >> discard >> start >> discard >> end >> discard >> discard) {
            //pathse.push_back(tmp);
            //paths[start].push_back(map[{start, end}]);
            pathlength += map[{start, end}].weight;
        }
        pathlength += map[{start, end}].weight;
        if (pathlength == minlength) 
            simcnt++;
        cnt++;
    }

    file.close();
    return 1.0 * simcnt / cnt;
}
