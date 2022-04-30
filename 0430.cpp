#include <iostream>
#include <algorithm>
using namespace std;

int cookie[1000001];
int m, n;

bool func(int len)
{ // ���� ���̰� len�� ��, m�� �̻󿡰� �� �� �ִ��� ����
    int num = 0;
    for (int i = 0; i < n; i++)
    { // ���� ������ŭ �ݺ�
        num += cookie[i] / len;
    }
    return num >= m; // m�� �̻󿡰� �� �� �ִ���
}

int main()
{

    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> cookie[i];
    }

    int st = 0;
    int en = 1000000000;

    while (st < en)
    {
        int mid = st + (en - st + 1) / 2;

        if (func(mid))
            st = mid;
        else
            en = mid - 1;
    }

    cout << st;

    // m = ��ī�� ��
    // ���� ���� = cookie[]
    // ans = ������ �ִ� ����
    // ������ ���̰� x�� �� �� �� �ִ� ��ī �� = ��� ���ڿ� ���� cookie[]/x �� ��
    // st = 0, en = 1000000000
    // x�� �Լ��� �ְ� ��ȯ ���� m�̻��̸� st=mid
    // �ƴϸ� en=mid-1
}