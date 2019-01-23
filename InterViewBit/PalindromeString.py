
import re


def isPalindrome(s):
    s = re.sub(r"[-()\"#/@;:<>{}`+=~|.!?,' ']", "", s)
    s1 = s.lower()
    strLen = len(s1)
    i = 0
    flag = True
    while i < strLen:
        if s1[i] != s1[strLen-i-1]:
            flag = False
            break
        i += 1
    return flag


s = "race a car"
print isPalindrome(s)
