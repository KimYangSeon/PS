// 백준 6198번: 옥상 정원 꾸미기
// https://www.acmicpc.net/problem/6198

#include <bits/stdc++.h>
using namespace std;

long long arr[80001]; // i번째 관리인이 볼 수 있는 빌딩
int height[80001]; // 각 빌딩의 높이 
long long ans;

int main()
{
    stack<pair<int, int>> s; // 높이, 번호 
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> height[i];
    }

    s.push({1000000001, 0});

    for (int i = n; i >= 1; i--)
    {
        while (s.top().first < height[i])
        {
            arr[i] += (arr[s.top().second] + 1);
            s.pop();
        }
        s.push({height[i], i});
        ans += arr[i];
    }
    cout << ans;
}