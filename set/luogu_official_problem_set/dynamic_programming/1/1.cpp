#include <iostream>
#define ll long long //当事先考虑暴力dfs时，值很大就要开long long 
using namespace std;
//f(n, m) = f(n-1, m) + f(n, m-1);状态转移方程 
//如果该位置有马及攻击范围，f(,)=0 
int n, m;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int horse[21][21];//马及马的攻击位置 
ll f[21][21];//走到该位置的路径条数 
bool check(int a, int b)
{
	return horse[a][b]==1?false:true;
}
int main()
{
	cin >> n >> m;//终点 
	int x,y;cin >>x>>y;horse[x][y] = 1;
	for(int i=0; i<8; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx <=20 && xx >=0 && yy <=20 && yy >=0)
			horse[xx][yy] = 1;//防越界 
	}
	if (horse[0][0] || horse[n][m]){
		cout << 0 << endl;return 0;
	}
	//初始化起点 
	f[0][0] = 1;//为了让f[0][1]=f[1][0]=1; 
	for (int i=0; i<=n; i++)
	{
		for (int j=0; j<=m; j++)
		{
			if (i==0&&j==0)continue;
			if (check(i, j))
			{//防越界 
				//if (i-1 <0 && j-1<0)f[i][j] = 0;//只有起点满足这个，起点已经初始化，故跳过 
				if (i-1 <0 && j-1>=0)f[i][j] = f[i][j-1];
				else if (i-1 >=0 && j-1<0)f[i][j] = f[i-1][j];
				else f[i][j] = f[i-1][j] + f[i][j-1];
			}
			else f[i][j] = 0;//i，j为马及攻击范围，走不通，方式数更新为0 
		}
	}
	cout << f[n][m] << endl;
	return 0;
}
