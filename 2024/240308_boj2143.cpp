// 백준 2143 : 두 배열의 합
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, t;
long long ans;
int A[1001];
int B[1001];
vector<int> A_sum;
vector<int> B_sum;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> B[i];

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += A[j];
            A_sum.push_back(sum);
        }
    }

    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        for (int j = i; j < m; j++)
        {
            sum += B[j];
            B_sum.push_back(sum);
        }
    }

    sort(B_sum.begin(), B_sum.end());

    for (auto a : A_sum)
    {
        int lower = lower_bound(B_sum.begin(), B_sum.end(), t - a) - B_sum.begin();
        int upper = upper_bound(B_sum.begin(), B_sum.end(), t - a) - B_sum.begin();

        ans += upper - lower;
    }

    cout << ans;

    return 0;
}
