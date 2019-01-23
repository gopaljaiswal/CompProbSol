def intersection(lst1, lst2):
    lst3 = [value for value in lst1 if value in lst2]
    return lst3


def getRes(arr, N, D):
    if len(arr) == N:
        for i in arr:
            print i,
        return

    tem = arr[:]
    arr.sort()

    while(len(arr) > N):
        if arr[0] + arr[len(arr)-1] > D:
            arr.pop()
        else:
            arr.pop(0)

    for i in intersection(tem, arr):
        print i,


inpList = map(int, raw_input().split())
N, M, D = inpList[0], inpList[1], inpList[2]
arr = map(int, raw_input().split())
getRes(arr, N, D)
