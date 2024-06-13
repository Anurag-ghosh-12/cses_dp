
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int bottomup(int curr,int prev,vector<int> &arr,vector<vector<int>> &dp)
{
   if(curr>=arr.size())
   {
   	return 0;//LIS of 0 length possible
   }
   if(dp[curr][prev+1]!=-1)
   {
   	return dp[curr][prev];
   }
   int take=0;
   if(prev==-1|| arr[prev]<arr[curr])
   {
   	take=1+bottomup(curr+1,curr,arr,dp);
   }
   int skip=bottomup(curr+1,prev,arr,dp);
   return dp[curr][prev+1]=max(take,skip);
}

int topdown(vector<int> &arr,int n)
{
   vector<int> t(n,1);
   int maxlen=1;
   for(int i=0;i<n;i++)
   {
   	for(int j=0;j<i;j++)
   	{
   		if(arr[j]<arr[i])
   		{
   			t[i]=max(t[i],1+t[j]);
   			maxlen=max(maxlen,t[i]);
   		}
   	}
   }
   return maxlen;
}
//DP + BINARY SEARCH
int optimal(vector<int> &a,int n)
{
	if(n==0)
		return 0;
	vector<int> ans;
	ans.push_back(a[0]);
	for(int i=1;i<n;i++)
	{
		if(a[i]>ans.back())
		{
			ans.push_back(a[i]);
		}
		else
		{
			int ind=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
			ans[ind]=a[i];
		}
	}
	return ans.size();
}
int main()
{
	int t=3;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}

		vector< vector <int> > dp(n,vector<int>(n+1,-1) );
		int res=optimal(arr,n);
        cout<<res<<endl;
      
	}
	return 0;
}
