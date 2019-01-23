

def calLPS(s):
    i, j = 1, 0
    lps = [0]*(len(s))
    lps[0] = 0
    while i < len(s):
        if s[i] == s[j]:
            j += 1
            lps[i] = j
            i += 1
        else:
            if j == 0:
                lps[i] = 0
                i += 1
            else:
                j = lps[j-1]
    return lps


def getRes(s):
    lps = calLPS(s)
    print lps


while True:
    s = raw_input()
    if s == '*':
        break
    getRes(s)
