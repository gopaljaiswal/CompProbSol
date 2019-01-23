

def editDistDP(s1, s2, m, n):
    dp = [[0 for i in range(n+1)] for j in range(m+1)]
    for i in range(0, m+1):
        for j in range(0, n+1):
            if i == 0:
                dp[i][j] = j
            elif j == 0:
                dp[i][j] = i
            elif s1[i-1] == s2[j-1]:
                dp[i][j] = dp[i-1][j-1]
            else:
                dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1])
    print dp[m][n]


T = input()
for i in range(0, T):
    s1 = raw_input()
    s2 = raw_input()
    editDistDP(s1, s2, len(s1), len(s2))
