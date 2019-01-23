# def phi(n):
#     result = n
#     p = 2
#     while(p * p <= n):
#         if (n % p == 0):
#             result -= result/p
#             while (n % p == 0):
#                 n = n / p
#         p = p + 1
#     if (n > 1):
#         result -= result / n
#     return result

n = 1000000
p = []
phi = []
for i in range(0, n*2):
    phi.append(i)
    p.append(True)

p[0] = False
p[1] = False
for i in range(2, n+2):
    if p[i] == True:
        j = 2
        phi[i] = i-1
        while j*j <= n+1:
            p[i*j] = False
            phi[i*j] = phi[i*j]/i*(i-1)
            j += 1

T = input()
for i in range(0, T):
    print phi[input()]
