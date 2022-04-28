#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;
//int n=5;

int matrixChainMulTabulation(int p[], int n)
{
	cout<<"n "<<n<<endl;
	unsigned int dp[4][4];
	for(int i=0; i<n-1; i++)
	{
		dp[i][i] =0;
	}
	for(int m =2; m<=n-1; m++)    // starting from all  2 -size matrix we multiply  4 size matrices. 
	//bcoz from arr 2nd index ie.. 1 in(0,1...) index, partition will be done.
	{
		for(int i =0; i<n-m; i++)
		{
			int j= i+m-1;
			dp[i][j] = INT_MAX;
			for(int k =i; k<j; k++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] +p[i] *p[k+1] *p[j+1]);
		}
	} 
	cout<<endl<<"Matrix Representation \n";
	for(int i=0; i<n-1; i++)
	{
		for(int j=0; j<n-1; j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<"cost is \n";
	return dp[0][n-2];
}

int main()
{
	int arr[] = {1,2,3,4,3};
	int n = sizeof(arr)/ sizeof(int);
	cout<<matrixChainMulTabulation(arr, n);
	
	
}
