#include <iostream>
#include <cstdio>
using namespace std;
//求区间和 --二维
//正方形面积 等于 区间和 
int n, m;
int a[105][105];
int suma[105][105];
int flag;	//因为该矩阵有可能全为0 
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
	{
		cin >> a[i][j];
		//排除0阵
		if (a[i][j] == 1)
		{
			flag = 1;
		}
	}
	//求suma
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			suma[i][j] = suma[i-1][j] + suma[i][j-1] - suma[i-1][j-1] + a[i][j];
		}
	}
	int ans, r;	//答案和边长 
	if (flag == 0){
		//说明为0阵
		cout << 0 << endl;
		return 0;
	}
	ans = 1;//至少是1
	//枚举区间正方形和的右下角
	//枚举边长
	r = 2;//从2开始
	int x;
	while (r <= min(n, m))
	{//最左边的一个正方形，右下角就是[r][r] 
		for (int i = r; i <= n; i++)
		{
			for (int j = r; j <= m; j++)
			{
				x = suma[i][j] - suma[i][j-r] - suma[i-r][j] + suma[i-r][j-r];
				if (x == r * r)
				{
					ans = max(ans, r);
				}
			}
		}
		r++;
	}
	cout << ans << endl;
	return 0;
}
