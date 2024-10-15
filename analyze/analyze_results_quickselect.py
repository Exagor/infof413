import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Load the data
quickselect_n2 = pd.read_csv('results/results_quickselect_n2.csv')
quickselect_n4 = pd.read_csv('results/results_quickselect_n4.csv')

# Generate x and y values for 3.386n
x_values = np.linspace(min(quickselect_n2['size']), max(quickselect_n2['size']), 500)
y_values = 3.386 * x_values

#plot number of comparisons
plt.scatter(quickselect_n2['size'], quickselect_n2['comparisons'], label='Quickselect',s=5)
# Plot 3.386n
plt.plot(x_values, y_values, label='3.386n', linestyle='-', linewidth=2, color='red')

plt.xlabel('Size (n)')
plt.ylabel('Number Comparisons')
plt.title('Quickselect Number Comparisons')
plt.grid(True)
plt.legend()

plt.savefig('fig/quickselect_n2_comparisons.png', dpi=300)
plt.show()

# For quickselect_n4
#plot number of comparisons
plt.scatter(quickselect_n4['size'], quickselect_n4['comparisons'], label='Quickselect',s=5)
# Plot 3.386n
plt.plot(x_values, y_values, label='3.386n', linestyle='-', linewidth=2, color='red')

plt.xlabel('Size (n)')
plt.ylabel('Number Comparisons')
plt.title('Quickselect Number Comparisons')
plt.grid(True)
plt.legend()

plt.savefig('fig/quickselect_n4_comparisons.png', dpi=300)
plt.show()


