#include <bits/stdc++.h>
using namespace std;

// 백준 1697번: 숨바꼭질
// https://www.acmicpc.net/problem/1697

int dist[100005];

int bfs(int n, int k){

    queue<int> q;
    q.push(n); // 시작점
    dist[n] = 0;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int dir=0; dir<3; dir++){
            int nx;

            if(dir==0){
                nx = cur -1;
            }
            else if(dir==1){
                nx = cur + 1;
            }
            else{
                nx = cur * 2;
            }

            if(nx<0 || nx>=100005) continue;
            if(dist[nx] > -1) continue;

            dist[nx] = dist[cur] + 1;
            q.push(nx);

            if(nx == k){ // 찾음
                return dist[nx];
            }
        }
    }

    return 0;
}

int main(){
    int n, k;
    cin >> n >> k;

    for(int i=0; i<100005; i++){
        dist[i] = -1;
    }

    cout << bfs(n, k);

}