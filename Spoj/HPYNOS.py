list = []


def getDigitSquareSum(N):
    sum = 0
    while(N != 0):
        rem = N % 10
        sum = sum + rem**2
        N = N/10
    return sum


def getRes(N):
    counter = 0
    while(True):
        N = getDigitSquareSum(N)
        counter += 1
        if N == 1:
            return counter
        if N in list:
            break
        else:
            list.append(N)

    return -1


N = input()
print getRes(N)
