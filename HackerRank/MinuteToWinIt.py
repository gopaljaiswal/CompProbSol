#!/bin/python


def minuteToWinIt(a, k):
    res1 = 0
    res2 = 0
    for i in range(1, len(a)):
        if a[i]-a[i-1]!=k:
            a[i]=a[i-1]+k
            res1+=1
        
    print res1    


N, K = map(int, raw_input().split())
A = map(int, raw_input().split())
print minuteToWinIt(A, K)
