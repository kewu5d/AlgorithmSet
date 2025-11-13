#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e5+5;
int a[N], b[N];
int main()
{
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> a[i];//1下标开始存
	for (int i = 1; i <= m; i++)cin >> b[i];
	int ai=1, bi=1;
	int ans=0; //操作数
	int asum = a[1], bsum =b[1];
	while (ai <=n && bi <=m) 
	{
		if (asum == bsum ) 
		{
			ai++;bi++;//都移动下一位 
			asum += a[ai];
			bsum += b[bi];
		}
		else if (asum < bsum)
		{
			ans++;
			asum += a[++ai];//前置++，ai后移 
		}
		else if (asum > bsum)
		{
			ans++;//合并操作+1 
			bsum += b[++bi];
		}
	}
	cout << ans << endl;
	return 0;
}
