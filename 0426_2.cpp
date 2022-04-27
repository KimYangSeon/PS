// ���� 1439 ������
// https://www.acmicpc.net/problem/1439

#include <iostream>
#include <algorithm>

using namespace std;
int main()
{

    string s_input;
    string s;
    bool is_same = true;

    cin >> s_input;

    int len = s_input.length();

    for (int i = 0; i < len; i++)
    {
        // ���ӵ� ���ڸ� �Ѱ��� ���ڷ� �����ؾ���

        if (i < len - 1 && s_input[i] != s_input[i + 1])
        {
            is_same = false;
        }

        if (i == len - 1)
        { // ������ ����

            if (s.length() == 0)
                is_same = false;
            else if (s[s.length() - 1] != s_input[i])
                is_same = false;
            // s�� ���������� ���� ���ڶ� s_input�� ������ ���ڰ� ���� �ٸ���
        }

        if (!is_same)
        {
            s += s_input[i];
            is_same = true;
        }
    }

    len = s.length();
    int count_1=0;
    int count_0=0;

    // 0�� 1�� ���� ����
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '1')
            count_1++;
        else
            count_0++;
    }

    if (count_0 > count_1) // 1�� ������
    {
        cout << count_1;
    }
    else // 0�� ������
    {
        cout << count_0;
    }
}
