#include <iostream>
#include <queue>
using namespace std;

long long n, m, ans;
long long arr[1000];
priority_queue<long long, vector<long long>, greater<long long> > pq;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        int a;
        cin>>a;
        pq.push(a);
    }

    int cnt = 0;
    while(cnt<m){
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        pq.push(a+b);
        pq.push(a+b);
        cnt++;
    }

    while(!pq.empty()){
        ans += pq.top();
        pq.pop();
    }

    cout << ans;

    return 0;
}