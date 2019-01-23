import math


def getRes(af3, al3, sum):
    n = 2*sum/(af3+al3)
    d = (af3-al3)/(2-n+3)
    a = af3-2*d
    # d = (al3-af3) / 5.
    # d = math.ceil(d)
    # a = af3-(2*d)
    # al = al3+(2*d)
    # n = int(math.floor((2*sum)/(a+al)))

    # print d, a, al, n
    print na
    for i in range(0, n):
        print int(a+(i*d)),


T = input()
for i in range(0, T):
    af3, al3, sum = map(int, raw_input().split())
    getRes(af3, al3, sum)
    print
