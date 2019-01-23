A = []


def int2bin(l, r):
    count1 = 0
    for j in range(l, r+1):
        i = A[j]
        if i == 0:
            return "0"
        while i:
            if i & 1 == 1:
                count1 += 1
            i /= 2
        # print str(j)+"  " + str(i)+"  "+str(count1)
    return count1


def getRes(x):
    res = -1
    low, high = 0, len(A)-1
    sum = 0
    while(low <= high):
        sum += int2bin(0, low)
        if sum == x:
            break
        else:
            res = low+1
        # print str(low)+"    "+str(high)+" "+str(res)
        low += 1
    print res


N, Q = map(int, raw_input().split())
A = map(int, raw_input().split())
for i in range(1, Q+1):
    getRes(input())
