#include <cstdio>
#include <iostream>
using namespace std;
int a[1005][1005];	//坐标格 (差分标记数组)
int suma[1005][1005];	//差分标记前缀和suma数组 
int main()
{
	int n, m;
	cin >> n >> m;
	int x1, y1, x2, y2;
	for (int i = 1; i <= m; i++) 
	{
		cin >> x1 >> y1 >> x2 >> y2;
		a[x1][y1] += 1;
		a[x1][y2+1] += -1;
		a[x2+1][y1] += -1;
		a[x2+1][y2+1] += 1;
	}
	//求差分标记前缀和suma数组 
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			suma[i][j] = suma[i][j-1] + suma[i-1][j] + a[i][j] - suma[i-1][j-1];
			cout << suma[i][j] << ' ';
		}
		cout << endl;
	}
	
	return 0;
}
