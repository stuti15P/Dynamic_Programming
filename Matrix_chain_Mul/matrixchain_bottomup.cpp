#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;
//int n=5;
void printParenthesis(int i, int j, int n, int* bracket,
                      char& name)
{
    // If only one matrix left in current segment
    if (i == j) {
        cout << name++;
        return;
    }
 
    cout << "(";
 
    // Recursively put brackets around subexpression
    // from i to bracket[i][j].
    // Note that "*((bracket+i*n)+j)" is similar to
    // bracket[i][j]
    printParenthesis(i, *((bracket + i * n) + j), n,
                     bracket, name);
 
    // Recursively put brackets around subexpression
    // from bracket[i][j] + 1 to j.
    printParenthesis(*((bracket + i * n) + j) + 1, j, n,
                     bracket, name);
    cout << ")";
}



int matrixChainMulTabulation(int p[], int n)
{
	cout<<"n "<<n<<endl;
	unsigned int dp[5][5];
	int matrixOrder[5][5];
	for(int i=1; i<n; i++)
	{
		dp[i][i] =0;
	}
	for(int m =2; m<=n-1; m++)    // starting from all  2 -size matrix we multiply  4 size matrices. 
	//bcoz from arr 2nd index ie.. 1 in(0,1...) index, partition will be done.
	{
		for(int i =1; i<=n-m; i++)
		{
			int j= i+m-1;
			dp[i][j] = INT_MAX;
			for(int k =i; k<j; k++)
			{
				if(dp[i][j] > dp[i][k] + dp[k+1][j] +p[i-1] *p[k] *p[j])
				{
					dp[i][j] = (dp[i][j], dp[i][k] + dp[k+1][j] +p[i-1] *p[k] *p[j]);
					matrixOrder[i][j] =k;
				}
			}
			
		}
	} 
	cout<<endl<<"Matrix Representation \n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
	////////////////////////////////////////////////////////////
	char name = 'A';
 
    cout << "Optimal Parenthesization is : ";
    printParenthesis(1, n - 1, n, (int*)matrixOrder, name);
	cout<<endl<<"cost is \n";
	return dp[1][n-1];
}

int main()
{
	int arr[] = {1, 2, 3, 4, 3};
	//int arr[] = {10,5,20,10,5};
	int n = sizeof(arr)/ sizeof(int);
	cout<<matrixChainMulTabulation(arr, n);
	
	
}
