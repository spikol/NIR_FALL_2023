import matplotlib.pyplot as plt

# Data from your JSON files
sessions = {
    "2023-09-09T11:27:58Z": {'Average Pause Duration (APD)': 4.02, 'Participation Equality (PEQ)': 0.738, 'Turn Taking Count (TTC)': 764, 'Silence Ratio (SR)': 0.072},
    "2023-09-09T12:39:44Z": {'Average Pause Duration (APD)': 2.25, 'Participation Equality (PEQ)': 0.862, 'Turn Taking Count (TTC)': 946, 'Silence Ratio (SR)': 0.024},
    "2023-09-09T14:21:42Z": {'Average Pause Duration (APD)': 6.07, 'Participation Equality (PEQ)': 0.727, 'Turn Taking Count (TTC)': 289, 'Silence Ratio (SR)': 0.293},
    "2023-09-10T07:04:50Z": {'Average Pause Duration (APD)': 1.91, 'Participation Equality (PEQ)': 0.926, 'Turn Taking Count (TTC)': 1029, 'Silence Ratio (SR)': 0.007},
    "2023-09-10T08:56:43Z": {'Average Pause Duration (APD)': 1.8, 'Participation Equality (PEQ)': 0.681, 'Turn Taking Count (TTC)': 65, 'Silence Ratio (SR)': 0.033}
}

# Separate data for plotting
session_labels = list(sessions.keys())
apd = [info['Average Pause Duration (APD)'] for info in sessions.values()]
peq = [info['Participation Equality (PEQ)'] for info in sessions.values()]
ttc = [info['Turn Taking Count (TTC)'] for info in sessions.values()]
sr = [info['Silence Ratio (SR)'] for info in sessions.values()]

# Create a new figure with sub-plots (2 rows, 1 column), with a specified figure size
fig, axs = plt.subplots(2, 1, figsize=(12, 10))  # Adjust the size as necessary

# First plot comparing APD and TTC
ax1 = axs[0]
line1, = ax1.plot(session_labels, apd, marker='o', color='b', label='APD')
ax1.set_xlabel('Session')
ax1.set_ylabel('Average Pause Duration (APD)', color='b')
ax1.tick_params(axis='y', labelcolor='b')

ax2 = ax1.twinx()  # instantiate a second y-axis that shares the same x-axis
line2, = ax2.plot(session_labels, ttc, marker='o', color='g', label='TTC')
ax2.set_ylabel('Turn Taking Count (TTC)', color='g')  
ax2.tick_params(axis='y', labelcolor='g')

ax1.set_title('APD and TTC Comparison')
ax1.set_xticklabels(session_labels, rotation=45, ha="right")  # Rotate session labels for readability
lines = [line1, line2]
ax1.legend(lines, [l.get_label() for l in lines])

# Second plot comparing PEQ and SR
ax3 = axs[1]
line3, = ax3.plot(session_labels, peq, marker='o', color='r', label='PEQ')
ax3.set_xlabel('Session')
ax3.set_ylabel('Participation Equality (PEQ)', color='r')
ax3.tick_params(axis='y', labelcolor='r')

ax4 = ax3.twinx()  # instantiate a second y-axis that shares the same x-axis
line4, = ax4.plot(session_labels, sr, marker='o', color='m', label='SR')
ax4.set_ylabel('Silence Ratio (SR)', color='m')  
ax4.tick_params(axis='y', labelcolor='m')

ax3.set_title('PEQ and SR Comparison')
ax3.set_xticklabels(session_labels, rotation=45, ha="right")  # Rotate session labels for readability
lines = [line3, line4]
ax3.legend(lines, [l.get_label() for l in lines])

fig.tight_layout()  # Adjust layout to prevent overlap
plt.show()  # Show the plot
