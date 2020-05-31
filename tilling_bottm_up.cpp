#include<iostream>

using namespace std;
int count_no_of_way_to_tile(int n, int m)
{
	int dp[n+1] ={0};
	dp[1] =1;
	if(dp[n]!=0)
		return dp[n];
	else
	{
		for(int i=2; i<=n; i++)
		{
			if(i ==m)
				dp[i] =2;
			else if(i<m)
				dp[i] =1;
			else
				dp[i]= (dp[i-1] + dp[i-m])%1000000007;
		}
	}
	return dp[n];
	
}
int main() {
	int t, n, m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		cout<<count_no_of_way_to_tile(n, m)<<endl;
	}
	return 0;
}
