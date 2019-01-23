

def getMaxDigit(N, maxDigit):
    if N == 0:
        return maxDigit
    rem = N % 10
    if rem > maxDigit and rem != 0:
        maxDigit = rem
    return getMaxDigit(N/10, maxDigit)


def getRes(N):
    # firstDiff = -1
    # count = 0
    #maxDigit = -1
    # while True:
    #     if count == 0:
    #         firstDiff = getMaxDigit(N, maxDigit)

    #     N = N-getMaxDigit(N, maxDigit)
    #     count += 1
    #     # print N
    #     if N == 0:
    #         break

    #firstDiff = getMaxDigit(N, maxDigit)
    pass

N = input()
if (N % 10) == 0: print 2
else: print '1\n{}'.format(N%10)

# getRes(N)
# print getMaxDigit(N, maxDigit)

