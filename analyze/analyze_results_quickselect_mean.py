import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Load the data
quickselect_n2 = pd.read_csv('results/results_quickselect_n2_mean.csv')
quickselect_n4 = pd.read_csv('results/results_quickselect_n4_mean.csv')

# Generate x and y values for 3.386n
x_values = np.linspace(min(quickselect_n2['size']), max(quickselect_n2['size']), 500)
y_values = 3.386 * x_values

#plot number of comparisons
quickselect_n2 = quickselect_n2.groupby('size', as_index=False)['comparisons'].mean().round()
quickselect_n4 = quickselect_n4.groupby('size', as_index=False)['comparisons'].mean().round()

plt.scatter(quickselect_n2['size'], quickselect_n2['comparisons'], s=10)
plt.scatter(quickselect_n4['size'], quickselect_n4['comparisons'], s=10)
plt.plot(quickselect_n2['size'], quickselect_n2['comparisons'], label='Quickselect n/2', linestyle='-')
plt.plot(quickselect_n4['size'], quickselect_n4['comparisons'], label='Quickselect n/4', linestyle='-')
# Plot 3.386n
plt.plot(x_values, y_values, label='3.386n', linestyle='-', linewidth=2, color='red')

plt.xlabel('Size (n)')
plt.ylabel('Number Comparisons')
plt.title('Quickselect Mean Number Comparisons')
plt.grid(True)
plt.legend()

plt.savefig('fig/quickselect_comparisons_mean.png', dpi=300)
plt.show()


