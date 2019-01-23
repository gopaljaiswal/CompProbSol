

def getRes(N, K, inpList):
    if K == 1:
        return 0

    if K > N:
        return 1000000005

    inpList.sort()
    windDiff = 1000000005
    for k in range(0, N-K+1):
        
        maxPosDiff = 0
        diff = inpList[K+k-1]-inpList[k]
        
        if diff > maxPosDiff:
            maxPosDiff = diff

        windDiff = min(windDiff, maxPosDiff)
    return windDiff


T = input()
for i in range(0, T):
    N, K = map(int, raw_input().split())
    inpList = map(int, raw_input().split())
    print getRes(N, K, inpList)
