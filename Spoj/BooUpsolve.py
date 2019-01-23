A = []


def isPosible(M, t):
    flag = True
    days = 1
    time = t
    for i in range(0, len(A)):
        time = time-A[i]
        if time < 0:
            time = t
            time = time-A[i]
            days += 1
        if time < 0:
            flag = False
            break

        if days > M:
            flag = False
            break
        #print str(time) + "   "+str(days)
    return flag


def getRes(M):
    res = -1
    low, high = 0, 10 ** 13

    #print isPosible(M, 6000000212451)
    while(low <= high):
        mid = (low+high) >> 1
        if isPosible(M, mid) == True:
            # print str(True) + "  "+str(mid)
            res = mid
            high = mid-1
        else:
            # print str(False) + "  "+str(mid)
            low = mid+1
    print res


N, M = map(int, raw_input().split())
A = map(int, raw_input().split())
getRes(M)
