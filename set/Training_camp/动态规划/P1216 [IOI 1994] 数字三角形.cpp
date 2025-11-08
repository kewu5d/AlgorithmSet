#include <iostream>
#include <algorithm> 
using namespace std;
int r, dp[1005], last[1005]; //答案遍历找最值--dp，而不是贪心
//dp[i]：表示当前行到达第i个位置的最大权值 （由上至下） ----------可以去掉last数组，合为一个二维dp数组
//dp[i][j]：表示第i行第j个位置的最大权值 
int ans;
int main()
{
	cin >> r;
	int n = 1, t;
	while (r--)
	{
		for (int i=1; i<=n; i++)
		{
			cin >> t;
			dp[i] = max(t+last[i-1], t+last[i]);//比较i、i-1，使用+=也行 
		}
		for (int i=1;i<=n;i++)last[i] = dp[i];
		n++;
	}
	for (int i=1; i<n; i++)dp[i]>ans?ans = dp[i]:0;
	cout << ans << endl;
	return 0;
}
