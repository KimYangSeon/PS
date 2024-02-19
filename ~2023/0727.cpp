// SWEA 4408. 자기 방으로 돌아가기

#include <bits/stdc++.h>
using namespace std;

int check[405];

int main()
{
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        cin >> n; // 학생 수
        for (int i = 1; i <= 400; i++)
            check[i] = 0;

        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;

            if (a > b)
                swap(a, b); // 작은번호 -> 큰번호로 가도록

            for (int j = a; j <= b; j++)
                check[j]++;
            if (b % 2 == 1)
                check[b + 1]++; // 1-3 이랑 4-6도 겹침 -> 홀수로 끝나면 그 다음까지 증가하도록 
        }

        cout << "#" << test_case << ' ' << *max_element(check + 1, check + 401) << '\n';
        // 겹친 수의 최대값
    }
    return 0;
}