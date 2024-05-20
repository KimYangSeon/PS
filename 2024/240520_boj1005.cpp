// 백준 1005 : ACM Craft
// https://www.acmicpc.net/problem/1005
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int t, n, k, w, ans;
int time[1001];
int deg[1001];
int maxTime[1001];
bool vis[1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--)
	{
		vector<int> adj[1001];
		vector<int> adj_reverse[1001];

		cin >> n >> k;

		ans = 0;
		for (int i = 0; i <= n; i++)
		{
			deg[i] = 0;
			vis[i] = 0;
			maxTime[i] = -1;
		}

		for (int i = 1; i <= n; i++)
			cin >> time[i];

		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj_reverse[y].push_back(x);
			deg[y]++;
		}
		cin >> w;

		queue<int> q;
		ans = 0;

		vis[w] = 1;
		q.push(w);

		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			for (int nxt : adj_reverse[cur])
			{
				if (vis[nxt])
					continue;
				vis[nxt] = 1;
				q.push(nxt);
			}
		}

		for (int i = 1; i <= n; i++)
		{
			if (vis[i] && deg[i] == 0)
			{
				q.push(i);
				maxTime[i] = time[i];
			}
		}

		while (!q.empty())
		{
			auto cur = q.front();
			q.pop();

			for (auto nxt : adj[cur])
			{
				if (!vis[nxt])
					continue;

				deg[nxt]--;
				maxTime[nxt] = max(maxTime[nxt], maxTime[cur] + time[nxt]);

				if (deg[nxt] == 0)
					q.push(nxt);
			}
		}

		cout << maxTime[w] << '\n';
	}

	return 0;
}

/*
목적지부터 거꾸로 타고가면서 반드시 방문해야 할 점을 미리 vis에 표시
degree가 0인 점들을 큐에 push 후 탐색 시작 (vis가 true인 점만 탐색함)
탐색하면서 점에 방문할 때마다 시간의 최대값(maxTime)을 갱신
*/
