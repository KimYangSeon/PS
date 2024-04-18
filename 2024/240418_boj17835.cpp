// 백준 17835 : 면접보는 승범이
// https://www.acmicpc.net/problem/17835
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int n, m, k;
const long long MAX_DIST = LONG_LONG_MAX;
vector<pair<int, int>> adj[100001];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
long long dist[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        dist[i] = MAX_DIST;
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[v].push_back({c, u}); // 반대 방향으로 넣기
    }
    for (int i = 0; i < k; i++)
    {
        int num;
        cin >> num;
        pq.push({0, num}); // 시작 지점에 면접장 번호 다 넣기
        dist[num] = 0;
    }

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        long long curDist = cur.first;
        int curCity = cur.second;
        if (dist[curCity] != curDist)
            continue;
        for (auto nxt : adj[curCity])
        {
            long long nCost = nxt.first;
            int nCity = nxt.second;
            if (dist[nCity] <= dist[curCity] + nCost)
                continue;
            dist[nCity] = dist[curCity] + nCost;
            pq.push({dist[nCity], nCity});
        }
    }

    int ansNum = -1;
    long long ansDist = -1;
    for (int i = 1; i <= n; i++)
    {
        if (ansDist < dist[i])
        {
            ansDist = dist[i];
            ansNum = i;
        }
    }

    cout << ansNum << '\n'
         << ansDist;

    return 0;
}
