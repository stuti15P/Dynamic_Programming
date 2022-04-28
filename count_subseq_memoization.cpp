#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

unordered_map<char, int> char_map;

int count_subseq(string str, int i)
{
	int len =str.length();
	int dp[len+1] ={0};
	int ans;
	//Doubt str[i] is string or char??
	if(i==0)
	{
		dp[i]= 1;
		return 1;
	}
	
	if(dp[i] != 0)
		return dp[i];
	
	if(char_map.find(str[i-1]) != char_map.end())
	{
		cout<<"i "<<i<<endl;
		int old_occur;
		old_occur = char_map[str[i-1]];
		cout<<"old_occur "<<old_occur<<endl;
		ans = 2* count_subseq(str, i-1) -dp[old_occur-1];
		char_map[str[i-1]] =i;
		return dp[i] =ans;
	}
	else
	{
		char_map[str[i-1]] =i;
		ans = 2*count_subseq(str, i-1);
		return dp[i] =ans;
	}
}

int main()
{
	string str ="ABCB";
	int len =str.length();
	cout<<count_subseq(str, len)<<endl;
	cout<<char_map['A']<<" "<<char_map['B']<<" "<<char_map['C']<<endl;
}
