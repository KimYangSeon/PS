// 백준 5430번: AC
// https://www.acmicpc.net/problem/5430

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        string p;
        cin >> p;
        int len = p.length();

        int n;
        cin >> n;
        string x;
        cin >> x;

        x.erase(x.begin());
        x.erase(x.end() - 1);

        istringstream ss(x);
        string subs;

        deque<string> dq;
        dq.clear();

        while (getline(ss, subs, ','))
        {
            dq.push_back(subs);
        }

        bool r = false;
        bool isError = false;

        for (int i = 0; i < len; i++)
        {
            if (p[i] == 'R')
            {
                r = !r;
            }
            else
            {
                if (!dq.empty())
                {
                    if (r)
                    {
                        dq.pop_back();
                    }
                    else
                    {
                        dq.pop_front();
                    }
                }
                else
                {
                    cout << "error\n";
                    isError = true;
                    break;
                }
            }
        }

        if (isError)
            continue;

        int dq_len = dq.size();

        if (dq_len == 0)
        {
            cout << "[]\n";
            continue;
        }

        if (r)
            reverse(dq.begin(), dq.end());

        cout << '[' << dq[0];
        for (int i = 1; i < dq_len; i++)
        {
            cout << ',' << dq[i];
        }
        cout << "]\n";
    }

    return 0;
}