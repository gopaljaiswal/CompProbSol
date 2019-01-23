import math

def getDivisors(list, n):
    i = 1
    while i <= math.sqrt(n):
        if (n % i == 0):
            if (n / i == i and (n/i) not in list):
                list.append(i)
            else:
                if i not in list:
                    list.append(i)
                if (n/i) not in list:
                    list.append(n/i)
        i = i + 1
    return list


def getRes(N, turn):
    map = {"0": "Airborne wins.", "1": "Pagfloyd wins."}
    # counter = 0
    # list = []
    # j = N
    # prevSize = 0
    # while(j > 0):
    #     list = getDivisors(list, j)
    #     if prevSize == len(list):
    #         break
    #     #print j, list
    #     j -= 1
    #     prevSize = len(list)
    #     counter += 1
        #print counter


    print map[str(turn)]


T = input()
for i in range(0, T):
    N, turn = map(int, raw_input().split())
    getRes(N, turn)
