A = []
B = []


def getRes(A, B):
    countNG, countMG = 0, 0
    P = len(A) if len(A) < len(B) else len(B)
    diff = A[0]-B[0]
    # print diff
    if diff > 0:
        countNG += 1
    elif diff < 0:
        countMG += 1
    print "Godzilla" if countNG >= countMG else "MechaGodzilla"


T = input()
for i in range(0, T):
    raw_input()
    N, M = map(int, raw_input().split())
    A = map(int, raw_input().split())
    B = map(int, raw_input().split())
    A.sort(reverse=True)
    B.sort(reverse=True)
    getRes(A, B)
