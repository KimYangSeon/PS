// 백준 22862 : 가장 긴 짝수 연속한 부분 수열 (large) 
// https://www.acmicpc.net/problem/22862
#include <iostream>
using namespace std;

int n, k, ans;
int arr[1000000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int l = 0, cnt = 0;

    while (l < n && arr[l] % 2 != 0) // 첫 짝수 만날때까지
        l++;

    int r = l;

    if (r != n)
        ans = 1;

    while (r < n)
    {
        if (cnt <= k)
        {
            ans = max(ans, r - l - cnt + 1);

            r++;
            while (r < n && arr[r] % 2 != 0)
            {
                r++;
                cnt++;
            }
        }
        else
        {
            l++;
            while (l <= r && arr[l] % 2 != 0)
            {
                l++;
                cnt--;
            }
        }
    }

    cout << ans;
    return 0;
}
