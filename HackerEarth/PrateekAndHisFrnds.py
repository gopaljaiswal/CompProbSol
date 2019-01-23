
def getRes(list, X):
    i = 0
    j = 0
    tempSum = list[0]
    while j < len(list):
        if tempSum == X:
            break
        elif tempSum > X:
            tempSum -= list[i]
            i += 1
        elif tempSum < X:
            j += 1
            if j < len(list):
                tempSum = tempSum+list[j]
        if i > j:
            j += 1

    return "YES" if j < len(list) else "NO"


T = input()
for i in range(0, T):
    list = []
    N, X = map(int, raw_input().split())
    for j in range(0, N):
        list.append(input())
    print getRes(list, X)
