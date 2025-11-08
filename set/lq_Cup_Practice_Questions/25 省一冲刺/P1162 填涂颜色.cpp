#include <iostream>
using namespace std;

int mat[35][35], flag[35][35], n;
int dx[4] = {0, 1, 0, -1};//右下左上 
int dy[4] = {1, 0, -1, 0};
void bfs(int x, int y) 
{
	if (mat[x][y] == 0 && flag[x][y] == 0)
	{//没有被搜索过 
		flag[x][y] = 1;//外部0
	}
	else if(mat[x][y] == 1 || flag[x][y]==1)return;//及时返回。当搜到了1或者已经搜过了 
	for (int i=0; i<4; i++)
	{
		int xx = x+dx[i];
		int yy = y+dy[i];
		if (xx >=0 && xx<=n+1 && yy>=0 && yy<=n+1)
			bfs(xx, yy);
	}
}
int main()
{
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			cin >> mat[i][j];
		}
	}
	bfs(0, 0);
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			if (flag[i][j] == 1)cout << 0 << ' ';
			else if (mat[i][j] == 1)cout << 1 << ' ';
			else cout << 2 << ' ';
		}
		cout << endl;
	}
	return 0;
 } 







/*
//错误思路：就是dfs每个0点，找不到边界就标记上，最后输出2 
int mat[31][31], n, flag[31][31];//标记为1，需要染色最后输出2，其他原样输出
int dx[] = {-1, 0, 1, 0};//上右下左 
int dy[] = {0, 1, 0, -1};//0~3下标  
int color;//1表示不要染，这个0没有在闭合圈内
void dfs(int x, int y) 
{
	if (x<1 || x>n || y<1 || y>n)
	{//找到边界--不打标记 
		color = 1; 
		return; 
	}
	if (mat[x][y] == 1)
	{//找到了墙壁
		return;
	}
	for (int i=0; i<4; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		dfs(xx, yy);
		if (color == 1)break;
	}
	if (color == 0)flag[x][y] = 1;
}
int main()
{
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			cin >> mat[i][j];
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			color = 0;
			dfs(i, j);
		}
	}
	//输出 
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			if (flag[i][j])cout << 2 << ' ';
			else cout << mat[i][j] << ' ';
		}
		cout << '\n';
		
	}
	return 0;
}*/
