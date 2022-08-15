// ���� 15652��: N�� M (4) (��Ʈ��ŷ)
// https://www.acmicpc.net/problem/15652
#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

void solve(int cur, int cnt)
{
    if (cnt == m) // m���� �� �� ���
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = cur; i <= n; i++) // cur���� n���� 
    {
        arr[cnt] = i; // �迭�� �߰�
        solve(i, cnt + 1); // ������ �� ���� i�̻��̾�� ��
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    solve(1, 0);
}