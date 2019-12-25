def bubbleSort(A):
    #Calculates number of comparisons using Bubble Sort
    count = 0
    for i in range(len(A)):
        for j in range(1,len(A)-i):
            count +=1
            if (A[j-1] > A[j]):
                swap(A,j-1,j)
    return count

def insertionSort(A):
    #Calculates number of comparisons using Insertion Sort
    count = 0
    for i in range(1,len(A)):
        for j in range(i-1,0,-1):
            count +=1
            if (A[j] > A[j+1]):
                swap(A,j,j+1)
            else:
                count +=1
                break
    return count

def selectionSort(A):
    #Calculates number of comparisons using Selection Sort
    count = 0
    for i in range(len(A)):
        bigIndex = 0
        for j in range(1,len(A)-i):
            count +=1
            if (A[j] > A[bigIndex]):
                bigIndex = j
        swap(A,bigIndex,len(A)-i-1)
    return count

                
def swap(A, a, b): 
    A[a], A[b] = A[b], A[a] 
    return A


