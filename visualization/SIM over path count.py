import matplotlib.pyplot as plt
file_path = 'output.txt'  # 替换为你的文件路径
with open(file_path, 'r') as file:
    # 读取文件内容
    content = file.read()

# 按空格拆分文本内容为列表
data = content.split('\n')
float_values = [float(value) for value in data]
# 绘制折线图
plt.plot(float_values)

# 添加标题和标签
plt.title('Line Chart of SIM Over Path Count')
plt.xlabel('Path Count (every 1000)')
plt.ylabel('SIM')

# 显示图形
plt.show()