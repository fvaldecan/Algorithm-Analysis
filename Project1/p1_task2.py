def euclid(m,n):
    #Calculates GCD using Euclid's algorithm
    if(n == 0):
        return m
    return euclid(n, m % n)
def task2():
    k = int(input("Enter number k = "))
    i = 0 
    fib = []
    first = 0
    second = 1
    #Generates Fibonacci numbers from 1 to k
    while(i < k+2):
        if(i <= 1):
            next = i
        else:
            next = first + second
            first = second
            second = next
        fib.append(next)
        i += 1
    gcd = euclid(fib[k+1],fib[k])
    print("GCD(", fib[k+1],", ",fib[k], ") = ", gcd)
    print("")
