// น้มุ 2573น๘: บ๙ป๊ (BFS)
// https://www.acmicpc.net/problem/2573

#include <bits/stdc++.h>
using namespace std;

int ice[301][301];
int vis[301][301];
int melt[301][301];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void thaw()
{
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            if (ice[i][j] <= 0)
                continue;

            int cnt = 0;

            if (ice[i + 1][j] <= 0)
                cnt++;
            if (ice[i][j + 1] <= 0)
                cnt++;
            if (ice[i - 1][j] <= 0)
                cnt++;
            if (ice[i][j - 1] <= 0)
                cnt++;

            melt[i][j] = cnt;
        }
    }

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            ice[i][j] -= melt[i][j];
        }
    }
}

int bfs(int year)
{
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] >= year || ice[i][j] <= 0)
                continue;

            queue<pair<int, int>> q;
            q.push({i, j});
            vis[i][j] = year;
            cnt++;
            // cout << i << ' ' << j << '\n';

            while (!q.empty())
            {
                auto cur = q.front();
                q.pop();

                // cout << cur.first << ' '<< cur.second << '\n';

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= m)

                        continue;

                    if (vis[nx][ny] >= year || ice[nx][ny] <= 0)

                        continue;

                    vis[nx][ny] = year;
                    //cout << "year: " << year << ' ';
                    q.push({nx, ny});
                }
            }
        }
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ice[i][j];
        }
    }

    int year = 1;

    while (true)
    {
        int ans = bfs(year);
        //cout << "ans: " << ans << '\n';

        if (ans > 1)
        {
            cout << year-1;
            return 0;
        }
        else if (ans == 0)
        {
            cout << 0;
            return 0;
        }
        year++;
        thaw();
    }
}