import pandas as pd
import matplotlib.pyplot as plt
import itertools

# Function to read and normalize data
def read_and_normalize(file_path):
    df = pd.read_csv(file_path)
    # Assuming the last two columns are non-numeric (labels, etc.), and the rest are the data to be normalized
    data_columns = df.columns[:-2]
    # Normalize such that each row sums to 1
    df_normalized = df[data_columns].div(df[data_columns].sum(axis=1), axis=0)
    return df_normalized

# File paths
file_paths = ['samples_06.csv', 'samples_13.csv', 'samples_29.csv']

# Read and normalize data from each file
normalized_data = [read_and_normalize(file) for file in file_paths]

# Calculate average normalized response at each wavelength for each file
average_responses = [df.mean() for df in normalized_data]

# Extracting wavelength values from the columns (assuming all files have the same wavelengths)
wavelengths = normalized_data[0].columns

# Creating a DataFrame for easier plotting
average_responses_df = pd.DataFrame(average_responses, index=['samples_06', 'samples_13', 'samples_29'])
average_responses_df = average_responses_df.T  # Transpose for easier plotting

# Plotting the average responses
plt.figure(figsize=(12, 6))

for sample_id in average_responses_df.columns:
    plt.plot(wavelengths, average_responses_df[sample_id], marker='o', label=sample_id)

plt.title('Average Normalized Response over Wavelength')
plt.xlabel('Wavelength (nm)')
plt.ylabel('Normalized Response')
plt.legend(title='Sample Set')
plt.grid(True)

# Display the plot
plt.show()

# Printing the table of average responses
print("Table of Average Normalized Responses:")
print(average_responses_df)