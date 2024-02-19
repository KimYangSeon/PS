// ���� 1629 ����
// https://www.acmicpc.net/problem/1629

#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

long long func(long long a, long long b, long long c) // a�� b���� c�� ���� �������� ���ϴ� �Լ�
{
    if (b == 1) // a�� 1��
    {
        return a % c;
    }

    long long ans = func(a, b / 2, c);
    ans = ans * ans % c; // a�� b���� �̸� ����س���

    if (b % 2 == 0)
    { // a�� b��
        return ans;
    }
    else
    { // b�� 2�� ������ �������� ���� �� a�� �ѹ� �� ������
        return ans * a % c;
    }
}

int main()
{
    long long a, b, c;

    cin >> a >> b >> c;

    cout << func(a, b, c);
    return 0;
}