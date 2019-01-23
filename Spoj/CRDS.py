
def getRes(n):
    sum = (n*2) % 1000007
    sum = sum + (3 * ((n-1)*n/2) % 1000007) % 1000007
    print sum % 1000007


N = input()
for i in range(0, N):
    getRes(input())
