#include <iostream>
using namespace std;

int r, c, k, ans;
char a[105][105];
void right(int x, int y)
{
	if (c - y +1 < k)return;
	int cnt = 1, i=y;
	while (cnt <=k)
	{
		if (a[x][i] == '#')return;
		cnt++;
		i++;
	}
	ans++;
}
void down(int x, int y)
{
	if (c - x +1 < k)return;
	int cnt = 1, i=x;
	while (cnt <=k)
	{
		if (a[i][y] == '#')return;
		cnt++;
		i++;
	}
	ans++;
}
int main()
{
	cin >> r >> c >> k;
	for (int i=1; i<=r; i++)
	{
		for (int j=1; j<=c; j++)
		{
			cin >> a[i][j];
		}
	}
	//枚举每一个点，往右往下是否能够排列 
	//注意当k=1时，往右往下站只算一种战法 
	if (k == 1)
	{
		for (int i=1; i<=r; i++)
		for (int j=1; j<=c; j++)
			if (a[i][j] == '.')ans++;
		cout << ans << endl;
		return 0;
	}
	
	
	for (int i=1; i<=r; i++)
	{
		for (int j=1; j<=c; j++)
		{
			right(i , j); 
			down(i, j);
		}
	}
	cout << ans << endl;
	return 0;
}
