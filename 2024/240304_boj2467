// 백준 2467 : 용액 (투포인터)
#include <iostream>
using namespace std;

int n, ans1, ans2;
int arr[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int st = 0;
    int en = n - 1;
    ans1 = arr[st];
    ans2 = arr[en];
    int minSum = abs(arr[st] + arr[en]);

    while (st != en)
    {
        int curSum = arr[st] + arr[en];
        if (abs(curSum) < minSum)
        {
            minSum = abs(curSum);
            ans1 = arr[st];
            ans2 = arr[en];
        }

        if (curSum < 0)
            st++;
        else if (curSum > 0)
            en--;
        else
            break;
    }

    if (ans1 < ans2)
        cout << ans1 << ' ' << ans2;
    else
        cout << ans2 << ' ' << ans1;

    return 0;
}
