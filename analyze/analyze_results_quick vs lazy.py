import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Load the data
quickselect_n2 = pd.read_csv('results/results_quickselect_n2.csv')
quickselect_n4 = pd.read_csv('results/results_quickselect_n4.csv')
lazyselect_n2 = pd.read_csv('results/results_lazyselect_n2.csv')
lazyselect_n4 = pd.read_csv('results/results_lazyselect_n4.csv')

# plot time
plt.scatter(quickselect_n2['size'], quickselect_n2['time'], label='Quickselect',s=5)
plt.scatter(lazyselect_n2['size'], lazyselect_n2['time'], label='Lazyselect',s=5)

plt.xlabel('Size (n)')
plt.ylabel('Time (s)')
plt.title('Quickselect vs Lazyselect Time')
plt.grid(True)
plt.legend()

plt.savefig('fig/quick_lazy_time_n2.png', dpi=300)
plt.show()

# For quickselect_n4
# plot number of comparisons
plt.scatter(quickselect_n4['size'], quickselect_n4['time'], label='Quickselect',s=5)
plt.scatter(lazyselect_n4['size'], lazyselect_n4['time'], label='Lazyselect',s=5)

plt.xlabel('Size (n)')
plt.ylabel('Time (s)')
plt.title('Quickselect vs Lazyselect Time')
plt.grid(True)
plt.legend()

plt.savefig('fig/quick_lazy_time_n4.png', dpi=300)
plt.show()


