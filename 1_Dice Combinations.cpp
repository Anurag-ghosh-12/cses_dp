// Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and  6.
// For example, if n=3, there are 4 ways:

// 1+1+1
// 1+2
// 2+1
// 3
#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1);

    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (j <= i)
            {
                // transition
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }

    // final subproblem
    cout << dp[n] << endl;
}

int main()
{
    solve();
}