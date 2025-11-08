#include <iostream>
using namespace std;
//dp[i]：以i开始所挖到的最多地雷数 
int n, dp[21];
int link[21][21];//i到j是否连通,1：连通 
int lei[21], nexti[21];
int main()
{
	cin >> n;
	for (int i=1; i<=n; i++)cin >> lei[i];
	for (int i=1; i<n; i++)
	{
		for (int j=i+1; j<=n; j++)
		{
			cin >> link[i][j];
		}
	}
	dp[n] = lei[n];
	int ansi = n;
	for (int i=n-1; i>=1; i--)
	{//枚举开始挖的节点 
		dp[i] = lei[i];
		for (int j=i+1; j<=n; j++)
		{//枚举i节点之后所有可能行进的节点 
			if (link[i][j] == 1 && dp[i]<lei[i] + dp[j])
			{//(有多个就选最优的)走过去 
				dp[i] = lei[i] + dp[j];
				nexti[i] = j;
			}
		}
		if (dp[i] > dp[ansi])ansi = i;//找最优开始点 
	}
	int ti = ansi;
	while (ti != 0)
	{//打印路径 
		cout << ti << ' ';
		ti = nexti[ti];
	}
	cout << '\n';
	cout << dp[ansi] << endl;
	return 0;
}
