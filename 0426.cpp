// 백준 4883 삼각 그래프
// https://www.acmicpc.net/problem/4883

#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int graph[100002][3];
int dp[100002][3];

int main()
{

    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
        }

        /******************/

        //dp[0][0] = graph[0][0];
        dp[0][1] = graph[0][1]; // 시작지점
        dp[0][2] = dp[0][1] + graph[0][2];
        dp[1][0] = dp[0][1] + graph[1][0];
        dp[1][1] = min({dp[1][0],dp[0][1],dp[0][2]}) + graph[1][1];
        dp[1][2] = min({dp[1][1],dp[0][1],dp[0][2]}) + graph[1][2];

        for (int i = 2; i <= n - 1; i++)
        {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + graph[i][0];
            dp[i][1] = min({dp[i][0], dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + graph[i][1];
            dp[i][2] = min({dp[i][1], dp[i - 1][1], dp[i - 1][2]}) + graph[i][2];
        }

        cout << k + 1 << ". " << dp[n - 1][1] << '\n';
        k++;
    }
}