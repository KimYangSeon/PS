// 백준 7795번: 먹을 것인가 먹힐 것인가
// https://www.acmicpc.net/problem/7795

#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[20001];
int b[20001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int ans = 0;

        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        sort(b, b + m);

        for (int i = 0; i < n; i++)
        {
            int idx = lower_bound(b, b + m, a[i]) - b;
            ans += idx;
        }

        cout << ans << '\n';
    }
}