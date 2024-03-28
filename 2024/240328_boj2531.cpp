// 백준 2531 : 회전초밥
// https://www.acmicpc.net/problem/2531
#include <iostream>
using namespace std;

int n, d, k, c, cur, ans;
int arr[30001];
int cnt[3001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d >> k >> c;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cnt[c]=1;
    ans=1;
    cur=1;

    for (int i = 0; i < k; i++)
    {
        int sushi = arr[i];
        if (cnt[sushi] == 0)
            cur++;
        cnt[sushi]++;
    }

    ans = max(ans, cur);

    int l = 0, r = k - 1;
    int l_sushi, r_sushi;

    for (int i = 0; i < n - 1; i++)
    {
        l_sushi = arr[l++];
        cnt[l_sushi]--;
        if (cnt[l_sushi] == 0)
            cur--;

        if (r == n - 1)
            r = -1;
        r_sushi = arr[++r];
        if (cnt[r_sushi] == 0)
            cur++;
        cnt[r_sushi]++;

        ans = max(ans, cur);
    }

    cout << ans;

    return 0;
}
