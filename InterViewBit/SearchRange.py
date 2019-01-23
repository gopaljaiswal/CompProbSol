from bisect import bisect_right
from bisect import bisect_left


def searchRange(A, B):
    low, high = 0, len(A)
    left, right = -1, -1
    while(low < high):
        mid = (low+high) >> 1
        if A[mid] < B:
            low = mid+1
        elif A[mid] >= B:
            high = mid
            right = high
        # print high

    low, high = 0, len(A)
    while(low < high):
        mid = (low+high) >> 1
        if A[mid] <= B:
            low = mid+1
            left = low
        elif A[mid] > B:
            high = mid

    # return [left, right]
    return [right, low-1]


def getBs(A, k):
    low, high = 0, len(A)
    while low < high:
        mid = (low+high) >> 1
        if A[mid] == k:
            print mid
            break
        elif A[mid] < k:
            low = mid+1
        else:
            high = mid
    # print mid


A = [4, 7, 7, 7, 8, 10, 10]
B = 7
# print bisect_left(A, 7)
# print bisect_right(A, 7)
# print searchRange(A, B)
getBs(A, 7)
