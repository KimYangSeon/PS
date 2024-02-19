// 백준 15657번: N과 M (8) (백트래킹)
// https://www.acmicpc.net/problem/15657
#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans[10];
int arr[10];

void solve(int cur, int cnt)
{
    if (cnt == m) // m개를 다 고른 경우
    {
        for (int i = 0; i < m; i++)
        {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = cur; i < n; i++)
    {
        ans[cnt] = arr[i]; // 배열에 추가
        solve(i, cnt + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    solve(0, 0);
}