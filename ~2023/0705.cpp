// ���� 1504��: Ư���� �ִ� ���
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

        // X = cost, Y = ���� ��ȣ
        if (d[cur.Y] != cur.X)
            continue;

        for (auto nxt : adj[cur.Y])
        { // �̿��� ����
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

    int v1, v2; // ���ľ� �ϴ� ����
    cin >> v1 >> v2;

    // 1�� -> N�� �������� ���µ�, v1�̶� v2�� �ݵ�� ���ľߵ�

    fill(d_1, d_1 + n + 1, INF);
    fill(d_v1, d_v1 + n + 1, INF);
    fill(d_v2, d_v2 + n + 1, INF);

    dijkstra(1, d_1);   // 1�� ���������� �ϴ� ���
    dijkstra(v1, d_v1); // v1�� ���������� �ϴ� ���
    dijkstra(v2, d_v2); // v2�� ���������� �ϴ� ���

    // 1�� -> v1 -> v2 -> N
    // 1�� -> v2 -> v1 -> N
    // �� �߿��� �� ���� ��� ����
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