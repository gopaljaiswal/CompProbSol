list=[]

N = input()
for i in range(1,N):
    a,b=map(int,raw_input().split())
    list.append(a)
print len(set(list))