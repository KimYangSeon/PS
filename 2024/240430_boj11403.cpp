// https://www.acmicpc.net/problem/11403
// 백준 11403: 경로 찾기
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int v;
int adj[101][101];
int ans[101][101];
int vis[101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v;
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            cin >> adj[i][j];
        }
    }

    for (int st = 1; st <= v; st++)
    {
        queue<int> q;
        q.push(st);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            for (int nxt = 1; nxt <= v; nxt++)
            {
                if (adj[cur][nxt] == 0)
                    continue;
                if (vis[nxt] == st)
                    continue;
                vis[nxt] = st;
                ans[st][nxt] = 1;
                q.push(nxt);
            }
        }
    }

    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}
