#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m;
ll ans1, ans2;//分别为正方形，矩形，  矩-正即为长方形 
int main()
{
	scanf("%d %d", &n, &m);
	for( int i=1; i<=n; i++) 
	{
		for (int j=1; j<=m; j++)
		{//固定右下角，向左上方的其余格子延申 
			ans1 += min(i, j);
			ans2 += i * j;
		}
	}
	printf("%lld %lld", ans1, ans2-ans1);
	return 0;
}
