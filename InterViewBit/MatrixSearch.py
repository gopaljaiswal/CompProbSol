
def getColRow(N, rowSize, colSize):
    if N == 0:
        return str(N)+' '+str(N)

    row = (N/colSize)
    if(N % colSize == 0):
        row = row - 1
        col = colSize-1
    else:
        col = (N % colSize)-1
    return str(row)+' '+str(col)


def getRes(A, rowSize, colSize, no):
    rowSize = len(A)
    colSize = len(A[0])
    
    count = 0
    low, high = 0, rowSize*colSize
    while(low <= high):
        mid = (low+high) >> 1
        row, col = map(int, getColRow(mid, rowSize, colSize).split())
        if A[row][col] == no:
            count += 1
            break
        elif A[row][col] < no:
            low = mid+1
        else:
            high = mid-1
    print count



def searchMatrix( A, no):
        rowSize = len(A)
        colSize = len(A[0])
        count = 0
        low, high = 0, rowSize*colSize
        while(low <= high):
            mid = (low+high) >> 1
            if mid == 0:
                row = 0
                col = 0
            row = (mid/colSize)
            if(mid % colSize == 0):
                row = row - 1
                col = colSize-1
            else:
                col = (mid % colSize)-1
                
            #row, col = map(int, getColRow(mid, rowSize, colSize).split())
            if A[row][col] == no:
                count += 1
                break
            elif A[row][col] < no:
                low = mid+1
            else:
                high = mid-1
        return count
        
A = [
    [1,   3,  5,  7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]
]
rowSize = len(A)
colSize = len(A[0])
#getRes(A, rowSize, colSize, 51)
print searchMatrix(A,12)
# row, col = map(int, getColRow(7, rowSize, colSize).split())
# print row, col
