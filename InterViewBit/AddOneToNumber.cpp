
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> plusOne(vector<int> &A)
{
    int n = A.size() - 1;
    for (int i = n; i >= 0; i--)
    {
        int sum = A[i];
        if (i == n)
        {
            sum += 1;
        }
        if (i == 0 && sum > 9)
        {
            A[i] = 0;
            A.insert(A.begin(), sum % 9);
            break;
        }

        if (sum > 9)
        {
            A[i] = 0;
            A[i - 1] = A[i - 1] + sum % 9;
        }
        else
        {
            A[i] = sum;
            break;
        }
    }

    while (true)
    {
        if (A[0] > 0)
        {
            break;
        }
        A.erase(A.begin());
    }
    return A;
}

int main()
{
    vector<int> A = {0, 6, 0, 6, 4, 8, 8, 1};

    vector<int> res = plusOne(A);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}
