#include<iostream>
using namespace std;
long long int count_no_of_binary_string(int n,  long long int *dp)
{
	if(dp[n]!= 0)
		return dp[n];
	else if(n<=0)
		return 0;
	else if(n==1)
		return 2;
	else if(n==2)
		return 3;
	else
		return dp[n]= count_no_of_binary_string(n-1, dp) +count_no_of_binary_string(n-2, dp);
}
int main() {
	int t, n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		//int *dp =new int[n+1];
		long long int dp[n+1] ={0};
		cout<<count_no_of_binary_string(n, dp)<<endl;
		//delete []dp;
	}
	return 0;
}
