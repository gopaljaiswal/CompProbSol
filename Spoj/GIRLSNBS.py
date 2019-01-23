import math


def getRes(N, M):
    if N == 0:
        return M
    elif M == 0:
        return N
    elif N == M:
        return 1
    elif N > M:
        return int(math.ceil(N/float(M+1)))
    else:
        return int(math.ceil(M/float(N+1)))


while True:
    N, M = map(int, raw_input().split())
    if N == -1 and M == -1:
        break
    else:
        print getRes(N, M)
