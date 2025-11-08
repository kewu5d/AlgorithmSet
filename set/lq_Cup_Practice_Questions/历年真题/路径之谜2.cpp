#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int n, x[21], y[21];//靶子
int visit[21][21];//位置是否访问，1访问过 
int dx[4] =	{0, 1, 0, -1};	
int dy[4] = {1, 0, -1, 0};	//右下左上 
int step;//总步数 
vector<int> ans;//答案路径 
void print()
{
	for (int i=0;i<ans.size();i++)cout << ans[i] << ' ';
	cout << endl;
}
void dfs(int i, int j)
{
	if (step == 0) 
	{
		if ((j-1)+(i-1)*n == n*n-1)//错误2：-------------没有检测靶子数是否耗尽(????step耗尽，难道？) 
		{
			for (int k=1;k<=n;k++) 
			{
				if (x[k]!=0 || y[k] != 0)return ;
			}
			print();
		}
		return;
	}
	//深搜右下左上？？？？ ---答：方向很有所谓---选择不当会TLE 
	for (int m=0;m <4;m++) 
	{
		//i+=dx[m];j+=dy[m];//错误1------直接修改了i，j,导致后续方向遍历时坐标混乱。 下一次循环的坐标已经是修改后的值，而非原始起点
		int xx=i+dx[m]; int yy = j+dy[m];
		if (visit[xx][yy] == 1) continue;			 //该方向已经访问过
		if (xx>n || xx<1 || yy>n || yy<1)  continue;//不合法方向 
		if (x[xx]<=0 || y[yy]<=0) continue;			//某个方向步数达到了限定 
		//否则去访问它 
		visit[xx][yy] = 1;
		x[xx]--;y[yy]--;
		step--;
		int t = (xx-1)+(yy-1)*n;
		ans.push_back(t); //二维转一维***** 
		dfs(xx, yy);
		//回溯
		visit[xx][yy] = 0;
		x[xx]++;y[yy]++;
		step++;
		ans.pop_back();
	}
}
int main()
{
	cin >>n;
	for (int i=1; i<=n; i++)
	{
		cin >> y[i];//1~n
		step += y[i];
	}
	for (int i=1;i<=n;i++)cin >> x[i];
	//起点出发
	visit[1][1]=1;x[1]--;y[1]--;step--;
	ans.push_back(0);
	dfs(1, 1);//以1，1为源点深搜 
	return 0; 
}
/*
4
2 4 3 4
4 3 3 3
*/
