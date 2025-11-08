#include <iostream> 
#include <cstdio>
using namespace std;
int n;	
int a[100005];
int suma[100005];
int ans[100005];
int m;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	cin >> m;
	//a数组的前缀和

	for (int i = 1; i <= n; i++)
	{
		suma[i] = suma[i-1] + a[i];
	}
	//边输入左右区间，边计算 
	int l, r; 
	for (int i = 1; i <= m; i++)
	{
		cin >> l >> r;
		ans[i] = suma[r] - suma[l - 1];
	}
	//输出
	for(int i = 1; i <= m; i++) 
	{
		cout << ans[i] << "\n";
	} 
	
	
	
	
	return 0;
}
