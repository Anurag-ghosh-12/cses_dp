#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
void solve()
{
	int n;
	cin>>n;
// 	vector<int> dp(n+1,1e9);
// 	dp[0]=0;
// 	for(int i=1;i<=n;i++)
// 	{
// 		string a=to_string(i);
// 		for(char c:a){
// 			int digit=c-'0';
// 			if(digit!=0)
// 			{
// 				dp[i]=min(dp[i],dp[i-digit]+1);
// 			}
// 		}
// 	}
   // cout<<dp[n]<<endl;
   int problems=0;
   for(int i=0;i<n;i++)
   {
   	 int a,b,c;
   	 
     cin>>a>>b>>c;
     int count=0;
   
     if(a==1)
   	   count++;
     if(b==1)
   	  count++;
     if(c==1)
       count++;
     if(count>=2)
   	   problems++;
   }
   cout<<problems<<endl;
}
int main()
{
    solve();
    return 0;
}