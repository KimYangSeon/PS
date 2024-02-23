#include <iostream>
using namespace std;

int n, k, ans;
int arr[101];
int isUsed[101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < k; i++)
        cin >> arr[i];

    int usedCnt = 0;

    for (int i = 0; i < k; i++)
    {
        if (isUsed[arr[i]]) // 현재 사용중인 전기용품
            continue; 

        if (usedCnt < n) // 콘센트에 빈 자리가 있음
        { 
            usedCnt++;
        }
        else // 빈 자리가 없음
        {                                   
            int selectedValue = arr[i + 1]; // 뽑을 번호
            int selectedIdx = i + 1;
            // int cIdx = 0;
            for (int num = 1; num <= k; num++) // 사용중인 것들 중에서 처음으로 나타난 위치가 가장 나중인 것 선택
            {
                if (!isUsed[num])
                    continue;

                bool isFind = false;
                for (int j = i + 1; j < k; j++)
                {
                    if (num == arr[j])
                    {
                        isFind = true;
                        if (selectedIdx < j)
                        {
                            selectedIdx = j;
                            selectedValue = num;
        
                        }
                        break;
                    }
                }

                if (!isFind)
                { // 안타나났음
                    selectedValue = num;
                    break;
                }
            }

            isUsed[selectedValue] = 0;
            ans++;
        }

        isUsed[arr[i]] = 1;
    }

    cout << ans;

    return 0;
}