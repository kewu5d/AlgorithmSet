#include <bits/stdc++.h>
using namespace std;
int n, t;//t为背包
double price;
struct a
{
	double m, v;
}ans[105];
//思路：对价值比排个序 
bool cmp(a x, a y)
{
	return x.v/x.m > y.v/y.m;//降序 
}
int main()
{
	cin >> n >> t;
	for (int i=1; i<=n; i++)
	{
		cin >> ans[i].m >> ans[i].v;
	}
	//按价值比排个序 
	sort(ans+1, ans + n+1, cmp);
	int i=1;
	while (t != 0 && i <= n) 
	{
		if (t >= ans[i].m)
		{
			price += ans[i].v;
			t -= ans[i].m;
		}
		else
		{
			
			price += ans[i].v / ans[i].m * t;
			t = 0;
		}
		i++;
	}
	//cout << price << endl;
	printf ("%.2f", price);
	return 0;
}
