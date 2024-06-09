/*in a grid can move in only right or down direction 
go from 0,0 to n,n cell such that the cost o path is minimum/ minimum path sum*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
void solve()
{
	int n;
	cin>>n;
	vector<vector<int>> grid(n,vector<int>(n));
	vector<vector<int>> dp(n,vector<int>(n));

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>> grid[i][j];
		}
	}
    dp[n-1][n-1]=grid[n-1][n-1];
	

	for(int i=n-1;i>=0;i--)
	{
		for(int j=n-1;j>=0;j--)
		{
			if(i==n-1 && j==n-1)
			{
				continue;
			}
			else
			{
				int ans=i<n-1?dp[i+1][j]:INT_MAX;
				int ans2=j<n-1?dp[i][j+1]:INT_MAX;
				dp[i][j]=min(ans,ans2)+grid[i][j];
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