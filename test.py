import pylab
import numpy as np

a, b, n = 0, 14 * np.pi, 3500
angs = np.linspace(a, b, n)
rs = np.sin(8 * angs / 7)
pylab.polar(angs, rs, lw=3)
pylab.title("graph of sin(8x/7) for x in [0, 14pi]")
pylab.show()