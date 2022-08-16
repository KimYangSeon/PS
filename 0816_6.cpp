// 백준 1941번: 소문난 칠공주 (백트래킹)
// https://www.acmicpc.net/problem/1941
#include <bits/stdc++.h>
using namespace std;

char arr[5][5];
int ans;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
bool vis[5][5];
vector<pair<int, int>> v;

bool check()
{
    pair<int, int> st;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (vis[i][j])
            {
                st = {i, j};
                break;
            }
        }
    }
    queue<pair<int, int>> q;
    q.push(st);

    bool vis2[5][5];
    for (int i = 0; i < 5; i++)
        fill(vis2[i], vis2[i] + 5, 0);
    vis2[st.first][st.second] = 1;

    int area = 0;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        area++;

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
                continue;
            if (!vis[nx][ny] || vis2[nx][ny])
                continue;

            vis2[nx][ny] = 1;
            q.push({nx, ny});
        }
    }

    if (area == 7)
        return true;
    else
        return false;
}

void solve(int cnt, int snum, int cx, int cy)
{
    if (cnt == 7)
    {
        if (snum >= 4 && check())
        {
            ans++;
        }
        return;
    }

    for (int i = cx; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == cx && j <= cy)
                continue;

            // if (cnt > 0 && !check(i, j))
            // continue;

            vis[i][j] = 1;
            v.push_back({i, j});
            if (arr[i][j] == 'S')
                solve(cnt + 1, snum + 1, i, j);
            else
                solve(cnt + 1, snum, i, j);
            vis[i][j] = 0;
            v.pop_back();
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> arr[i][j];

    solve(0, 0, 0, -1);

    cout << ans;
}