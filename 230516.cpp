// https://www.acmicpc.net/problem/2493
// 백준 2490 : 탑 (스택)

#include <iostream>
#include <stack>
#include <utility>
using namespace std;
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n;
    cin >> n;
    stack<pair<int, int>> s; // 번호, 높이
 
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
 
        while (!s.empty() && s.top().second < t)
            s.pop();
 
        if (s.empty())
            cout << 0 << ' ';
        else
            cout << s.top().first << ' ';
 
        s.push({i + 1, t});
    }
 
    return 0;
}