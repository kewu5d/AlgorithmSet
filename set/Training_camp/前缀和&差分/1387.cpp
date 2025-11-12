//读入矩阵，二维数组存，从1下标开始存。从1，1开始遍历，增大最大变长。
//正方形区间前缀和==变长^2。取max。其中边长max（n, m） 

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
//int x1, y1;//正方形的左上角边，右下角（x1+ans, y1+ans），ans就是最大边长
//**全局变量不宜作循环变量
int a[105][105];	//array subscript数组下标a[] []不能有空格
int sum[105][105];
int main()
{
	int n, m;cin >> n>> m;//n行m列 
	int ans = 0, flag = 0;
	for (int i=1; i<= n; i++)
	for (int j= 1;j <=m; j++)	
	{
		cin >> a[i][j];
		if (a[i][j] == 1)flag = 1;//边长至少为1 
	}
	//特殊情况--0阵 
	if (flag == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	//前缀和数组
	for (int i=1; i <= n; i++)
	for (int j= 1;j <=m; j++)
	{
		sum[i][j] = sum[i][j-1] + sum[i-1][j] + a[i][j] - sum[i-1][j-1];
	}
	//**倒着枚举**右下角x1+ans, y1+ans 
	//通过右下角-左上角的前缀和区间均为1，判断ans的合法性
	ans = min(n, m);
	while (ans >=1)
	{
		int t = ans-1;//x1+t长度为边长ans
		for (int x1 = 1; x1+t <=n; x1++)
		{
			for (int y1 = 1; y1+t <=m; y1++)
			{
				int x = sum[x1+t][y1+t] - sum[x1+t][y1-1] - sum[x1-1][y1+t] + sum[x1-1][y1-1];
				//cout << x << ' '; 
				if (x == ans*ans)
				{
					cout << ans << endl;
					return 0;//倒着枚举的好处！
				}
			}
		}
		ans--;
	}
	return 0;
}
/*
4 4
0 1 1 1
1 1 1 0
0 1 1 0
1 1 0 1

*/
