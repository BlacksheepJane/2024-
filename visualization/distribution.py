import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np

# 生成一些示例数据
np.random.seed(42)
x1 = np.random.rand(100)
x2 = np.random.rand(100)
y = 2 * x1 + 3 * x2 + np.random.randn(100)  # 示例线性关系，添加噪声

# 创建3D图
fig = plt.figure(figsize=(10, 8))
ax = fig.add_subplot(111, projection='3d')

# 绘制散点图
ax.scatter(x1, x2, y, c='b', marker='o')

# 设置坐标轴标签
ax.set_xlabel('Parameter 1')
ax.set_ylabel('Parameter 2')
ax.set_zlabel('Y')

# 设置图表标题
plt.title('3D Scatter Plot of Parameters vs Y')

# 显示图表
plt.show()
