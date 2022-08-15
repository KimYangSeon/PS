// 백준 15655번: N과 M (6) (백트래킹)
// https://www.acmicpc.net/problem/15655
#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans[10];
int arr[10];

// void solve(int cur, int cnt)
// {
//     if (cnt == m) // m개를 다 고른 경우
//     {
//         for (int i = 0; i < m; i++)
//         {
//             cout << ans[i] << ' ';
//         }
//         cout << '\n';
//         return;
//     }

//     for (int i = cur; i < n; i++)
//     {
//         ans[cnt] = arr[i]; // 배열에 추가
//         solve(i + 1, cnt + 1);
//     }
// }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    // solve(0, 0);

    int a[10];
    for (int i = 0; i < n; i++)
    {
        if (i < m)
            a[i] = 0;
        else
            a[i] = 1;
    }

    do
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
                cout << arr[i] << ' ';
        }
        cout << '\n';
    } while (next_permutation(a, a + n));
}