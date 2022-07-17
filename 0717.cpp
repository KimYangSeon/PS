// πÈ¡ÿ 4179π¯: ∫“!
// https://www.acmicpc.net/problem/4179

#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dist_j[1001][1001];
int dist_f[1001][1001];
string maze[1001];
queue<pair<int, int>> q_j; // ¡ˆ»∆
queue<pair<int, int>> q_f; // ∫“

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        cin >> maze[i];
    }

    for (int i = 0; i < r; i++)
    {
        fill(dist_j[i], dist_j[i] + c, -1);
        fill(dist_f[i], dist_f[i] + c, -1);
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (maze[i][j] == 'J')
            {
                q_j.push({i, j});
                dist_j[i][j] = 0;
            }
            else if (maze[i][j] == 'F')
            {
                q_f.push({i, j});
                dist_f[i][j] = 0;
            }
        }
    }

    // ∫“ bfs
    while (!q_f.empty())
    {
        auto cur = q_f.front();
        q_f.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
            if (dist_f[nx][ny] >= 0 || maze[nx][ny] == '#')
                continue;

            dist_f[nx][ny] = dist_f[cur.first][cur.second] + 1;
            q_f.push({nx, ny});
        }
    }

    // ¡ˆ»∆ bfs
    while (!q_j.empty())
    {
        auto cur = q_j.front();
        q_j.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
            { // ≈ª√‚
                cout << dist_j[cur.first][cur.second] + 1 << '\n';
                return 0;
            }
            if (dist_j[nx][ny] >= 0 || maze[nx][ny] == '#')
                continue;
            if (dist_f[nx][ny] >= 0 && dist_f[nx][ny] <= dist_j[cur.first][cur.second] + 1)
                continue; // ∫“¿Ã ¿ÃπÃ π¯¡¸

            dist_j[nx][ny] = dist_j[cur.first][cur.second] + 1;
            q_j.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE";
}