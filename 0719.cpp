// SWEA 3316 ���Ƹ��� �����ϱ�
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

        int x = 1 << (s[0] - 'A'); // �����

        // ù��
        for (int i = 1; i < 16; i++)
        {
            if ((x & i) && (1 & i))
            {
                dp[0][i] = 1;
            }
        }

        // ��°�� ~
        for (int day = 1; day < n; day++)
        {

            x = 1 << (s[day] - 'A'); // �����

            for (int i = 1; i < 16; i++)
            {                           // 15���� ����� �� �߿��� ������
                if (dp[day - 1][i] != 0) // ������ i�� ������� ������
                {
                    for (int j = 1; j < 16; j++)
                    {
                        // ������ i�� ������� ������ ��
                        // ���� j�� ������� ������ �� �������� ������
                        // �� 15*15�� ������

                        if ((j & i) && (j & x))
                        { // ���� ���� ��� ���� && ����� ����
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
