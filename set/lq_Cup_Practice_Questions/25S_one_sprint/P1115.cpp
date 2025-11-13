#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 2e5+10;
ll dp[N], a[N];//dp[i]：表示以a[i] 结尾的最大字段和 
int main()
{
	int n; cin >> n;
	for (int i=1; i<=n;i++)cin >> a[i];
	dp[0] = -1e18;
	ll ans = -1e18;
	for (int i=1; i<=n; i++)
	{
		if (dp[i-1] + a[i] > a[i])
		{//上升了 
			dp[i] = dp[i-1]+a[i];
		}
		else dp[i] = a[i];
		
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}
