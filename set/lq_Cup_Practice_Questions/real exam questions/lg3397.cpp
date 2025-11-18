#include  <iostream>
#include <cstdio>
using namespace std;
int b[1005][1005], sumb[1005][1005];//输出最后的suma数组 
int x1,y1,x2,y2;
int main()
{
	int n, m;//n^n格子，m个摊子
	cin >> n >> m;//下标从1开始
	while (m--)
	{
		cin >> x1 >>y1 >> x2 >> y2;
		//容斥 
		b[x1][y1]++;b[x1][y2+1]--;b[x2+1][y1]--;b[x2+1][y2+1]++;
		
	}
	//最后求sumb-----不是求区间和 
	for(int i = 1;i<=n;i++) 
	for (int j= 1;j<=n;j++)
	{
		sumb[i][j] = sumb[i-1][j]+sumb[i][j-1] - sumb[i-1][j-1]+b[i][j];
	}
	//输出sumb
	for(int i = 1;i<=n;i++) 
	{
		for (int j= 1;j<=n;j++)
		{
			cout << sumb[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
