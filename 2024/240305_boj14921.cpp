// 백준 14921 : 용액 합성하기
#include <iostream>
#include <algorithm>
using namespace std;

int n, ans;
int arr[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    ans = 200000001;

    for (int i = 0; i < n; i++)
    {
        int idx = lower_bound(arr, arr + n, -arr[i]) - arr;

        if (idx < n && i != idx && abs(arr[i] + arr[idx]) < abs(ans))
        {
            ans = arr[i] + arr[idx];
        }

        if (idx - 1 >= 0 && i != idx - 1 && abs(arr[i] + arr[idx - 1]) < abs(ans))
        {
            ans = arr[i] + arr[idx - 1];
        }

        if (idx + 1 < n && i != idx + 1 && abs(arr[i] + arr[idx + 1]) < abs(ans))
        {
            ans = arr[i] + arr[idx + 1];
        }
    }

    cout << ans;

    return 0;
}
