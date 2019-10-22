"""
Author: Angeliki Loukatou
Date: 22/10/19

This script receives a minimum and a maximum value from the user, along with a value for the mode and picks n
random values from the triangular distribution. It then plots the histogram of the simulated random values.
"""

import numpy as np
import matplotlib.pyplot as plt

def triangular_distr(min,mode,max,no_random_values):
    # draw random values
    random_values = np.random.triangular(min,mode,max,size=no_random_values)
    # plot the histogram
    plt.hist(random_values,density=True,bins=1000)
    plt.xlabel('Random values')
    plt.ylabel('Probabilities')
    plt.title('Histogram of ' + str(no_random_values) + ' random values')
    plt.show()

if __name__ == "__main__":
    # set the number of random values
    no_random_values = 100000

    # request min, mode and max from the user
    min = float(input('Please enter a minimum value between 0-50: '))
    if min > 50 or min < 0:
        min = input('Sorry the value is out of range. Please enter a minimum value between 0-50: ')
    mode = float(input('Please enter a value for the mode between 100-200: '))
    if mode >= 200 or mode < 100:
        mode = input('Sorry the value is out of range. Please enter a mode value between 100-200: ')
    max = float(input('Please enter a maximum value between 400-800: '))
    if max >= 800 or max < 400:
        max = input('Sorry the value is out of range. Please enter a max value between 400-800: ')

    # call the triangular_distr function to simulate and plot the random values
    triangular_distr(min,mode,max,no_random_values)

