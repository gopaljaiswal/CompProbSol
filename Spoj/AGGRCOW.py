A = []


def isPosible(M, t):
    count = 1
    i = 0
    for j in range(1, len(A)):
        diff = A[j]-A[i]
        if diff >= t:
            count += 1
            i = j
            # if diff == t:
            #     diffVar = diff

    return count


def getRes(M):
    res = 1
    low, high = 1, 10**9

    # count, diffVar = map(int, isPosible(M, 3).split())
    # print str(count)+" "+str(diffVar)
    # print str(isPosible(M, 3))+"  "+str(diffVar)

    while(low <= high):
        mid = (low+high) >> 1
        # count, diffVar = map(int, isPosible(M, mid).split())
        count = isPosible(M, mid)
        # print 'low={}, high={}, mid={}, count={}'.format(low, high, mid, count)
        if count >= M:
            res = mid
            # print str(low)+"  "+str(mid)+" "+str(high) +"  "+str(diffVar)
            low = mid+1
        else:
            high = mid-1

    print res


T = input()
for __ in range(T):
    A = []
    N, M = map(int, raw_input().split())

    for i in range(0, N):
        A.append(input())
    A.sort()
    getRes(M)
