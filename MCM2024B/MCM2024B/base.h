#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct Point {
    double x;
    double y;

    // 构造函数
    Point(double x_val, double y_val) : x(x_val), y(y_val) {}
};

struct Edge {
    Point start;
    Point end;
    double weight;  // 边的权重，可以根据需要更改数据类型

    // 构造函数
    Edge(const Point& start_point, const Point& end_point, double weight_val)
        : start(start_point), end(end_point), weight(weight_val) {}
};