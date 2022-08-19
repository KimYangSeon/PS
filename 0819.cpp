// 백준 1431번: 시리얼 번호 (STL sort cmp함수 연습)
// https://www.acmicpc.net/problem/1431

#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> v;

int solve(const string &s)
{
    int len = s.length();
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            sum += (s[i] - '0');
        }
    }
    return sum;
}

bool cmp(const string &a, const string &b)
{
    if (a.length() != b.length())
        return a.length() < b.length();

    int suma = solve(a);
    int sumb = solve(b);
    if (suma != sumb)
        return suma < sumb;

    return a < b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }

    sort(v.begin(), v.end(), cmp);

    for (auto x : v)
        cout << x << '\n';
}