// 백준 1439 뒤집기
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
        // 연속된 숫자를 한개의 숫자로 압축해야함

        if (i < len - 1 && s_input[i] != s_input[i + 1])
        {
            is_same = false;
        }

        if (i == len - 1)
        { // 마지막 문자

            if (s.length() == 0)
                is_same = false;
            else if (s[s.length() - 1] != s_input[i])
                is_same = false;
            // s에 마지막으로 넣은 문자랑 s_input의 마지막 문자가 서로 다를때
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

    // 0과 1의 개수 세기
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '1')
            count_1++;
        else
            count_0++;
    }

    if (count_0 > count_1) // 1을 뒤집기
    {
        cout << count_1;
    }
    else // 0을 뒤집기
    {
        cout << count_0;
    }
}
