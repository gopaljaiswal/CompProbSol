
#include <iostream>
#include <vector>
using namespace std;

int getDist(int x1, int y1, int x2, int y2)
{
    int xCnt = 0;
    int yCnt = 0;

    if (x1 <= x2)
    {
        xCnt = x2 - x1;
    }
    else
    {
        xCnt = x1 - x2;
    }

    if (y1 <= y2)
    {
        yCnt = y2 - y1;
    }
    else
    {
        yCnt = y1 - y2;
    }
    return max(xCnt, yCnt);
}

int coverPoints(vector<int> &A, vector<int> &B)
{
    int x = A[0], y = B[0], tot = 0;

    for (int i = 1; i < A.size(); i++)
    {
        int x1 = A[i], y1 = B[i];
        cout << getDist(x, y, x1, y1) << endl;
        tot += getDist(x, y, x1, y1);
        x = x1, y = y1;
    }
    return tot;
}

int main()
{
    vector<int> A = {0, 1, 2};
    vector<int> B = {0, 1, 3};

    cout << coverPoints(A, B) << endl;
}
