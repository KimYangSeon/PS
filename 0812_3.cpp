// ¹éÁØ 2447¹ø: º° Âï±â - 10 (Àç±Í)
// https://www.acmicpc.net/problem/2447
#include <iostream>
using namespace std;

char star[6600][6600];

void solve(int x, int y, int n)
{
    if (n == 3)
    {
        for (int i = x; i < x + n; i++)
        {
            for (int j = y; j < y + n; j++)
            {
                star[i][j] = '*';
            }
        }
        star[x + 1][y + 1] = ' '; // °¡¿îµ¥ ºóÄ­
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 1 && j == 1)
                continue; // °¡¿îµ¥ °Ç³Ê¶Ù±â
            solve(x + n / 3 * i, y + n / 3 * j, n / 3);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            star[i][j] = ' '; // ºó Ä­À¸·Î ÃÊ±âÈ­
        }
    }

    solve(0, 0, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << star[i][j];
        }
        cout << '\n';
    }
}