// https://www.acmicpc.net/problem/14502
// 백준 14502번: 연구소
// 완전탐색 + bfs
// 시간복잡도: O(n^2 * 64 * 63 * 62)

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
int board[9][9];
int board_bfs[9][9];
int ans;
bool check[9][9];
bool vis[9][9];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<pair<int, int>> virus;

void bfs() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			vis[i][j] = 0;
			board_bfs[i][j] = board[i][j];
		}
	}
		
	queue<pair<int, int>> q;

	for (auto v : virus) {
		q.push(v);
		vis[v.X][v.Y] = 1;
	}

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board_bfs[nx][ny] != 0) continue;

			vis[nx][ny] = 1;
			board_bfs[nx][ny] = 2;
			q.push({ nx,ny });
		}
	}

}

void solve(int x, int y, int cnt) {

	if (cnt == 3) {
		int curans = 0;
		bfs();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board_bfs[i][j] == 0) {
					curans++;
				}
			}
		}
		ans = max(ans, curans);
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (i <= x && j <= y) continue;
			if (board[i][j] != 0) continue;
	
			board[i][j] = 1;
			solve(i, j, cnt + 1);
			board[i][j] = 0;
		}
	}
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
	}

	solve(-1, -1, 0);

	cout << ans;


	return 0;
}