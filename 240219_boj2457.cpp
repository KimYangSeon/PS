#include <iostream>
#include <vector>
#include <algorithm>
#define st first
#define en second
using namespace std;

int n, ans;
vector<pair<int, int>> arr;
int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int convert(int m, int d)
{
    return day[m - 1] + d;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    int a, b, c, d;

    for (int i = 1; i <= 11; i++)
        day[i] += day[i - 1];

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c >> d;
        if (a < 3)
        {
            a = 3;
            b = 1;
        }
        if (c > 11)
        {
            c = 12;
            d = 1;
        }
        arr.push_back({day[a - 1] + b, day[c - 1] + d});
    }

    sort(arr.begin(), arr.end());

    int cur_en = convert(3, 1);
    int temp_en;
    int idx = 0;
    int ans_en = convert(12, 1);

    while (idx < n && cur_en < ans_en)
    {
        if (arr[idx].st > cur_en)
        { // 날짜 끊김
            ans = 0;
            break;
        }

        temp_en = cur_en;

        while (arr[idx].st <= cur_en && idx < n)
            temp_en = max(temp_en, arr[idx++].en);

        cur_en = temp_en;
        ans++;
    }

    if (cur_en < ans_en)
        ans = 0;

    cout << ans;

    return 0;
}