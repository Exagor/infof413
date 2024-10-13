import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Load the data
data = pd.read_csv('results/results.csv')

# Generate x and y values for x*log(x)
x_values = np.linspace(min(data['size']), max(data['size']), 500)
y_values = x_values * np.log(x_values)
# y_values = 3.386 * x_values

#plot time taken
plt.plot(data['size'], data['time'], label='Quicksort', linestyle='-', linewidth=1)
plt.xlabel('Size of the list')
plt.ylabel('Time Taken (s)')
plt.title('Quicksort Time')
plt.grid(True)
plt.legend()

plt.savefig('fig/quicksort_time.png', dpi=300)
plt.show()


#plot number of comparisons
plt.plot(data['size'], data['comparisons'], label='Quicksort', linestyle='-', linewidth=1)

# Plot n*log(n)
plt.plot(x_values, y_values, label='n*log(n)', linestyle='--', linewidth=2)

plt.xlabel('Size of the list')
plt.ylabel('Number Comparisons')
plt.title('Quicksort Number Comparisons')
plt.grid(True)
plt.legend()

plt.savefig('fig/quicksort_comparisons.png', dpi=300)
plt.show()


