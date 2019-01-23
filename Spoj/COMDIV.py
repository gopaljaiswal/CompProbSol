
import math
list1 = []


def SieveOfEratosthenes(n):
    prime = [True for i in range(n+1)]
    p = 2
    while (p * p <= n):
        if (prime[p] == True):

            for i in range(p * 2, n+1, p):
                prime[i] = False
        p += 1
    for p in range(2, n):
        if prime[p]:
            list1.append(p)


# def GCD(a, b):
#     if b == 0:
#         return a
#     return GCD(b, a % b)
def gcd(a, b):

    if (a == b):
        return a

    # GCD(0, b) == b; GCD(a, 0) == a,
    # GCD(0, 0) == 0
    if (a == 0):
        return b

    if (b == 0):
        return a

    # look for factors of 2
    # a is even
    if ((~a & 1) == 1):

        # b is odd
        if ((b & 1) == 1):
            return gcd(a >> 1, b)
        else:
            # both a and b are even
            return (gcd(a >> 1, b >> 1) << 1)

    # a is odd, b is even
    if ((~b & 1) == 1):
        return gcd(a, b >> 1)

    # reduce larger number
    if (a > b):
        return gcd((a - b) >> 1, b)

    return gcd((b - a) >> 1, a)


def countCommDiv(a, b):
    n = gcd(a, b)
    result = 0
    i = 1
    while list1[i] <= math.sqrt(n):
        if n % list1[i] == 0:
            if n/list1[i] == list1[i]:
                result += 1
            else:
                result += 2
        i += 1
    return result


N = 1000
SieveOfEratosthenes(N)
T = input()
for i in range(T):
    a, b = map(int, raw_input().split())
    print countCommDiv(a, b)
