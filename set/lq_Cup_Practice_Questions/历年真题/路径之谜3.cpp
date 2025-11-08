#include <iostream>
#include <vector>
using namespace std;
int row[21], col[21];//行，列靶子数 
vector<int> path;
int step;//总步数
int n, vis[21][21]; 
int dx[4] = {0, 1, 0, -1};//右下左上 
int dy[4] = {1, 0, -1, 0};
void print()
{
	for (int i=0;i<path.size();i++)cout << path[i] << ' ';
	cout << endl;
}
void dfs(int a, int b)
{
	//目标状态1.达到终点      2.达到步数step==0（还要在判断是否用尽步数到达的是终点） 
	//这么看来其实弄一个步数判断似乎是多余的，只要到达终点，***并且是按照规定的靶子数路径则为答案路径 ***
	if (step==0) 
	{
		if (a*n+b == n*n-1) 
		{//是终点 
//			for (int i=0;i<n;i++)
//			{
//				if(row[i] !=0 || col[i]!=0)return;//不合法 
//			}
			print();///////////////笔记
		}
		return; //路径唯一递归出口 
	}
	//以(a，b)为源点深搜
	for (int i=0;i<4;i++)
	{
		int x = a + dx[i];int y = b+dy[i];
		//(x,y)是否可以访问
		if (x<0 || x>=n || y<0||y>=n) continue;
		if (row[x]<0 || col[y]<0)continue;//访问到（x，y），必然会让行列靶子数都--
		if (vis[x][y] ==1)continue;
		//else
		vis[x][y] = 1;
		step--;row[x]--;col[y]--;
		path.push_back(x*n+y);
		dfs(x, y);
		//回溯
		vis[x][y] = 0;
		step++;row[x]++;col[y]++;
		path.pop_back();
	}
	
}
int main()
{
	cin >> n;
	for (int i=0;i<n;i++)cin>>col[i];//先列
	for (int i=0;i<n;i++) 
	{
		cin >> row[i];step += row[i];
	}
	//从入口开始搜 
	vis[0][0] = 1;
	row[0]--;col[0]--;step--;
	path.push_back(0);
	dfs(0,0);//0~n-1
	return 0;
}
