#include <iostream>
#include <algorithm>
using namespace std;

int vis[10][10], a[10][10];//每个灯只能按一次 
int ans = 10;//初始化为10，因为最多不会超过10次 
int dx[5]= {0,-1, 1, 0, 0}, dy[5] = {0, 0, 0, -1, 1};
bool check()
{
	for (int i=1; i<=3; i++) 
	{
		for (int j=1; j<=3; j++)
		{
			if (a[i][j] == 0)return false;
		}
	}
	return true;
}
void change(int x, int y)
{
	for (int i=0; i<5; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];//xx,yy不会越界 
		a[xx][yy] = 1 - a[xx][yy];//1-0=1,1-1=1,实现了反转 
	}
}
void dfs(int step) 
{
	//if(step > ans) return;//剪枝 
	if (check())
	{//每次都检查一下是否达111111111 
		ans = min(ans, step);
	}
	//暴力深搜，访问所有可能，但只能访问一次 
	for (int i=1; i<=3; i++) 
	{
		for (int j=1; j<=3; j++)
		{
			if(vis[i][j] == 0) 
			{
				vis[i][j] = 1;
				change(i, j);//改变自己的灯和周围灯的状态
				dfs(step+1) ;
				vis[i][j] = 0;
				change(i, j);//在改变一次就还原了 
			}
		}
	}
	
}
int main()
{
	for (int i=1; i<=3; i++) 
	{
		for (int j=1; j<=3; j++)
		{
			cin >> a[i][j];
		}
	}
	
	
	dfs(0);//深搜步数 
	
	
	
	cout << ans << endl; 
	return 0;
}
