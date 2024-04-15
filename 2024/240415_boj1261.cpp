// 백준 1261 : 알고스팟
// https://www.acmicpc.net/problem/1261
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int n, m, ans;
int dist[101][101];
string board[101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for (int i = 0; i < n; i++)
        cin >> board[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dist[i][j] = n * m + 1;

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({0, 0, 0});
    dist[0][0] = 0;

    while (!pq.empty())
    {
        int curX, curY, curD;
        tie(curD, curX, curY) = pq.top();
        pq.pop();
        if (dist[curX][curY] != curD) // 최신 dist값 = 큐에 들어있던 dist 값인지 확인
            continue;

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            int ndist = dist[curX][curY];
            if (board[nx][ny] == '1')
                ndist++;

            if (dist[nx][ny] <= ndist)
                continue;

            dist[nx][ny] = ndist;
            pq.push({ndist, nx, ny});
        }
    }

    cout << dist[n - 1][m - 1];

    return 0;
}
