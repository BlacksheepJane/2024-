#include "base.h"
using namespace std;
int main() {
    // 打开 CSV 文件
    ifstream file("Case1-vertex.csv");

    // 检查文件是否成功打开
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    // 定义一个二维向量用于存储 CSV 文件的内容
    vector<vector<Point>> vertex;


    // 逐行读取 CSV 文件
    string line;
    while (getline(file, line)) {
        // 使用字符串流分割每行的内容
        stringstream ss(line);
        vector<string> row;

        // 逐个读取逗号分隔的值并存储到向量中
        string value;
        while (getline(ss, value, ',')) {
            row.push_back(value);
        }

        // 将当前行添加到数据向量中
        data.push_back(row);
    }

    // 关闭文件
    file.close();

    // 输出读取的数据（可根据实际情况进行处理）
    for (const auto& row : data) {
        for (const auto& value : row) {
            cout << value << "\t";
        }
        cout << endl;
    }

    return 0;
}