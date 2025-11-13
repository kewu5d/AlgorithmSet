#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[305][305];
int m[305], sum[305];//前缀和优化 
int main()
{
	int n; cin >> n;
	memset(dp, 0x3f, sizeof(dp));
	for (int i=1; i<=n; i++)
	{
		cin >> m[i];
		sum[i] = sum[i-1] + m[i];
		//初始化 
		dp[i][i] = 0;
		//i==1?0:dp[i-1][i] = m[i]+m[i-1];
	}
//	if (n == 1)
//	{
//		cout << 0 << endl;return 0;
//	}
	for (int len = 2; len<=n; len++)
	{//枚举由两小区间合并而来的较大区间长度 
		for (int i=1; i+len-1<=n; i++)
		{//枚举较大区间的左端点 
			int j = i+len-1;//右端点
			for (int k=i; k<j; k++) 
			{//枚举合并点 
				int cost = sum[j] - sum[i-1];
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + cost);
			}
		}
	}
	cout << dp[1][n] << endl;
	return 0;
}
