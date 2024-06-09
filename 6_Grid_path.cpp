#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
void solve()
{
	int n;
	cin>>n;
	vector<vector<char>> grid(n,vector<char>(n));
	vector<vector<int>> dp(n,vector<int>(n));

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>> grid[i][j];
		}
	}
	if(grid[n-1][n-1]=='.')
	{
		dp[n-1][n-1]=1;
	}
	else
	{
		dp[n-1][n-1]=0;//no path possible
	}

	for(int i=n-1;i>=0;i--)
	{
		for(int j=n-1;j>=0;j--)
		{
			if(i==n-1 && j==n-1)
			{
				continue;
			}
			if(grid[i][j]=='*')
				dp[i][j]=0;//no path
			else
			{
				int ans=i<n-1?dp[i+1][j]:0;
				int ans2=j<n-1?dp[i][j+1]:0;
				dp[i][j]=(ans+ans2)%MOD;
			}
		}
	}
	cout<<dp[0][0]<<endl;
}
int main()
{
	solve();
	return 0;
}