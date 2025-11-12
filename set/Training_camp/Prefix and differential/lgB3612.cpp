#include <iostream> 
#include <cstdio>
using namespace std;
int n;	
int a[100005];
int suma[100005];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		suma[i] = suma[i-1] + a[i];//a数组的前缀和
	}
	//边输入左右区间，边计算 
	int m;cin >> m;
	int l, r; 
	for (int i = 1; i <= m; i++)
	{
		cin >> l >> r;
		cout << suma[r] - suma[l - 1] << endl;
	}
	
	return 0;

	//优化点：两个数组改用一个数组--自前缀数组
}
