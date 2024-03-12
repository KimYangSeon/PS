// 백준 2473 : 세 용액
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
long long ansSum = 3000000001;
long long arr[5001];
long long ans[3];

void check(int idx, long long a, long long b)
{
    if (idx >= n || idx < 0)
        return;
    if (arr[idx] == a || arr[idx] == b)
        return;

    long long sum = abs(arr[idx] + a + b);
    if (arr[idx] != a && arr[idx] != b && sum < ansSum)
    {
        ansSum = sum;
        ans[0] = a;
        ans[1] = b;
        ans[2] = arr[idx];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int idx = lower_bound(arr, arr + n, -(arr[i] + arr[j])) - arr;
            for (int k = -2; k <= 2; k++)
            {
                check(idx + k, arr[i], arr[j]);
            }
        }
    }

    sort(ans, ans + 3);
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];
    return 0;
}
