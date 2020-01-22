import numpy as np
import matplotlib.pyplot as plt
# This import registers the 3D projection, but is otherwise unused.
from mpl_toolkits.mplot3d import Axes3D  # noqa: F401 unused import

n = 16
m = 2
s = 10000
t = 100000
d = 100

lamb = np.zeros([n,n])
for i in range(n) :
    for j in range(n):
        if i == n-1 :
            a = 1
        else:
            a = 1 - np.exp2(-i-1)
        if j == n-1 :
            b = 1
        else:
            b = 1 - np.exp2(-j-1)
        lamb[i,j] = (a + b)/2.0

fig = plt.figure(figsize=(5,5))
ax = fig.add_subplot(111, projection='3d')
for k in range(s, t, d):
    mat = np.zeros([n,n])
    for i in range(n):
        for j in range(n):
            if i == 0 :
                if j == 0:
                    mat[i,j] = np.power(lamb[i,j], k)
                else:
                    mat[i,j] = np.power(lamb[i,j], k) - np.power(lamb[i,j-1], k)
            else:
                if j == 0:
                    mat[i,j] = np.power(lamb[i,j], k) - np.power(lamb[i-1,j], k)
                else:
                    mat[i,j] = np.power(lamb[i,j], k) - np.power(lamb[i,j-1], k) \
                    - np.power(lamb[i-1,j], k) + np.power(lamb[i-1,j-1], k)
    
    ax.clear()
    ax.set_zlim3d(0, 0.1)

    _x = np.arange(n)
    _y = np.arange(n)
    _xx, _yy = np.meshgrid(_x, _y)
    x, y = _xx.ravel(), _yy.ravel()

    top = mat.flatten()
    c = plt.cm.jet(top/np.max(top))
    c[:,3] = 0.7
    bottom = np.zeros_like(top)
    width = depth = 0.7
    ax.bar3d(x, y, bottom, width, depth, top, shade=True, color = c)
    plt.savefig('steps3/step_'+str(k)+'.png')
    # plt.show()
