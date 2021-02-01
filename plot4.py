import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt('sch_4.dat')
plt.title('Solution of Schrodinger Equation for Morse Potential')
plt.ylabel('$\psi$, d$\psi$/dx', fontsize=14)
plt.xlabel('x', fontsize=14)
plt.ylim(-1,1)
plt.xlim(0,5)
plt.plot(data[:,0], data[:,1],'-r',label='$\psi$')
plt.plot(data[:,0], data[:,2],'-b',label='d$\psi$/dx')
plt.legend()
plt.show()