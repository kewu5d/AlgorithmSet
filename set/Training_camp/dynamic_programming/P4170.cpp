#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
string str;
int dp[55][55];
int main()
{
	cin >> str;
	memset(dp, 0x3f, sizeof(dp));
	str = '0' + str;//1下标开始存
	for (int i=1; i<=str.size()-1; i++) dp[i][i] = 1;
	for (int len=2; len<str.size(); len++)
	{
		for (int i=1; i+len-1<str.size(); i++)
		{
			int j = i+len-1;
			for (int k=i; k<j; k++)
			{
				if (str[i] == str[j])
					dp[i][j] = min(dp[i+1][j], dp[i][j-1]);
				else
					dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]);
			}
		}
	}
	cout << dp[1][str.size()-1] << endl;
	return 0;
}
