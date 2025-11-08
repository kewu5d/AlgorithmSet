#include <bits/stdc++.h>
using namespace std;
int n, k, desk[13][13], vis[13][13];//还不能交叉 
vector<int> ans;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = { 0,  1, 1, 1, 0, -1,-1,-1};
int cnt;//存在多条路劲，只打印字典序最小的一条 
int flag;//输出-1 
void print()
{
	for (int i=0; i<ans.size(); i++)cout << ans[i];
	cout << endl;
}
bool check(int i, int x, int y)
{//这种判断方式欠妥 
	int t1, t2;
	if (i == 1)
	{
		if (vis[x-1][y] == 1 && vis[x][y+1] == 1)
		{
			//反方向，判断是否有绕行 ---好像不靠谱 
			t1 = x; t2 = y;
			while (t1); 
			return false;
		}
	}
	else if (i==3)
	{
		if (vis[x+1][y] == 1 && vis[x][y+1] == 1)return false;
	}
	else if(i == 5)
	{
		if (vis[x+1][y] == 1 && vis[x][y-1] == 1)return false;
	}
	else if (i == 7)
	{
		if (vis[x][y-1] == 1 && vis[x-1][y] == 1)return false;
	}
	return true;
}
void dfs(int x, int y, int s)
{
	if (x == n-1 && y == n-1)
	{
		if (ans.size() != n*n-1)
		{//没有遍历一遍 
			return; 
		}
		cnt++;
		//if (cnt <=1) print();
		print(); 
		flag =1; 
		return;
	}
	//0~7八个方向 
	for (int i=0; i<8; i++) //字典序 
	{
		int xi = x + dx[i];
		int yi = y + dy[i];
		if (xi<0 || xi >=n || yi <0 || yi >= n)continue;
		if (vis[xi][yi] == 1)continue;
		if (desk[xi][yi] != (s+1)%k)continue;
		if (i==1 || i==3 ||i==5 || i==7)
		{
			if (!check(i, x, y))continue;	//或者整个四维数组vis2[x1][y1][x2][y2],是否又从x1，y1来往过x2，y2 
		}
		//else
		vis[xi][yi] = 1;
		ans.push_back(i);
		dfs(xi, yi, s+1);	
		if (cnt == 1)return;//可以利用cnt进行剪枝 ------其实也可以直接用flag剪枝，少一个cnt变量 
		//huisu
		vis[xi][yi] = 0;
		ans.pop_back();
	}
	//走不通
	return; 
}
int main()
{
	cin>>n >> k;
	for (int i=0; i<n;i++)
	{
		for (int j=0; j<n; j++)
			cin >> desk[i][j];	
	}
	int step = 0;
	vis[0][0] = 1;
	dfs(0, 0, step);//深搜位置，步数（对k取余） 
	if (flag == 0)cout << -1 << endl;
	return 0;
}
/*
4 3
0 0 1 2
1 2 0 0
2 1 2 1
0 1 2 0
420224460564222
*/
