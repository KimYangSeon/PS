// SWEA 3316 동아리실 관리하기
#include <iostream>
using namespace std;

long long dp[10000][16];

int main(int argc, char **argv)
{
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        string s;
        cin >> s;
        int n = s.length();

        for(int i=0; i<n; i++){
            for(int j=0; j<16; j++){
                dp[i][j]=0;
            }
        }

        int x = 1 << (s[0] - 'A'); // 담당자

        // 첫날
        for (int i = 1; i < 16; i++)
        {
            if ((x & i) && (1 & i))
            {
                dp[0][i] = 1;
            }
        }

        // 둘째날 ~
        for (int day = 1; day < n; day++)
        {

            x = 1 << (s[day] - 'A'); // 담당자

            for (int i = 1; i < 16; i++)
            {                           // 15가지 경우의 수 중에서 따져봄
                if (dp[day - 1][i] != 0) // 전날에 i의 사람들이 나왔음
                {
                    for (int j = 1; j < 16; j++)
                    {
                        // 전날에 i의 사람들이 나왔을 때
                        // 오늘 j의 사람들이 나오는 게 가능한지 따져봄
                        // 총 15*15번 따져봄

                        if ((j & i) && (j & x))
                        { // 전날 나온 사람 포함 && 담당자 포함
                            dp[day][j] += dp[day-1][i];
                            dp[day][j] %= 1000000007;
                        }
                    }
                }
            }
        }
        

        long long ans = 0;
        for (int i = 1; i < 16; i++)
        {
            ans += dp[n - 1][i];
            ans %= 1000000007;
        }
        cout << '#' << test_case << ' ' << ans << '\n';
    }

    return 0;
}
