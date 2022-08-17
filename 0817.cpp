// ���� 16987��: ������� ���ġ�� (��Ʈ��ŷ)
// https://www.acmicpc.net/problem/16987
// ��ƴ�,,
#include <bits/stdc++.h>
using namespace std;

int n;
int ans;
bool isBroken[10];
vector<pair<int, int>> eggs; // ������, ����

void solve(int broken_cnt, int idx) // idx : �տ� �� ��� ��ȣ
{
    if (idx == n)
    { // �ֱٿ� ���� ������ ����� �� ���
        // cout << broken_cnt << '\n';
        ans = max(ans, broken_cnt);
        return;
    }

    // cout << idx << " ����� ";
    // cout <<"����: " <<  broken_cnt << '\n';

    if (isBroken[idx] || broken_cnt >= n - 1)
    {                               // �տ� �� ����� �����ų� ������ ���� �ٸ� ����� ���� ���
        solve(broken_cnt, idx + 1); // ġġ �ʰ� �Ѿ
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (idx == i)
                continue; // �ڱ� �ڽ��� �Ѿ

            int cur_broken_cnt = 0;
            bool egg1_broken = false;
            bool egg2_broken = false;

            if (!isBroken[i]) // ������ ���� ����� ����
            {
                eggs[idx].first -= eggs[i].second; // ��� ������ ����
                eggs[i].first -= eggs[idx].second;

                // cout << idx << " -> " << i << '\n';

                if (eggs[idx].first <= 0) // �տ� �� ����� ����
                {
                    isBroken[idx] = 1;
                    cur_broken_cnt++;
                    egg1_broken = 1;
                    // cout << idx << " ����\n";
                }
                if (eggs[i].first <= 0) // ģ ����� ����
                {
                    isBroken[i] = 1;
                    cur_broken_cnt++;
                    egg2_broken = 1;
                    // cout << i << " ����\n";
                }
            }
            solve(broken_cnt + cur_broken_cnt, idx + 1); // ������ �ֱٿ� ���� ����� �ٷ� ������ ����� ����

            if (egg1_broken)
            { // ���� ����� ���� �׽�Ʈ�ϱ� ���� ������� �ǵ���
                isBroken[idx] = 0;
            }
            if (egg2_broken)
            {
                isBroken[i] = 0;
            }

            if (!isBroken[i])
            {
                eggs[idx].first += eggs[i].second;
                eggs[i].first += eggs[idx].second;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        eggs.push_back({a, b});
    }

    solve(0, 0); // ù��° ����� ��� ����

    cout << ans;
}