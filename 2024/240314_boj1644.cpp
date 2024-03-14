#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, ans;
vector<int> primes;
vector<bool> state(4000001, 1);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 2; i * i <= n; i++)
    {
        if (!state[i])
            continue;
        for (int j = i * i; j <= n; j += i)
            state[j] = false;
    }

    for (int i = 2; i <= n; i++)
        if (state[i])
            primes.push_back(i);

    int m = primes.size();
    if (m == 0)
    {
        cout << 0;
        return 0;
    }

    int left = 0;
    int right = 1;
    int sum = primes[0];

    while (right <= m)
    {
        if (sum < n)
        {
            if (right == m)
                break;
            sum += primes[right++];
        }
        else if (sum > n)
        {
            sum -= primes[left++];
        }
        else
        {
            ans++;
            if (right == m)
                break;
            sum += primes[right++];
        }
    }

    cout << ans;
    return 0;
}
