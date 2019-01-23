

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

// brute force
// int maxArr(vector<int> &A)
// {
//     int max = INT_MIN;
//     for (int i = 0; i < A.size(); i++)
//     {
//         for (int j = i + 1; j < A.size(); j++)
//         {
//             int diff = abs(A[j] - A[i]) + (j - i);

//             if (diff > max)
//             {
//                 max = diff;
//             }
//         }
//     }
//     return max;
// }

int maxArr(vector<int> &A)
{
    int max1 = INT_MIN, max2 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;

    for (int i = 0; i < A.size(); i++)
    {
        max1 = max(max1, A[i] + i);
        min1 = min(min1, A[i] + i);

        max2 = max(max2, A[i] - i);
        min2 = min(min2, A[i] - i);
    }
    return max((max1 - min1), (max2 - min2));
}

int main()
{
    vector<int> arr = {-70, -64, -6, -56, 64,61, -57, 16, 48, -98};
    cout << maxArr(arr);
    return 0;
}
