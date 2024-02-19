// 백준 2448번: 별 찍기 - 11 (재귀)
// https://www.acmicpc.net/problem/2448
#include <iostream>
using namespace std;

char star[4000][8000]; // 가로 크기때문에 맞왜틀 함

void solve(int x, int y, int n) 
{
    if (n == 3) // 기본 별 모양
    {
        star[x][y + 2] = '*';
        star[x + 1][y + 1] = '*';
        star[x + 1][y + 3] = '*';
        for (int i = y; i < y + 5; i++)
            star[x + 2][i] = '*';
        return;
    }

    solve(x, y + n / 2, n / 2); 
    solve(x + n / 2, y, n / 2);
    solve(x + n / 2, y + n, n / 2);
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int m = n / 3;
    m = m - 1 + 5 * m; // 가로 길이

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            star[i][j] = ' '; // 빈 칸으로 초기화
        }
    }

    solve(0, 0, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << star[i][j];
        }
        cout << '\n';
    }
}