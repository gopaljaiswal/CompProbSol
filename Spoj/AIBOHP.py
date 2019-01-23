
def lcs(s, s1, n):
    dp = [[0 for i in range(n+1)] for j in range(n+1)]
    for i in range(0, n+1):
        for j in range(0, n+1):
            if i == 0 or j == 0:
                dp[i][j] = 0
            elif s[i-1] == s1[j-1]:
                dp[i][j] = 1+dp[i-1][j-1]
            else:
                dp[i][j] = max(dp[i][j-1], dp[i-1][j])
    return dp[n][n]


def getRes(s):
    s1 = s[::-1]
    print len(s)-lcs(s, s1, len(s))


def findMinInsertionsDP():



T = input()
for i in range(0, T):
    str = raw_input()
    getRes(str)
    # isPal(str)
