import numpy as np
import matplotlib.pyplot as plt

# x = np.array([10, 13, 16, 19, 22, 25, 28, 31])
# y = np.array([6.36, 5.04, 3.48, 2.36, 1.88, 1.12, 0.82, 0.68])

# plt.rc('font', family = 'SimHei')
# plt.rc('axes', unicode_minus = False)
# plt.xlabel("距离(cm)")
# plt.ylabel("电压(Vpp)")
# plt.plot(x, y)
# plt.show()

x = np.array([0.601, 0.598, 0.596, 0.598, 0.598, 0.596])
y = np.mean(x)
u = ((1 / 30) * np.sum((x - y) ** 2)) ** 0.5
print(y)
print(u)
