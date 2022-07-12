// 백준 17298번: 오큰수
// https://www.acmicpc.net/problem/17298

#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
int ans[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> arr[i];
    }

    for (int i = n-1; i >=0; i--)
    {
        while(!s.empty() && s.top() <= arr[i]){
            s.pop();
        }

        if(s.empty()){
            ans[i]=-1;
        }
        else{
            ans[i]=s.top();
        }

        s.push(arr[i]);
    }

    for(int i=0; i<n; i++) cout << ans[i] << ' ';
}