// ���� 15657��: N�� M (8) (��Ʈ��ŷ)
// https://www.acmicpc.net/problem/15657
#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans[10];
int arr[10];

void solve(int cur, int cnt)
{
    if (cnt == m) // m���� �� �� ���
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
        ans[cnt] = arr[i]; // �迭�� �߰�
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