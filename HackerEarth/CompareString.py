# def compareStr(A, B):
#     i = 0
#     flag = True
#     while(i < len(A)):
#         if B[i] < A[i]:
#             flag = False
#             break
#         i += 1
#     return flag


zIdxA = []
zIdxB = []
N, Q = map(int, raw_input().split())
A = list(raw_input())
B = list(raw_input())

for i in range(0, N):
    if A[i] == '0':
        zIdxA.append(i)
    if B[i] == '0':
        zIdxB.append(i)

for k in range(0, Q):
    i, j = 0, 0
    x = int(raw_input())
    x -= 1
    # B = B[0:x]+"1"+B[x+1:len(B)]
    B[x] = '1'
    while (j < len(zIdxB)) and (B[zIdxB[j]] == '1'):
        j += 1
    if (i == len(zIdxA)) and (j == len(zIdxB)):
        res = True
    elif(i == len(zIdxA) and j < len(zIdxB)):
        res = False
    elif(i < len(zIdxA) and j == len(zIdxB)):
        res = True
    elif(zIdxA[i] < zIdxB[j]):
        res = True
    else:
        res = False
    print "YES" if res == True else "NO"
