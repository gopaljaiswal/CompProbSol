
#include <iostream>
using namespace std;
int arr[2] = {1,1};

int bst(int num)
{
    int low = 0, high = sizeof(arr) / sizeof(*arr);
    //cout << low << ' ' << high;
    bool flag = false;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == num)
        {
            flag = true;
            break;
        }
        else if (arr[mid] < num)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
        cout << flag << ' ' << low << ' ' << high << '\n';
    }
    return flag;
}

// main
int main()
{
    // int t;
    // cin >> t;
    // for (int i = 0; i < t; i++)
    // {
    //     int num;
    //     cin >> num;
    //     arr[i] = num;
    // }
    cout << bst(1);
    return 0;
}