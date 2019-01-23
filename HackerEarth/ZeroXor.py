import itertools

a = [1, 2, 3, 1]

import itertools


def findsubsets(S, m):
    return set(itertools.combinations(S, m))


for i in range(2, len(a)+1):
    print findsubsets(a, i)

# def getRes(A):
#     counter = 0
#     for i in range(0, len(A)-1):
#         a = A[i]
#         print A[i], '->>'
#         if i > 0:
#             for j in range(0, i):
#                 a = a ^ A[j]
#                 if a == 0:
#                     counter += 1
#                     print A[i], A[j]

#         if (i+1) != len(A)-1:
#             for j in range(i+1, len(A)):
#                 a = a ^ A[j]
#                 if a == 0:
#                     counter += 1
#                     print A[i], A[j]

#     print counter


# N = input()
# A = map(int, raw_input().split())
# getRes(A)


# n = input()
# A = map(int, raw_input().split())
# count = 0
# for ii in range(1, 1<<n):
#     m = bin(ii)[2:]
#     m = '0'*(n-len(m)) + m
#     ans = 0
#     for bit_id in range(n):
#         if(m[bit_id] == '1'):
#             ans ^= A[bit_id]
#     if not ans: count+=1
# print count
