import csv
import matplotlib.pyplot as plt

# File path
filename = 'samples_13.csv'

# Initialize the plot
plt.figure(figsize=(10, 5))

with open(filename, mode='r') as file:
    reader = csv.reader(file)
    x_values = next(reader)[:-2]  # Read the first row and exclude the last two items
    x_values = [float(x) for x in x_values]  # Convert x-axis values to float

    for row in reader:
        try:
            carry_values = [float(value) for value in row[:-2]]  # Exclude the last two items
        except ValueError as e:
            print(f'Error converting value to float: {e}')
            continue  # Skip to the next row if there is an error converting value

        if len(x_values) != len(carry_values):
            print(f'Skipping row due to length mismatch: x_values length: {len(x_values)}, carry_values length: {len(carry_values)}')
            continue  # Skip to the next row if there is a length mismatch

        legend_item = row[-2]  # Use the second last item as legend
        plt.plot(x_values, carry_values, marker='o', label=legend_item)

# Set the plot title and labels
plt.title('Multiple Response over Wavelength')
plt.xlabel('Wavelength (nm)')
plt.ylabel('Response')
plt.legend(loc='upper right')
plt.grid(True)

# Display the plot
plt.show()
