# for __ in range(input()):
#     if __ > 0: raw_input()
#     n = input()
#     A = map(int, raw_input().split())

#     psum = [0] * 5005
#     for ii in range(0, len(A), 2):
#         psum[A[ii]]+=1
#         psum[A[ii+1] + 1]-=1
#     for ii in range(1, len(psum)):
#         psum[ii]+=psum[ii-1]

#     q = input()
#     print 'Case #{}:'.format(__+1), 
#     # res = [psum[input()] for queries in range(q)]

#     for ii in range(q):
#         x = input()
#         print psum[x],
    
#     # print 'Case #{}: {}'.format(__+1, ' '.join(res))
#     print 
        

global str
leftList = []
rightList = []


def getRes(i, q, result, leftList, rightList, N):
    count = 0
    for i in range(0, N):
        if leftList[i] <= q and rightList[i] >= q:
            print leftList[i], rightList[i]
            count += 1
    result += " "+str(count)
    return result


T = input()
for i in range(0, T):
    if i > 0:
        raw_input()
    N = input()
    list = map(int, raw_input().split())
    leftList = list[0::2]
    rightList = list[1::2]
    print leftList
    print rightList
    Q = input()
    result = "Case #"+str(i+1)+":"
    for j in range(0, Q):
        q = int(raw_input())
        result = getRes(i, q, result, leftList, rightList, N)
    print result