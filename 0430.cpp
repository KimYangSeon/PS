#include <iostream>
#include <algorithm>
using namespace std;

int cookie[1000001];
int m, n;

bool func(int len)
{ // 과자 길이가 len일 때, m명 이상에게 줄 수 있는지 구함
    int num = 0;
    for (int i = 0; i < n; i++)
    { // 과자 갯수만큼 반복
        num += cookie[i] / len;
    }
    return num >= m; // m명 이상에게 줄 수 있는지
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

    // m = 조카의 수
    // 과자 길이 = cookie[]
    // ans = 과자의 최대 길이
    // 과자의 길이가 x일 때 줄 수 있는 조카 수 = 모든 과자에 대한 cookie[]/x 의 합
    // st = 0, en = 1000000000
    // x를 함수에 넣고 반환 값이 m이상이면 st=mid
    // 아니면 en=mid-1
}