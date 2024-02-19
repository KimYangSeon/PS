// 백준 2468 : 안전 영역(BFS)
// https://www.acmicpc.net/problem/2468

#include <bits/stdc++.h>
using namespace std;

int n, ans;
int board[101][101];
bool vis[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int h)
{
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] || board[i][j] <= h)
                continue;

            vis[i][j] = 1;
            queue<pair<int, int>> q;
            q.push({i, j});
            cnt++;
            // cout << cnt << ' ';

            while (!q.empty())
            {
                auto cur = q.front();
                q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                        continue;
                    if (vis[nx][ny] || board[nx][ny] <= h)
                        continue;

                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    return cnt;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    ans = 1; // 이거때문에 맞왜틀 함 (비가 안오는 경우 고려...)

    for (int i = 1; i <= 100; i++)
    {
        int curcnt = bfs(i);
        if (curcnt == 0)
            break;

        ans = max(ans, curcnt);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                vis[i][j] = 0;
            }
        }
    }

    cout << ans;

    return 0;
}