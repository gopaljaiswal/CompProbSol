

def getRes(L):
    print "%.2f" % ((L**2)/(2*3.145))


while True:
    L = input()
    if L == 0:
        break
    else:
        getRes(L)
