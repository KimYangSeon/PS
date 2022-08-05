// 백준 5014: 스타트링크 (bfs)
// https://www.acmicpc.net/problem/5014

#include <bits/stdc++.h>
using namespace std;

int dist[1000001];
int n, st, goal, up, down;

int main()
{
    cin >> n >> st >> goal >> up >> down;

    for (int i = 0; i <= n; i++)
        dist[i] = -1;

    queue<int> q;
    q.push(st);
    dist[st] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        //cout << cur << ' ';

        int nu = cur + up;
        int nd = cur - down;

        if (nu > 0 && nu <= n && dist[nu] == -1)
        {
            dist[nu] = dist[cur] + 1;
            q.push(nu);
        }

        if (nd > 0 && nd <= n && dist[nd] == -1)
        {
            dist[nd] = dist[cur] + 1;
            q.push(nd);
        }
    }

    if (dist[goal] == -1)
    {
        cout << "use the stairs";
    }
    else
    {
        cout << dist[goal];
    }

    return 0;
}