// SWEA 4408. �ڱ� ������ ���ư���

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
        cin >> n; // �л� ��
        for (int i = 1; i <= 400; i++)
            check[i] = 0;

        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;

            if (a > b)
                swap(a, b); // ������ȣ -> ū��ȣ�� ������

            for (int j = a; j <= b; j++)
                check[j]++;
            if (b % 2 == 1)
                check[b + 1]++; // 1-3 �̶� 4-6�� ��ħ -> Ȧ���� ������ �� �������� �����ϵ��� 
        }

        cout << "#" << test_case << ' ' << *max_element(check + 1, check + 401) << '\n';
        // ��ģ ���� �ִ밪
    }
    return 0;
}