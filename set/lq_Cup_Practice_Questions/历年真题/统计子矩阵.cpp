#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, k;
ll a[505][505], suma[505][505];
ll ans;
int main()
{
	cin>>n >> m >> k;
	for (int i=1; i<=n; i++) 
	{
		for (int j=1; j<=m; j++)cin >> a[i][j];
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
			suma[i][j] = suma[i][j-1] + suma[i-1][j] - suma[i-1][j-1] + a[i][j];
	}
	//±©Á¦ÊÔÊÔ
	for (int x1=1; x1 <=n; x1++) 
	{
		for (int y1 = 1; y1<=m; y1++)
		{
			for (int x2=x1; x2 <=n; x2++) 
			{
				for (int y2 = y1; y2<=m; y2++)
				{
					ll t = suma[x2][y2] - suma[x2][y1-1] - suma[x1-1][y2] + suma[x1-1][y1-1];
					if (t <=k)ans++;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
