from random import randint

T = 1000
print T
for ii in range(T):
    N, M = [randint(2, 20) for x in range(2)]
    K = randint(2, 10**18)
    print N, M, K
