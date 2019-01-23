A = [
    [1, 1, 3, 3, 3, 3, 3]
]
N = len(A)*len(A[0])
from bisect import bisect_right


def getCount(A, e):
    cnts = 0
    for elem in A:
        low = 0
        high = len(elem)
        while low < high:
            mid = (low+high)/2
            if elem[mid] <= e:
                low = mid+1
            else:
                high = mid
        cnts += low
    return cnts


def findMedian(A):
    c = (len(A) * len(A[0]))/2 + 1
    low = 0
    high = 10**9
    while low < high:
        mid = (low+high)/2
        cs = getCount(A, mid)
        if cs < c:
            low = mid+1
        else:
            high = mid
    return low


print findMedian(A)
