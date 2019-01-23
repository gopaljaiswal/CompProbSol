
def getRes(N):
    sum = 1
    i = 1
    while True:
        if (N-sum) == 0:
            return 'Y'
            break
        elif (N-sum) < 0:
            return 'N'
            break
        else:
            sum += (6*i)
            i += 1
        


while True:
    N = input()
    if N == -1:
        break
    else:
        print getRes(N)
