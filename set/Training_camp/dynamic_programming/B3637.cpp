#include <iostream>
#include <algorithm>
using namespace std;
int dp[5005], a[5005], n;
int main()
{
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> a[i];dp[i] = 1;
	}
	//初始化状态数组 
//	for (int i=1; i<=5000; i++)dp[i] = 1;//自身长度就是 个上升子序列
	for (int i=1; i<=n; i++) 
	{
//		int maxlen = 0;
//		for (int j=1; j<i; j++)
//		{
//			if (a[j] < a[i]) maxlen = max(maxlen, dp[j]);
//		}
//		dp[i] += maxlen;
		for (int j=1; j<i; j++)
		{
			if (a[j] < a[i]) dp[i] = max(dp[i], dp[j]+1);
		}
	}
	int ans = 0;
	for (int i=1;i<=n;i++)dp[i]>ans?ans=dp[i]:0;
	cout << ans << endl;
	return 0;
}
