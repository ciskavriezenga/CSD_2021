import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import csv

def plot_file(file_path, output_file_name):
    # create a list and import data from output.csv file
    data = list()
    with open(file_path, 'r') as file:
        reader = csv.reader(file)
        for row in reader:
            data.append(float(row[0]))

    # transform list to numpy array
    np_data = np.array(data)

    # create samples for x axis
    t = np.arange(0, len(data), 1)

    # create plot
    fig, ax = plt.subplots()
    ax.plot(t, np_data)
    y_min = min(data)
    print(y_min)
    y_max = max(data)
    print(y_max)
    plt.yticks(np.arange(y_min, y_max, (y_max - y_min) / 2))
    ax.set(xlabel='sample', ylabel='output value',
           title=output_file_name)
    ax.grid()

    # To save the result, outcomment the line below:
    fig.savefig(output_file_name + ".png")
    plt.show()

plot_file('data/data_output_sin.csv', 'plot_output_sin')
plot_file('data/data_input_sin.csv', 'plot_input_sin')
plot_file('data/data_input_sin_delta.csv', 'plot_input_sin')
