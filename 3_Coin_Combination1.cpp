/*Given amount and coin denominations return minimum number of coins
to achieve amount, assume infinite supply of coins*/
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
void solve()
{
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	vector<int> dp(x + 1, 0);
	dp[0] = 1;
	int mini;
	for (int i = 1; i <= x; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[j] <= i)
			{
				dp[i] = (dp[i] + dp[i - a[j]]) % MOD;
			}
		}
	}
	cout << dp[x] << endl;
}
int main()
{
	solve();
	return 0;
}