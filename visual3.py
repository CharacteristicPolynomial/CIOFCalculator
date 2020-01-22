import numpy as np
import matplotlib.pyplot as plt
# This import registers the 3D projection, but is otherwise unused.
from mpl_toolkits.mplot3d import Axes3D  # noqa: F401 unused import


def visualize_gis(gis):
    # setup the figure and axes
    m = gis.shape[0]
    n = gis.shape[1]

    fig = plt.figure(figsize=(4*m,4))
    ax = fig.add_subplot(111, projection='3d')
    _x = np.arange(n*m)
    _y = np.arange(n)
    _xx, _yy = np.meshgrid(_x, _y)
    x, y = _xx.ravel(), _yy.ravel()

    gis = np.concatenate(gis, axis=1)
    top = gis.flatten()
    #top = np.clip(top, 0, 5000)
    c = plt.cm.jet(top/np.max(top))
    c[:,3] = 0.7
    bottom = np.zeros_like(top)
    width = depth = 0.7
    print(x.shape, y.shape, bottom.shape, top.shape)
    ax.bar3d(x, y, bottom, width, depth, top, shade=True, color = c)

    # _x = np.arange(n)
    # _y = np.arange(n)
    # _xx, _yy = np.meshgrid(_x, _y)
    # x, y = _xx.ravel(), _yy.ravel()
    # width = depth = 0.3
    # ax.bar3d(x, y, low.flatten(), width, depth, mid.flatten(), shade=True, color = 'blue')
    # ax.bar3d(x, y, mid.flatten(), width, depth, high.flatten(), shade=True, color = 'red')



    ax.set_title('gi.array')
    ax.set_xlabel('state of block 1')
    ax.set_ylabel('state of block 2')
    ax.set_zlabel('estimates')
    plt.show()

gi1 = np.loadtxt('gi.array')
gi2 = np.loadtxt('gi2.array')
gi3 = np.loadtxt('gi3.array')

# hyper = np.loadtxt('hyper.array')
visualize_gis(np.array([gi1, gi3, gi2]))
