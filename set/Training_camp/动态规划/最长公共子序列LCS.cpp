#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int dp[1005][1005];
string t1, t2;
int main()
{
	cin >> t1 >> t2;
	t1 = 'A' + t1;//注意'A' 放前面，占据下标0 
	t2 = 'A' + t2;//将有效子串下标从1开始，结尾仍为size-1
	for (int i=1; i<=t1.size()-1; i++)
	{
		for (int j=1; j<=t2.size()-1; j++)
		{
			if(t1[i] == t2[j])
			{
				dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
			}
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	cout << dp[t1.size()-1][t2.size()-1] << endl;
	return 0; 
}
