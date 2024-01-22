import pandas as pd
import matplotlib.pyplot as plt

# 从CSV文件读取数据
df = pd.read_csv('Case1-vertex.csv')  # 替换为你的CSV文件路径

# 提取X和Y坐标数据
labels = df.iloc[:, 0].tolist()
x_points = df.iloc[:, 1].tolist()
y_points = df.iloc[:, 2].tolist()
point_dict = {}
# 可视化点并添加标号
for label, x, y in zip(labels, x_points, y_points):
    plt.scatter(x, y, color='blue', label='Points')
    plt.text(x, y, str(label), ha='right', va='bottom')  # 添加标号
    point_dict[label] = (x, y)  # 将标号和坐标添加到字典中

# 添加标题和标签
plt.title('Point and Line Visualization with Labels')
plt.xlabel('X-axis')
plt.ylabel('Y-axis')

# 添加图例
plt.legend()

# 显示图形
plt.show()

# 现在，point_dict中包含了每个点的标号和坐标
print("Point Dictionary:", point_dict)