import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Load the data
lazyselect_n2 = pd.read_csv('results/results_lazyselect_n2.csv')
lazyselect_n4 = pd.read_csv('results/results_lazyselect_n4.csv')

# Generate x and y values for 2n
x_values = np.linspace(min(lazyselect_n2['size']), max(lazyselect_n2['size']), 500)
y_values = 2 * x_values

#plot number of comparisons
plt.scatter(lazyselect_n2['size'], lazyselect_n2['comparisons'], label='lazyselect',s=5)
# Plot 2n
plt.plot(x_values, y_values, label='2n', linestyle='-', linewidth=2, color='red')

plt.xlabel('Size (n)')
plt.ylabel('Number Comparisons')
plt.title('Lazyselect Number Comparisons')
plt.grid(True)
plt.legend()

plt.savefig('fig/lazyselect_n2_comparisons.png', dpi=300)
plt.show()

# For lazyselect_n4
#plot number of comparisons
plt.scatter(lazyselect_n4['size'], lazyselect_n4['comparisons'], label='lazyselect',s=5)
# Plot 2n
plt.plot(x_values, y_values, label='2n', linestyle='-', linewidth=2, color='red')

plt.xlabel('Size (n)')
plt.ylabel('Number Comparisons')
plt.title('Lazyselect Number Comparisons')
plt.grid(True)
plt.legend()

plt.savefig('fig/lazyselect_n4_comparisons.png', dpi=300)
plt.show()


