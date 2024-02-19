// 백준 1629 곱셈
// https://www.acmicpc.net/problem/1629

#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

long long func(long long a, long long b, long long c) // a의 b승을 c로 나눈 나머지를 구하는 함수
{
    if (b == 1) // a의 1승
    {
        return a % c;
    }

    long long ans = func(a, b / 2, c);
    ans = ans * ans % c; // a의 b승을 미리 계산해놓음

    if (b % 2 == 0)
    { // a의 b승
        return ans;
    }
    else
    { // b가 2로 나누어 떨어지지 않을 때 a를 한번 더 곱해줌
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