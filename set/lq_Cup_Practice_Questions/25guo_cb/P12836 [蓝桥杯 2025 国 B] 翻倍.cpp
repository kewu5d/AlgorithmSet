#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10;
ll n, a[N];
ll dp[N];//以a[n]结尾的翻倍次数 
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i];
	}
	ll ans = 0;
	for (int i = 0; i <= n; i++)
	{
		if (a[i] >= a[i-1])
		{
			dp[i] = dp[i-1] + ans;
			ans = 0;
		}
		else
		{
			a[i] *= 2;
			ans++;//操作一次 
			i--; 
		}
	}
	cout << dp[n] << '\n';
	return 0;
}
