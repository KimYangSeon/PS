// 백준 2617 : 구슬 찾기
// https://www.acmicpc.net/problem/2617
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj_in[100];
vector<int> adj_out[100];
int vis[100];

int bfs(int st, vector<int> adj[]){
    queue<int> q;
    q.push(st);
    vis[st]=st;
    int cnt=0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int nxt : adj[cur]){
            if(vis[nxt] == st) continue;
            vis[nxt]=st;
            cnt++;
            q.push(nxt);
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    int ans=0;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adj_in[a].push_back(b);
        adj_out[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        int cnt1 = bfs(i, adj_in);
        int cnt2 = bfs(i, adj_out);
        if(cnt1 >= (n+1)/2 || cnt2 >= (n+1)/2) ans++;
    }

    cout << ans;

    return 0;
}
