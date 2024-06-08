/*Consider a money system consisting of n coins. 
Each coin has a positive integer value.
 Your task is to calculate the number of distinct ordered ways 
 you can produce a money sum x using the available coins.
*/
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
void solve()
{
	int n,x;
	cin>>n>>x;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	vector<vector<int>> dp(n+1,vector<int>(x+1));

	for(int i=0;i<n;i++)
	{
		dp[i][0]=1;//base case
	}
	for(int i=n-1;i>=0;i--)
	{
       for(int sum=1;sum<=x;sum++)
       {
       	int skipped=dp[i+1][sum];
       	int picked=0;
       	if(a[i]<=sum)
       	{
       		picked=dp[i][sum-a[i]];
       	}
       	dp[i][sum]=(skipped+picked)%MOD;
      }

	}
   cout<<dp[0][x]<<endl;
}
int main()
{
    solve();
    return 0;
}