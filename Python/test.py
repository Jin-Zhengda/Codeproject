import numpy as np
import matplotlib.pyplot as plt

d = np.array([29.360-28.562,29.360-28.560,29.366-28.564,29.362-28.559,29.364-28.564])
d_me = np.mean(d)
print(d_me)
d_me = d_me * 10e-3
pho = 7800
g = 9.78
pho0 = 950
D = 0.02
de_t = 0.2
L = 0.2

t = 6.41

k = (pho - pho0) * d_me  ** 2 * t / (18 * L * (1 + 2.4 * d_me / D))
print(k)

plt.plot([30, 36, 42, 50, 60], [0.06, 0.027, 0.016, 0.01, 0.007])
plt.show()
