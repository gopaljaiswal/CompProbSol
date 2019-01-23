opSet = set(['+', '-', '*', '/'])


def getRes(s):
    arr = s.split()
    total = int(arr[0])
    i = 1
    while i < len(arr):
        op = arr[i]
        if op == '=':
            return total

        if op == '+':
            total += int(arr[i+1])
        elif op == '-':
            total -= int(arr[i+1])
        elif op == '*':
            total *= int(arr[i+1])
        elif op == '/':
            total /= int(arr[i+1])

        i += 2


T = input()
for i in range(0, T):
    raw_input()
    s = raw_input()
    print getRes(s)
