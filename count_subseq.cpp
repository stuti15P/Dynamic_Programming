#include<iostream>
#include<cstring>
#include<unordered_map>

using namespace std;

int count_subsequence(string str)
{
	unordered_map<char, int> char_map;
	int len = str.length();
	int dp[len+1];
	dp[0] =1;
	
	for(int i=0; i<len; i++)
	{
		dp[i+1] = 2*dp[i];
		
		if(char_map.find(str[i]) != char_map.end())
		{
			int pos =char_map[str[i]];
			dp[i+1] -= dp[pos-1];
		}
		char_map[str[i]] =i+1;
	}
	
	return dp[len];
}

int main()
{
	string str = "ABBB";
	cout<<"No of distict subsequence is \n";
	cout<<count_subsequence(str);
}
