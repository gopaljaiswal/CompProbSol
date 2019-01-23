

def getRes(arr, N, M):
    res, sum = 0, arr[0]

    i, j = 0, 0
    while(j < N):
        if sum == M:
            res = sum
            break

        if sum < M and res < sum:
            res = sum
        elif sum < M:
            j += 1
            if j < N:
                sum += arr[j]
        elif sum > M:
            sum -= arr[i]
            i += 1

        if j < i:
            j += 1

    print res


N, M = map(int, raw_input().split())
arr = map(int, raw_input().split())
getRes(arr, N, M)
