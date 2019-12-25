def sieve_of_eratosthenes(n):
    #Generates prime numbers between 2 and n
    factors = []
    for i in range (2, n+1):
        if(len(factors)== 0):
            factors.append(i)
        else:
            if checkPrime(factors, i) == True:
                continue
            else:
                factors.append(i)
    return factors

def checkPrime(factors,i):
    #Checks if the numbers are prime
    check = False
    for j in range(len(factors)):
        if (i % factors[j] == 0):
            check = True 
            return check
    return check


def middleschool_procedure(n):
    #Generates common factors using middle school procedure 
    prime_factors = sieve_of_eratosthenes(n)
    factors = []
    i = 0
    while 1 < n:
        if n % prime_factors[i] == 0:
            factors.append(prime_factors[i])
            n /= prime_factors[i]
        else:
            i += 1
    return factors
    
def cf_count(a,b,count):
    #Count the number of comparisons for two lists of prime common factors
    count = 0
    common_factors = []
    for i in range(len(a)):
        for j in range(len(b)):
            count += 1 
            if(a[i] == b[j]):
                common_factors.append(a[i])
                b.remove(b[j])
                break
    return count
    
def common_factors(a, b):
    #Returns list of common factors
    common_factors = []
    for i in range(len(a)):
        for j in range(len(b)):
            if(a[i] == b[j]):
                common_factors.append(a[i])
                b.remove(b[j])
                break
    return common_factors


def task3():
    m = int(input("Enter value for m: "))
    n = int(input("Enter value for n: "))
    list1 = middleschool_procedure(m) 
    list2 = middleschool_procedure(n)
    cf =[]
    cf = common_factors(list1,list2)
    gcd = 1
    for i in range(len(cf)):
        gcd *= cf[i] 
    print("GCD = ", gcd)
    print("")
