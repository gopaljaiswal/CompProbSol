T = input()
for i in range(0, T):
    tot, no = map(int, raw_input().split())
    A = map(int, raw_input().split())

    A.sort(reverse=True)

    j = 0
    sum = 0
    count = 0
    flag = False
    while(j < len(A)):
        sum += A[j]
        count += 1
        if(sum >= tot):
            flag = True


            
            print "Scenario #" + str(i+1) + ":"
            print count
            print
            break
        j += 1

    if flag == False:
        print "Scenario #" + str(i+1)+":"
        print "impossible"
        print 
