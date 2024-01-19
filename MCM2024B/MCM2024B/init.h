#pragma once
#include "base.h"

vector<Point> initvertices() {
    vector<Point> res;
    std::ifstream file("Case1-vertex.csv");
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
vector<Edge> initedges(unordered_map<pair<int, int>, Edge, pair_hash>& map) {
    vector<Edge> res;
    ifstream file("Case1-edge.csv");
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
        res.push_back(tmp);
        map[{stoi(row[0]), stoi(row[1])}] = tmp;
    }

    file.close();
    return res;
}

void initpath(unordered_map<pair<int, int>, Edge, pair_hash>& map, vector<Edge>* paths, vector<pair<int, int>>& pathse) {
    ifstream file("Case1-path.txt");
    string line;

    while (getline(file, line)) {
        stringstream ss(line);

        pair<int, int> tmp;
        tmp.first = stoi(line.substr(1));
        tmp.second = stoi(line.substr(line.find_last_of(' ')));

        char discard;
        int start, end;

        while (ss >> discard >> start >> discard >> end >> discard >> discard) {
            pathse.push_back(tmp);
            paths[start].push_back(map[{start, end}]);
            break;
        }
    }

    file.close();
}
