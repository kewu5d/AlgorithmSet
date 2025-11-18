//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> col;//列 ---输出皇后放置的列数 
int vis[14][14];//放一个皇后，要改八个方向 ！！ 
int ans, n; 
void print()
{
	for (int i= 0; i<col.size(); i++)//cout << col[i]<< ' ';
		printf("%d ", col[i]);
	//cout << endl;
	printf("\n");
}
void attack(int r, int c)
{
	for (int i=1; i<=n ;i++)
	{
		vis[r][i] = 1;vis[i][c] = 1;
	}
	//左上
	int t1, t2;t1 = r;t2 = c;
	while (t1>0 && t2>0) {
		vis[t1--][t2--] = 1;
	}
	t1 = r;t2 = c;
	while (t1 <= n && t2 <= n){
		vis[t1++][t2++] = 1;
	}
	t1 = r;t2 = c;
	while (t1 >0 && t2 <= n)//youshang
	{
		vis[t1--][t2++] = 1;
	}
	t1 = r;t2 = c;
	while (t1 <= n && t2 >0){
		vis[t1++][t2--] = 1;
	}
}
void disattack(int r, int c){
}
//注意：之前皇后的位置不能干掉 
bool check(int r, int c)
{//该皇后攻击范围没有其他皇后
	for (int i=1; i<=n; i++)
	{
		if (vis[i][c] == 1)return false;
		if (vis[r][i] == 1)return false;
	}
	//左上
	int t1, t2;t1 = r;t2 = c;
	while (t1>0 && t2>0) {
		if (vis[t1--][t2--] == 1)return false;
	}
	t1 = r;t2 = c;
	while (t1 <= n && t2 <= n){
		if (vis[t1++][t2++] == 1)return false;
	}
	t1 = r;t2 = c;
	while (t1 >0 && t2 <= n)//youshang
	{
		if (vis[t1--][t2++] == 1)return false;
	}
	t1 = r;t2 = c;
	while (t1 <= n && t2 >0){
		if (vis[t1++][t2--] == 1)return false;
	}
	return true; 
}
void dfs(int q, int row) 
{
	if (q > n)//if (col.size() == n)皇后都放完了 
	{
		ans++;
		if (ans <= 3)print();
		return ;
	}
	//在第row行，放第q个皇后 
	for (int i=1; i<=n; i++)
	{
		if (vis[row][i] == 0&& check(row, i))
		{
			//放置
			//attack(row, i);
			vis[row][i] = 1;
			col.push_back(i);
			dfs(q+1, row+1);//下一行放下一个皇后 
			//disattack(row, i);//取消这个皇后 
			//之前放置的皇后的攻击范围保留 
			vis[row][i] = 0;
			col.pop_back();
		}
	}
}
int main()
{
	//cin >> n;
	scanf("%d", &n);
	dfs(1, 1);//放棋子（皇后） //漏了条件哈-------以某个皇后为中心，上下左右四斜都不能有其他皇后，不能相互攻击 
	//cout << ans << endl;
	printf("%d\n", ans);
	return 0;
}
