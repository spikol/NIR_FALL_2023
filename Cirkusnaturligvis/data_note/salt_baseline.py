import csv
import itertools
import matplotlib.pyplot as plt

# File path

# Corrected code with the color iterator outside the loop

# Define a color palette (excluding black for 'salt')
colors = itertools.cycle(['b', 'g', 'r', 'c', 'm', 'y'])

# Re-plotting with the corrected code
plt.figure(figsize=(10, 5))

file_path = 'samples_13.csv'  # Replace with the actual file path
with open(file_path, mode='r') as file:  # Using the absolute path
    reader = csv.reader(file)
    x_values = next(reader)[:-2]  # Read the first row and exclude the last two items
    x_values = [float(x) for x in x_values]  # Convert x-axis values to float

    for row in reader:
        try:
            carry_values = [float(value) for value in row[:-2]]  # Exclude the last two items
        except ValueError as e:
            print(f'Error converting value to float: {e}')
            continue

        if len(x_values) != len(carry_values):
            print(f'Skipping row due to length mismatch: x_values length: {len(x_values)}, carry_values length: {len(carry_values)}')
            continue

        legend_item = row[-2]  # Use the second last item as legend
        if legend_item.lower() == 'salt':
            # Plot 'salt' with black color and thicker line
            plt.plot(x_values, carry_values, marker='o', label=legend_item, color='k', linewidth=2)
        else:
            color = next(colors)  # Get the next color from the palette for other lines
            plt.plot(x_values, carry_values, marker='o', label=legend_item, color=color)

# Set the plot title and labels
plt.title('Multiple Response over Wavelength')
plt.xlabel('Wavelength (nm)')
plt.ylabel('Response')
plt.legend(loc='upper right')
plt.grid(True)

# Display the plot
plt.show()
