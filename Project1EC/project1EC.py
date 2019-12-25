import math
import os
import random
import re
import sys
import numpy as np
from matplotlib import pyplot as plt
from sorting_algorithms import bubbleSort,insertionSort,selectionSort
def bubbleGraph():
    x = []
    best_bubbleSort_y = []
    avg_bubbleSort_y = []
    worst_bubbleSort_y = []
    
    #Bubble Sort
    n = 0
    while n < 100: 
        #100 random numbers between 1 and 500
        random_numbers = []
        sorted_numbers = []
        reversed_numbers = []

        x.append(n)
        for i in range(1,n+1): #List sizes from 1-100
            random_numbers.append(random.randint(1,500))
            sorted_numbers.append(i)
            reversed_numbers.append(i)

        reversed_numbers.reverse()
        
        best_bubbleSort_y.append(bubbleSort(sorted_numbers))
        avg_bubbleSort_y.append(bubbleSort(random_numbers))
        worst_bubbleSort_y.append(bubbleSort(reversed_numbers))
        n +=1

    fig = plt.figure(0)
    fig.canvas.set_window_title('Best Case: Bubble Sort')
    plt.scatter(x,best_bubbleSort_y)
    plt.show()

    fig = plt.figure(1)
    fig.canvas.set_window_title('Average Case: Bubble Sort')
    plt.scatter(x,avg_bubbleSort_y)
    plt.show()

    fig = plt.figure(2)
    fig.canvas.set_window_title('Worst Case: Bubble Sort')
    plt.scatter(x,worst_bubbleSort_y)
    plt.show()
def insertionGraph():
    #Insertion Sort
    x2 = []
    best_insertionSort_y = []
    avg_insertionSort_y = []
    worst_insertionSort_y = []
    n = 0
    while n < 100: 
        #100 random numbers between 1 and 500
        random_numbers = []
        sorted_numbers = []
        reversed_numbers = []

        x2.append(n)
        for i in range(1,n+1):#List sizes from 1-100
            random_numbers.append(random.randint(1,500))
            sorted_numbers.append(i)
            reversed_numbers.append(i)

        reversed_numbers.reverse()
        best_insertionSort_y.append(insertionSort(sorted_numbers))
        avg_insertionSort_y.append(insertionSort(random_numbers))
        worst_insertionSort_y.append(insertionSort(reversed_numbers))
        n +=1

    fig = plt.figure(0)
    fig.canvas.set_window_title('Best Case: Insertion Sort')
    plt.scatter(x2,best_insertionSort_y)
    plt.show()

    fig = plt.figure(1)
    fig.canvas.set_window_title('Average Case: Insertion Sort')
    plt.scatter(x2,avg_insertionSort_y)
    plt.show()

    fig = plt.figure(2)
    fig.canvas.set_window_title('Worst Case: Insertion Sort')
    plt.scatter(x2,worst_insertionSort_y)
    plt.show()
def selectionGraph():
    #Selection Sort
    x3 = []
    best_selectionSort_y = []
    avg_selectionSort_y = []
    worst_selectionSort_y = []

    n = 0
    while n < 100: 
        #100 random numbers between 1 and 500
        random_numbers = []
        sorted_numbers = []
        reversed_numbers = []

        x3.append(n)
        for i in range(1,n+1):#List sizes from 1-100
            random_numbers.append(random.randint(1,500))
            sorted_numbers.append(i)
            reversed_numbers.append(i)

        reversed_numbers.reverse()
        best_selectionSort_y.append(selectionSort(sorted_numbers))
        avg_selectionSort_y.append(selectionSort(random_numbers))
        worst_selectionSort_y.append(selectionSort(reversed_numbers))
        n +=1

    fig = plt.figure(0)
    fig.canvas.set_window_title('Best Case: Selection Sort')
    plt.scatter(x3,best_selectionSort_y)
    plt.show()

    fig = plt.figure(1)
    fig.canvas.set_window_title('Average Case: Selection Sort')
    plt.scatter(x3,avg_selectionSort_y)
    plt.show()

    fig = plt.figure(2)
    fig.canvas.set_window_title('Worst Case: Selection Sort')
    plt.scatter(x3,worst_selectionSort_y)
    plt.show()
def main():
    print("Bubble Sort Scatterplot (1)")
    print("Insertion Sort Scatterplot (2)")
    print("Selection Sort Scatterplot (3)")
    print("Quit (q)")
    user_input = input("Select Mode: ")
    if(user_input == '1'):
        print("Plotting Bubble Sort Graph...")
        bubbleGraph()
    elif user_input == '2':
        print("Plotting Insertion Sort Graph...")
        insertionGraph()
    elif user_input == '3':
        print("Plotting Selection Sort Graph...")
        selectionGraph()
    elif user_input == 'q':
        exit(1)
    else:
        print("Enter valid input!")
    while(user_input != 'q'):
        print("Bubble Sort Scatterplot (1)")
        print("Insertion Sort Scatterplot (2)")
        print("Selection Sort Scatterplot (3)")
        print("Quit (q)")
        user_input = input("Select Mode: ")
        if(user_input == '1'):
            print("Plotting Bubble Sort Graph...")
            bubbleGraph()
        elif user_input == '2':
            print("Plotting Insertion Sort Graph...")
            insertionGraph()
        elif user_input == '3':
            print("Plotting Selection Sort Graph...")
            selectionGraph()
        elif user_input == 'q':
            exit(1)
        else:
            print("Enter valid input!")

main()