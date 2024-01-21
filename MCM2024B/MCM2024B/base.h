#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<algorithm>
using namespace std;
const int maxV = 40000, maxE = 100000, maxD = 1000000;

struct Point {
    double x;
    double y;

    // ���캯��
    Point(double x_val, double y_val) : x(x_val), y(y_val) {}
};

struct Edge {
    int start;
    int end;
    double weight;  // �ߵ�Ȩ�أ����Ը�����Ҫ������������

    // ���캯��
    Edge(){}
    Edge(int start_point, int end_point, double weight_val)
        : start(start_point), end(end_point), weight(weight_val) {}
};

// �Զ����ϣ����
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // ����ʹ�������������Ϲ�ϣֵ
        return h1 ^ h2;
    }
};