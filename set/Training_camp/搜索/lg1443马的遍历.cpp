#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
typedef struct pos
{
	int x,y;
}pos;
//用于对应的八个方位访问 
int dx[8] = {-2, -2, 2, 2, 1, -1, 1, -1};
int dy[8] = {-1, 1, -1, 1, 2, -2, -2, 2};
int main()
{
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	int ans[404][405];//bfs步数数组 
	//初始化-1
	for (int i= 1; i<=n;i++) 
	{
		for (int j= 1;j<=m; j++)
		{
			ans[i][j] = -1;
		}
	}
	ans[x][y] = 0;//马所在位置，即起点
	queue<pos> q;
	pos now;
	now.x = x;
	now.y = y;
	q.push(now);
	//int idx = 0;
	while (q.empty() == 0)
	{
		//idx++;
		now = q.front();//队首，先进先出
		q.pop();
		for (int i = 0; i<8; i++) 
		{//八个访问:不越界 &&没有被访问过（==-1） 
			pos next;
			next.x = now.x + dx[i];
			next.y = now.y + dy[i];
			 if (next.x>=1 && next.x<=n && next.y<=m && next.y>=1 && ans[next.x][next.y] == -1)
			 {
			 	ans[next.x][next.y] = ans[now.x][now.y] + 1;//更新
				q.push(next);//将该层位置入队 
			 	
			 }
		}
	}
	for (int i= 1; i<=n;i++) 
	{
		for (int j= 1;j<=m; j++)
		{
			printf("%-5d", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
