#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, ans;
int arr[2001];
vector<int> two;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            int upper = upper_bound(arr, arr + n, arr[i] - arr[j]) - arr;
            int lower = lower_bound(arr, arr + n, arr[i] - arr[j]) - arr;
            if (lower == n || arr[lower] != arr[i] - arr[j])
                continue;

            int cnt = 0;
            // 만약 찾는 수가 없으면 arr[lower] != arr[i] - arr[j] 
            if (arr[i] - arr[j] == arr[i])
                cnt++;
            if (arr[i] - arr[j] == arr[j])
                cnt++;

            if (upper - lower > cnt)
            {
                ans++;
                break;
            }
        }
    }

    cout << ans;

    return 0;
}
