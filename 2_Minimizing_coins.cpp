/*Given amount and coin denominations return minimum number of coins 
to achieve amount, assume infinite supply of coins*/
#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	vector<int> dp(x + 1,1e9);
	dp[0] = 0;
	int mini;
	for (int i = 1; i <= x; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[j]<=i)
			{
				dp[i] = min(dp[i],dp[i - a[j]]+1);
			}
		}
	}
	cout << ((dp[x]<1e9)? dp[x]: -1) << endl;
}
int main()
{
	solve();
	return 0;
}