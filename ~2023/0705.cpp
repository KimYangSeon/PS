// 백준 1504번: 특정한 최단 경로
// https://www.acmicpc.net/problem/1504

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

vector<pair<int, int>> adj[801];
int n, e;
int d_1[801];
int d_v1[801];
int d_v2[801];
const int INF = 0x3f3f3f3f;

void dijkstra(int st, int (&d)[801])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    d[st] = 0;
    pq.push({d[st], st});

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        // X = cost, Y = 정점 번호
        if (d[cur.Y] != cur.X)
            continue;

        for (auto nxt : adj[cur.Y])
        { // 이웃한 정점
            if (d[nxt.Y] > d[cur.Y] + nxt.X)
            {
                d[nxt.Y] = d[cur.Y] + nxt.X;
                pq.push({d[nxt.Y], nxt.Y});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        adj[a].push_back({cost, b});
        adj[b].push_back({cost, a});
    }

    int v1, v2; // 거쳐야 하는 정점
    cin >> v1 >> v2;

    // 1번 -> N번 정점으로 가는데, v1이랑 v2는 반드시 거쳐야됨

    fill(d_1, d_1 + n + 1, INF);
    fill(d_v1, d_v1 + n + 1, INF);
    fill(d_v2, d_v2 + n + 1, INF);

    dijkstra(1, d_1);   // 1을 시작점으로 하는 경우
    dijkstra(v1, d_v1); // v1을 시작점으로 하는 경우
    dijkstra(v2, d_v2); // v2를 시작점으로 하는 경우

    // 1번 -> v1 -> v2 -> N
    // 1번 -> v2 -> v1 -> N
    // 둘 중에서 더 작은 경로 선택
    int case1;
    int case2;

    if (d_1[v1] == INF || d_v1[v2] == INF || d_v2[n] == INF)
        case1 = INF;
    else
        case1 = d_1[v1] + d_v1[v2] + d_v2[n];

    if (d_1[v1] == INF || d_v2[v1] == INF || d_v1[n] == INF)
        case2 = INF;
    else
        case2 = d_1[v2] + d_v2[v1] + d_v1[n];

    int ans = min(case1, case2);

    if (ans == INF)
        ans = -1;

    cout << ans << '\n';
}