// 백준 15650번: N과 M (2) (백트래킹)
// https://www.acmicpc.net/problem/15650
#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[10];
// int arr[10];
// bool isused[10];

/*
void solve(int cur, int cnt)
{
    if (cnt == m)
    {
        for (int i = 1; i <= n; i++)
        {
            if (isused[i])
                cout << i << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = cur; i <= n; i++)
    {
        if (!isused[i])
        {
            isused[i] = 1;
            solve(i + 1, cnt + 1);
            isused[i] = 0;
        }
    }
}
*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = n - 1; i > m - 1; i--)
    {
        a[i] = 1;
    }

    do
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
                cout << i + 1 << ' ';
        }
        cout << '\n';
    } while (next_permutation(a, a + n));
}