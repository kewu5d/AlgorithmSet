#include <iostream>
using namespace std;
const int N = 2e5+5; 
int a[N] , temp[N];//这里的a，temp数组都可以改用变量，来进行空间优化 
int main()
{
	int n;cin >> n;
	int ans= -1e8;
	for (int i=1;i<=n; i++)
	{
		cin >> a[i];
		if (i == 1)temp[i] = a[i];//可能的最大字段和
		else
		{
			temp[i] = max(temp[i-1]+a[i], a[i]);//原区间加上新元素后比新元素还小，就让新元素成一个新区间 
			ans = max (ans, temp[i]);
		 } 
	}
	cout << ans << endl;
	return 0;
}
