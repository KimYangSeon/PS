#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, ans;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int s, t;
        cin >> s >> t;
        v.push_back({s, t});
    }

    sort(v.begin(), v.end());
    pq.push(v[0].second);

    for (int i = 1; i < n; i++)
    {
        if (v[i].first >= pq.top())
            pq.pop();

        pq.push(v[i].second);
    }

    cout << pq.size();

    return 0;
}