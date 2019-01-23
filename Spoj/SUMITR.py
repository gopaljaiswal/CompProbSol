T = input()
for i in range(T):
    n=input()
    f=[0]*n
    t=f[:]
    for j in range(n):
        a=map(int, raw_input().split())
        for k in range(len(a)):
            f[k]=a[k]+max(t[k-1], t[k])
        t=f[:]
    print max(f)
