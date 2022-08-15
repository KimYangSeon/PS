// 백준 15652번: N과 M (4) (백트래킹)
// https://www.acmicpc.net/problem/15652
#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

void solve(int cur, int cnt)
{
    if (cnt == m) // m개를 다 고른 경우
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = cur; i <= n; i++) // cur부터 n까지 
    {
        arr[cnt] = i; // 배열에 추가
        solve(i, cnt + 1); // 다음에 고를 수는 i이상이어야 함
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    solve(1, 0);
}