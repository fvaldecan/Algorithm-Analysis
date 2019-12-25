
def euclid_count(m,n,count):
    #Counts number of modulo divisions using Euclid's algoirthm
    if(n == 0):
        return count
    count += 1
    return euclid_count(n, m % n,count)

def intCheck(m,n,t,count):
    #Counts number of divisions using Consecutive integer checking 
    r = m % t
    count += 1
    if r == 0:
        r2 = n % t
        count += 1
        if r2 == 0:
            return count
    return intCheck(m, n -1,t -1,count)

def task1():
    sumMD = 0
    sumD = 0
    n = int(input("Enter number n = "))
    for i in range(1,n+1):# X-axis
        count = 0
        md = euclid_count(n,i,count)
        sumMD += md
    for i in range(1,n+1):
        count = 0
        t = min(n,i)
        d = intCheck(n,i,t,count)
        sumD += d
    avgMD = round((sumMD/n),2)
    avgD = round((sumD/n),2)
    print("MD avg: ", avgMD)    
    print("D avg: ", avgD)
    print("")
