// SWEA 1248. 공통조상

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10000];
int p[10000];

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int v, e, x, y;
        cin >> v >> e >> x >> y;

        for (int i = 0; i < v; i++)
        {
            fill(adj[i].begin(), adj[i].end(), 0);
        }
        fill(p, p + v, 0);

        for (int i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b); // 부모 - 자식
            p[b] = a;            // 부모노드 기록
        }

        int x_pnum = 0;
        int y_pnum = 0;
        int temp = x;

        vector<int> x_plist;
        vector<int> y_plist;

        while (temp != 1)
        {
            temp = p[temp];
            x_pnum++;
            // x_plist.push_back(temp);
        }

        temp = y;

        while (temp != 1)
        {
            temp = p[temp];
            y_pnum++;
            // y_plist.push_back(temp);
        }

        while (x != y)
        {
            if (x_pnum < y_pnum)
            {
                y_pnum--;
                y = p[y];
            }
            else
            {
                x_pnum--;
                x = p[x];
            }
        }

        queue<int> q;

        q.push(x);
        int sub_size = 0;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            sub_size++;
            //cout << sub_size << ' ';

            for (int nxt : adj[cur])
            {
                if(nxt==0) continue;
                //if (p[cur] == nxt)
                    //continue;
                q.push(nxt);
            }
        }

        cout << '#' << test_case << ' ' << x << ' ' << sub_size << '\n';
    }
    return 0;
}