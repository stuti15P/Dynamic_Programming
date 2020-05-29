//Given a floor of size n x m. Find the number of ways to tile the floor with tiles of size 1 x m . 
//A tile can either be placed horizontally or vertically.

//First line of input contains an integer T denoting the number of test cases. Then T test cases follow.

#include<iostream>
#define mod 1000000007
using namespace std;

int count_no_of_ways_to_tile(int n, int m, int dp[])
{
	if(dp[n]!= 0)
		return dp[n];
	else
	{
	if(n<=0 ||m<=0)
		return 0;
	else if(n<m)
		return 1;
	else if(n==m)
		return 2;
	else
		return dp[n]= (count_no_of_ways_to_tile(n-1, m, dp)%mod + count_no_of_ways_to_tile(n-m, m, dp)%mod)%mod;
	}
}
int main() {

	int t, n, m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		int *dp =new int[n+1]{0};
		//int dp[n+1] ={0};
		cout<<count_no_of_ways_to_tile(n,m,dp);
		cout<<endl;
		//delete []dp;
	}

	return 0;
}
