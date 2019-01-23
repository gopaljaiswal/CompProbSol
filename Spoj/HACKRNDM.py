
def bst(A, k):
    low, high = 0, len(A)-1
    flag = False
    while low <= high:
        mid = (low+high) >> 1
        #print mid
        if A[mid] == k:
            flag = True
            break
        elif A[mid] < k:
            low = mid+1
        elif A[mid] > k:
            high = mid-1
    return flag


def getRes(A, K):
    print bst(A, 0)
    # count = 0
    # for i in range(0, len(A)):
    #     count += 1 if bst(A, A[i]+K) == True else 0
    # print count


N, K = map(int, raw_input().split())
A = map(int, raw_input().split())
A.sort()
getRes(A, K)
