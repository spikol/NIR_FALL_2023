import pandas as pd
import matplotlib.pyplot as plt

# Load the dataset
file_path = 'path_to_your_file/samples_29.csv'  # Replace with your file path
data = pd.read_csv(file_path)

# Resetting the index to convert index values into columns
data_reset = data.reset_index()

# Renaming columns for clarity
column_names = ['Value' + str(i) for i in range(1, len(data_reset.columns) - 1)]
data_reset.columns = column_names + ['Response', 'Additional Item']

# Filtering data to include only the value columns and the response (item name)
plot_data = data_reset.set_index('Response').drop('Additional Item', axis=1)

# Creating the plot
plt.figure(figsize=(12, 6))
for item in plot_data.index:
    plt.plot(plot_data.columns, plot_data.loc[item], label=item)
    if item == 'salt':
        plt.plot(plot_data.columns, plot_data.loc[item], label=item, color='black', linewidth=2.5)  # Emphasize the salt line

plt.title('Comparison of Measurements with Salt as Baseline')
plt.xlabel('Measurement Number')
plt.ylabel('Value')
plt.legend()
plt.grid(True)
plt.show()
