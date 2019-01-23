#include <iostream>
#include <vector>
using namespace std;

vector<int> maxset(vector<int> &A)
{
    long sum = 0, finalSum = 0;
    vector<int> newVect, finalVect;
    int minIdx = 0;

    int i = 0, j = 0;
    while (j < A.size())
    {
        int a = A[j];
        if (j == A.size() - 1 && a>=0)
        {
            sum += a;
            newVect.push_back(a);
            a = -1;
        }
        if (a >= 0)
        {
            sum += a;
            newVect.push_back(a);
            j++;
        }
        else
        {
            if (sum > finalSum)
            {
                finalSum = sum;
                finalVect.assign(newVect.begin(), newVect.end());
            }
            else if (sum == finalSum)
            {
                if (newVect.size() > finalVect.size())
                {
                    finalVect.assign(newVect.begin(), newVect.end());
                }
                else if (newVect.size() == finalVect.size())
                {
                    if (i < minIdx)
                    {
                        finalVect.assign(newVect.begin(), newVect.end());
                    }
                }
            }

            minIdx = i;
            j++;
            i = j;
            sum = 0;
            newVect = {};
        }
        cout << i << "  " << j << "  "<< finalSum << "  " << sum << endl;
    }
    return finalVect;
}

int main()
{
    vector<int> v = {-846930886, -1714636915, 424238335, -1649760492};

    vector<int> resVect = maxset(v);
    for (int i = 0; i < resVect.size(); i++)
    {
        cout << resVect[i] << " ";
    }
    return 0;
}
