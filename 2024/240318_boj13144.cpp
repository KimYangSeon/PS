#include <iostream>
using namespace std;

int n;
long long ans;
int arr[100001];
int cnt[100001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int l = 0;
    for (int r = 1; r <= n; r++)
    {
        cnt[arr[r-1]]++;
        while (l < r && cnt[arr[r - 1]] > 1)
            cnt[arr[l++]]--;
        
        ans += (r - l);
    }

    cout << ans;

    return 0;
}
