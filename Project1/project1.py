import math
import os
import random
import re
import sys
import numpy as np
from matplotlib import pyplot as plt
from p1_task1 import task1,euclid_count,intCheck
from p1_task2 import task2, euclid
from p1_task3 import task3,common_factors,sieve_of_eratosthenes, cf_count,middleschool_procedure

def scatterplot():
    #Task 1 Graph
    task1MD_x = []
    task1MD_y = []
    task1D_x = []
    task1D_y = []
    num = 500
    for i in range(1,num+1):
        sumMD = 0
        sumD = 0
        n = random.randint(1,1000)
        task1MD_x.append(n) #500 random numbers
        task1D_x.append(i)  #Numbers 1-500

        #Calculates the sum of number of modulo divisions
        for j in range(1,n+1):
            count = 0
            md = euclid_count(n,j,count)
            sumMD += md
        #Calculates the sum of number of divisions
        for k in range(1,i+1):
            count = 0
            t = min(k,i)
            d = intCheck(k,i,t,count)
            sumD += d
        avgMD = round((sumMD/n),2)
        avgD = round((sumD/i),2)
        task1MD_y.append(avgMD)
        task1D_y.append(avgD)

    fig = plt.figure(0)
    fig.canvas.set_window_title('Task 1: MDavg(n)')
    plt.scatter(task1MD_x,task1MD_y)
    plt.show()

    fig = plt.figure(1)
    fig.canvas.set_window_title('Task 1: Davg(n)')
    plt.scatter(task1D_x,task1D_y)
    plt.show()

    #Task2 Graph
    i = 0 
    fib = []
    first = 0
    second = 1
    
    #Generates Fibonacci numbers from 1 to 500
    while(i < num+2):
        if(i <= 1):
            next = i
        else:
            next = first + second
            first = second
            second = next
        fib.append(next)
        i += 1
        fib_x = []
        fib_y = []

    #Calculates number of modulo divisions
    for k in range(len(fib)): 
        if(k+1 == len(fib)):
            break
        worst = euclid_count(fib[k+1],fib[k],count)
        fib_x.append(k+1)
        fib_y.append(worst)
    fig = plt.figure(2)
    fig.canvas.set_window_title('Fibonacci')
    plt.scatter(fib_x,fib_y)
    plt.show()
    
    #Task 3 Graph
    task3_x = []    
    task3_y = []
    i = 1
    while i <= num:
        m = random.randint(1,500)
        n = random.randint(1,500)

        #Generates common factors for m and n
        list1 = middleschool_procedure(m)
        list2 = middleschool_procedure(n)

        #x = larger size of the two lists
        #y = number of comparisons for finding common prime factors
        x = max(len(list1),len(list2))
        y = cf_count(list1,list2,count)
        task3_x.append(x)
        task3_y.append(y)
        i +=1

    fig = plt.figure(3)
    fig.canvas.set_window_title('Middle School Procedure')
    plt.scatter(task3_x,task3_y)
    plt.show()

def main():
    print("User Testing Mode (1)")
    print("Scatter Plot Mode (2)")
    print("Quit (q)")
    user_input = input("Enter Mode: ")
    if(user_input == '1'):
        while(user_input != 'q'):
            print("Task 1 (1)")
            print("Task 2 (2)")
            print("Task 3 (3)")
            print("Back (b)")
            print("Quit (q)")
            print("")
            user_input = input("Enter Task: ")
            if user_input == '1':
                task1()
            elif user_input == '2':
                task2()
            elif user_input == '3':
                task3()
            elif user_input == 'b':
                break
            elif user_input == 'q':
                exit(1)
            else:
                print("Enter valid input!")
                print("")

    elif user_input == '2':
        print("Scatter Plot Mode...")
        scatterplot()
    elif user_input == 'q':
        exit(1)
    else:
        print("Enter valid input!")
    while(user_input != 'q'):
        print("User Testing Mode (1)")
        print("Scatter Plot Mode (2)")
        print("Quit (q)")
        print("")

        user_input = input("Enter Mode: ")
        if user_input == '1':
            while(user_input != 'q'):
                print("Task 1 (1)")
                print("Task 2 (2)")
                print("Task 3 (3)")
                print("Back (b)")
                print("Quit (q)")
                print("")
                user_input = input("Enter Task: ")
                if user_input == '1':
                    task1()
                elif user_input == '2':
                    task2()
                elif user_input == '3':
                    task3()
                elif user_input == 'b':
                    break
                elif user_input == 'q':
                    exit(1)
                else:
                    print("Enter valid input!")
        elif user_input == '2':
            print("Scatter Plot Mode...")
            scatterplot()
        elif user_input == 'q':
            exit(1)
        else:
            print("Enter valid input!")
            print("")    
main()
