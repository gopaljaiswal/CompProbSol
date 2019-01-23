
def getRes(result, firstEle, leftList, rightList, N, dict):
    src = firstEle
    result += " "+leftList[src]+"-"+rightList[src]
    while True:
        if rightList[src] not in dict:
            break
        else:
            src = dict[rightList[src]]
        result += " "+leftList[src]+"-"+rightList[src]
        # print leftList[src], rightList[src]
    return result
    


T = input()
for i in range(0, T):
    result = ""
    leftList = []
    rightList = []
    dict = {}
    result += 'Case  #%d' % (i+1) + ":"
    N = input()
    for j in range(0, 2*N):
        if j % 2 == 0:
            str = raw_input()
            leftList.append(str)
            dict[str] = j/2
        else:
            rightList.append(raw_input())

    firstEleInd = 0
    for j in range(0, N):
        if leftList[j] not in rightList:
            firstEle = j
            break

    print getRes(result, firstEle, leftList, rightList, N, dict)
