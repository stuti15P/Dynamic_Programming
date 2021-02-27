#include<iostream>
#include<climits>

using namespace std;

int minmMulReq[4][4] ={0};
int matrixChainMul(int p[], int i, int j)
{
	if(i== j)
		return 0;
	if(minmMulReq[j-i][i-1] !=0)
		return minmMulReq[j-i][i-1];
	int min = LONG_MAX;
	cout<<"i, j, min"<<endl;
	cout<<i<<" "<<j<<" "<<min<<endl;
	for(int k= i; k<j; k++)
	{
		int count1 = matrixChainMul(p, i, k) ;
		int count2 = matrixChainMul(p, k+1, j);
		int count3 = p[i-1]* p[k]* p[j];
		int count =count1 +count2+count3;
		if(count < min)
			min = count;
	}
	return minmMulReq[j-i][i-1] =min;
}

int main()
{
	int arr[] ={1, 2, 3, 4, 3};
	int n= sizeof(arr)/sizeof(arr[0]);
	cout<<"Minm multiplication needed to multiply these "<<n-1<<" matrices = "<<matrixChainMul(arr, 1, n-1);
	
}
