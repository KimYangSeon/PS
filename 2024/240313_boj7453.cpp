#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
long long ans;
int A[4001], B[4001], C[4001], D[4001];
vector<int> two;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i] >> B[i] >> C[i] >> D[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            two.push_back(A[i] + B[j]);
     

    sort(two.begin(), two.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = C[i] + D[j];
            ans += (upper_bound(two.begin(), two.end(), -sum) - lower_bound(two.begin(), two.end(), -sum));
        }
    }

    cout << ans;
    return 0;
}
