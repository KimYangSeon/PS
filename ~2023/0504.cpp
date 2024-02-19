// 백준 2230 수 고르기
// https://www.acmicpc.net/problem/2230

#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int ans = 2000000001;
int A[100001];

int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    ///////////////////////

    sort(A, A + n);

    int st = 0, en = 0;

    for (st; st < n; st++)
    {
        for (en; en < n; en++)
        {
            if (A[en] - A[st] >= m)
            {
                ans = min(ans, A[en] - A[st]);
                break;
            }
        }
        if(en==n) break;
    }

    //////////////////////

    cout << ans;
}