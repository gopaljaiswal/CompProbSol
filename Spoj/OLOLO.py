# 1. Find once ocuured element in twice occured elements

# from sys import stdin, stdout
# N = int(stdin.readline())
# res = input()
# for i in range(1, N):
#     res = res ^ int(stdin.readline())
#     print res
# stdout.write(str(res))


# 2. Find once ocuured element in thrice occured elements
NO_BITS = 5
list = [5, 5, 5, 2, 8, 8, 8, 2, 2, 10]
ans = 0

for i in range(0, 32):
    sum=0
    for j in range(0, len(list)):
        # print list[j], 1<<i, (list[j] & (1 << i))
        if (list[j] & (1 << i)) > 0: # ?? 
            sum += 1
        # sum += 1 if (list[j] & (1 << i)) > 0 else 0
    # print sum
    ans|=((sum%3)*(1<<i)) ## ?? 
print ans