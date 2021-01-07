import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt('sch_1.dat')
plt.title('Solution of Schrodinger Equation for Ground State')
plt.ylabel('$\psi$, d$\psi$/dx')
plt.xlabel('x')
plt.ylim(-0.3,1)
plt.xlim(0,6)
plt.plot(data[:,0], data[:,1],'-r',label='$\psi$')
plt.plot(data[:,0], data[:,2],'-b',label='d$\psi$/dx')
plt.legend()
plt.show()