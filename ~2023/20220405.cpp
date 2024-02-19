// ���� 16236 
// https://www.acmicpc.net/problem/16236

#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[21][21];
int dist[21][21];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int shark_size = 2;
int eat_count = 0;
int cur_dist = 999;
int push_dist = 0;
int cur_eatX = 999;
int cur_eatY = 999;
pair<int, int> shark_pos;
bool eat_flag = false;
bool checked = false;
int ans;

void bfs()
{
}

int main()
{

    cin >> n;
    queue<pair<int, int>> Q;
    queue<int> Q_dist;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 9)
            { // ��� ��������
                Q.push({i, j});
                Q_dist.push(0);
                dist[i][j] = 0;
                shark_pos = {i, j};
            }
        }
    }

    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        Q_dist.pop();

        if ((Q_dist.front() == cur_dist && eat_flag) || (Q_dist.empty() && eat_flag))
            checked = true;

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny > n)
                continue;

            if (board[nx][ny] > shark_size)
                continue; // ����� Ŀ�� ��������

            if (-1 < dist[nx][ny])
                continue;

            dist[nx][ny] = dist[cur.first][cur.second] + 1; // nx ny �湮

            if (board[nx][ny] < shark_size && board[nx][ny] > 0 && board[nx][ny] < 9 && dist[nx][ny] <= cur_dist)
            { // ���� �� �ִ� ����� ã����
                eat_flag = true;

                // cout << "!!" << nx << " " << ny << '\n';

                if (nx < cur_eatX)
                { // ���� �ִ� ����� �켱

                    cur_eatX = nx;
                    cur_eatY = ny;
                }

                if (nx == cur_eatX) // x�� ������ ���� �켱
                {
                    if (ny < cur_eatY)
                    {
                        cur_eatY = ny;
                    }
                }

                cur_dist = dist[nx][ny]; // ���� ����� �������� �Ÿ�
                ans = cur_dist;
            }

            // if (Q_dist.empty() && eat_flag)
            // { // ���� �Ÿ��� ������ �� üũ����
            //     checked = true;
            // }

            Q.push({nx, ny});
            Q_dist.push(dist[nx][ny]);
        }

        if (eat_flag && checked)
        { // �Ա�

            board[cur_eatX][cur_eatY] = 9;
            cur_dist = dist[cur_eatX][cur_eatY];
            eat_count++;

            if (eat_count == shark_size)
            { // ��� ũ�� ����
                shark_size++;
                eat_count = 0;
                // cout << "size: " << shark_size << '\n';
            }

            for (int i = 0; i < n; i++) // dist �ʱ�ȭ
            {
                for (int j = 0; j < n; j++)
                {
                    dist[i][j] = -1;
                }
            }

            while (!Q.empty())
                Q.pop();
            while (!Q_dist.empty())
                Q_dist.pop();

            Q.push({cur_eatX, cur_eatY}); // ���ο� ������
            Q_dist.push(0);
            board[shark_pos.first][shark_pos.second] = 0;
            shark_pos = {cur_eatX, cur_eatY};
            dist[cur_eatX][cur_eatY] = cur_dist;
            eat_flag = false;
            checked = false;
            // ans = cur_dist;

            // cout << "eat" << '\n';
            // cout << cur_eatX << " " << cur_eatY << '\n';

            cur_dist = 999;
            cur_eatX = 999;
            cur_eatY = 999;

            // for (int i = 0; i < n; i++)
            // {
            //     for (int j = 0; j < n; j++)
            //     {
            //         cout << board[i][j] << ' ';
            //     }
            //     cout << '\n';
            // }
        }
    }

    cout << ans;
}