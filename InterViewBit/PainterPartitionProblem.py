A = 1
B = 1000000
C = [1000000, 1000000]


def isPossble(A, k, ans):
    res = ans
    i = 0
    flag = True
    while(i < len(A)):
        if res-A[i] >= 0:
            res = res-A[i]
            # print ">", res
        else:
            k -= 1
            res = ans
            i = i-1
            # print "<", res
        if k == 0:
            flag = False
            break
        i += 1
    # if k == 1:
    #     flag = True
    return flag


def getRes(A, B, C):
    low, high = 0, 10**9
    res = -1
    # print isPossble(C, A, 6)
    while(low <= high):
        mid = (low+high) >> 1
        # print mid
        if isPossble(C, A, mid) == True:
            res = mid
            high = mid-1
        else:
            low = mid+1
    return ((res % 10000003)*B) % 10000003


print getRes(A, B, C)
