import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import csv
import sys

# OUTPUT sin function
# to plot float 0 and float 8200
# python3 plot_two_graphs.py data/data_output_sin_float_0.csv data/data_output_sin_float_8200.csv

# to plot double 0 and double 8200
# python3 plot_two_graphs.py data/data_output_sin_double_0.csv data/data_output_sin_double_8200.csv

# to plot float 0 and double 0
# python3 plot_two_graphs.py data/data_output_sin_float_0.csv data/data_output_sin_double_0.csv

# to plot float 8200 and double 8200
# python3 plot_two_graphs.py data/data_output_sin_float_8200.csv data/data_output_sin_double_8200.csv



# phase
# to plot float 0 and float 8200
# python3 plot_two_graphs.py data/data_phase_delta_float_0.csv data/data_phase_delta_float_8200.csv

# to plot double 0 and double 8200
# python3 plot_two_graphs.py data/data_phase_delta_double_0.csv data/data_phase_delta_double_8200.csv

# to plot float 0 and double 0
# python3 plot_two_graphs.py data/data_phase_delta_float_0.csv data/data_phase_delta_double_0.csv

# to plot float 8200 and double 8200
# python3 plot_two_graphs.py data/data_phase_delta_float_8200.csv data/data_phase_delta_double_8200.csv






# create a list and import data from output.csv file
input_1 = sys.argv[1]
input_2 = sys.argv[2]



def load_data(file_path):
    data = list()
    with open(file_path, 'r') as file:
        reader = csv.reader(file)
        for row in reader:
            data.append(float(row[0]))
        return data

data_1 = load_data(input_1)
data_2 = load_data(input_2)


# transform list to numpy array
np_data_1 = np.array(data_1)
np_data_2 = np.array(data_2)

# create samples for x axis
t = np.arange(0, len(np_data_1), 1)

# create plot
fig, ax = plt.subplots()
ax.plot(t, np_data_1)
ax.plot(t, np_data_2)
y_min = min(np_data_1)
y_max = max(np_data_1)
print("y min:", y_min, "y_max:", y_max)
if(y_min == y_max):
    y_min = y_min - 0.001
    y_max = y_max + 0.001

plt.yticks(np.arange(y_min, y_max, (y_max - y_min) / 2))
ax.set(xlabel='sample', ylabel='output value',
       title="two_graphs")
ax.grid()

plt.show()
