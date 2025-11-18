#include <iostream>
#include <algorithm>
using namespace std;
int r, c, maxlen, note[105][105];//备忘录初始化全0,没有记 
int zone[105][105];//区域 
int dx[4] = {-1, 1, 0, 0 };//上下左右 
int dy[4] = {0, 0, -1, 1};
int dfs(int x, int y)
{
	if (note[x][y]!=0)return note[x][y];
	int res = 1;//待返回结果----如果都不能滑动，自身也是一个长度 
	int xx, yy;
	for (int i=0; i<4; i++)
	{
		xx = x+dx[i];
		yy = y+dy[i];
		if (xx>0 && xx<=r && yy>0 && yy <=c && zone[x][y] > zone[xx][yy])
		{//不越界，并且高度更低 
			res = max(res, dfs(xx, yy)+1);
			//dfs最终返回结果就是以下一个点为起点能滑的最长滑坡距离。
			//这里+1表示：当前点滑动过去，结果就是当前点为起点的最长滑坡长度 
		}
	}
	note[x][y] = res;
	return res;
}
int main()
{
	cin >> r >> c;
	for (int i=1; i<=r; i++)
	{
		for (int j=1; j<=c; j++)
		{
			cin >> zone[i][j];
		}
	}
	for (int i=1; i<=r; i++)
	{
		for (int j=1; j<=c; j++)
		{
			maxlen = max(maxlen, dfs(i, j));
		}
	}
	cout << maxlen << endl;
	return 0;
}
