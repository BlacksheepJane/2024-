#pragma once
#include "base.h"

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
vector<Edge> initedges() {
    vector<Edge> res;
    ifstream file("Case1-vertex.csv");
    string line;
    getline(file, line);
    while (getline(file, line)) {
        stringstream ss(line);
        vector<string> row;
        string value;
        while (getline(ss, value, ',')) {
            row.push_back(value);
        }
        Edge tmp(stoi(row[1]), stoi(row[2]), stod(row[0]));
        // 将当前行添加到数据向量中
        res.push_back(tmp);
    }

    file.close();
    return res;
}