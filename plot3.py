import numpy as np
import matplotlib.pyplot as plt

data1 = np.loadtxt('sch_3a.dat')
data2 = np.loadtxt('sch_3b.dat')
data3 = np.loadtxt('sch_3c.dat')
plt.title('Solution of Schrodinger Equation for Harmonic Oscillator')
plt.ylabel('$\psi$, d$\psi$/dx')
plt.xlabel('x')
plt.ylim(-2,2)
plt.xlim(0,5)
plt.plot(data1[:,0], data1[:,1],'-r',label='$\psi$')
plt.plot(data1[:,0], data1[:,2],'-b',label='d$\psi$/dx')
plt.legend()
plt.show()