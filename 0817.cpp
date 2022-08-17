// 백준 16987번: 계란으로 계란치기 (백트래킹)
// https://www.acmicpc.net/problem/16987
// 어렵당,,
#include <bits/stdc++.h>
using namespace std;

int n;
int ans;
bool isBroken[10];
vector<pair<int, int>> eggs; // 내구도, 무게

void solve(int broken_cnt, int idx) // idx : 손에 든 계란 번호
{
    if (idx == n)
    { // 최근에 가장 오른쪽 계란을 든 경우
        // cout << broken_cnt << '\n';
        ans = max(ans, broken_cnt);
        return;
    }

    // cout << idx << " 들었음 ";
    // cout <<"현재: " <<  broken_cnt << '\n';

    if (isBroken[idx] || broken_cnt >= n - 1)
    {                               // 손에 든 계란이 깨졌거나 깨지지 않은 다른 계란이 없는 경우
        solve(broken_cnt, idx + 1); // 치치 않고 넘어감
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (idx == i)
                continue; // 자기 자신은 넘어감

            int cur_broken_cnt = 0;
            bool egg1_broken = false;
            bool egg2_broken = false;

            if (!isBroken[i]) // 깨지지 않은 계란을 선택
            {
                eggs[idx].first -= eggs[i].second; // 계란 내구도 감소
                eggs[i].first -= eggs[idx].second;

                // cout << idx << " -> " << i << '\n';

                if (eggs[idx].first <= 0) // 손에 든 계란이 깨짐
                {
                    isBroken[idx] = 1;
                    cur_broken_cnt++;
                    egg1_broken = 1;
                    // cout << idx << " 깨짐\n";
                }
                if (eggs[i].first <= 0) // 친 계란이 깨짐
                {
                    isBroken[i] = 1;
                    cur_broken_cnt++;
                    egg2_broken = 1;
                    // cout << i << " 깨짐\n";
                }
            }
            solve(broken_cnt + cur_broken_cnt, idx + 1); // 다음엔 최근에 들은 계란의 바로 오른쪽 계란을 들음

            if (egg1_broken)
            { // 다음 경우의 수를 테스트하기 위해 원래대로 되돌림
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

    solve(0, 0); // 첫번째 계란을 들고 시작

    cout << ans;
}