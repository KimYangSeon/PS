// 백준 1406번: 에디터
// https://www.acmicpc.net/problem/1406

#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<char> l;
    string s;
    int n;
    cin >> s >> n;

    for (auto c : s)
    {
        l.push_back(c);
    }

    auto cur = l.end();


    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        if (c == 'L')
        {
            if (cur != l.begin())
                cur--;
        }
        else if (c == 'D')
        {
            if (cur != l.end())
                cur++;
        }
        else if (c == 'B')
        {
            if (cur != l.begin())
            {
                cur--;
                cur = l.erase(cur);
            }
        }
        else
        {
            cin >> c;
            cur = l.insert(cur, c);
            cur++;
        }
    }

    for (auto c : l)
        cout << c;
}