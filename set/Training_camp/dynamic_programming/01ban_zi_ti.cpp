#include <iostream>
using namespace std;
int t, m;//t±³°ü£¬mÖÖÀà
long long dp[10000005];
int w[10005], v[10005];
int main()
{
	cin >> t >> m;
	for (int i=1; i<=m; i++)cin >> w[i] >> v[i];
	for (int i=1; i<=m; i++)
	{
		for (int j=w[i]; j<=t; j++)
		{
			dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
		}
	}
	cout << dp[t] << endl;
	return 0;
}
