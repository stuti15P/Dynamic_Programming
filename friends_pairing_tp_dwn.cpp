#include<iostream>
using namespace std;

long long int friends_pairing_problem(int n ,long long int *dp)
{
	if(dp[n]!=0)
		return dp[n];
	else
	{
		if(n<=0)
			return 0;
		else if(n<=2)
			return dp[n] =n;
		else
			return dp[n] =friends_pairing_problem(n-1, dp) +((n-1)*friends_pairing_problem(n-2, dp));
	}
}
int main() {
	int t, n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long int dp[n+1] ={0};
		cout<<friends_pairing_problem(n, dp)<<endl;
	}
	return 0;
}
