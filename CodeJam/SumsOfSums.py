

T = input()
for i in range(0, T):
    N, Q = map(int, raw_input().split())
    A = map(int, raw_input().split())
    list = []
    for j in range(len(A)):
        for k in range(j+1, len(A)+1):
            sub = sum(A[j:k])
            if sub > 0:
                list.append(sub)
    list.sort()
    print "Case #%s" % (i+1)+":"
    for q in range(0, Q):
        L, R = map(int, raw_input().split())
        print sum(list[L-1:R])
