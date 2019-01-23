#include "algorithm"
#include "iostream"

using namespace std;

const int MAX = 1e5;
int A[MAX+5];
int main() {
    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> A[i];
    sort(A, A+n);
    int res = 0;
    for(int i=0;i<n-1;i++) {
        res += binary_search(A+i+1, A+n, A[i] + k);
    }
    printf("%d", res);
}