#include <iostream>
using namespace std;
int desk[5][5], ans;//0~4
bool check()
{//上下左右主副对角 -----横纵交叉（4个方向） 
	int s1, s2, s3, s4;s1=s2=s3=s4=0;//------------------高级的判断方法，搞自己 
	for (int i=0; i<5;i++)
	{
		s1=s2 =0;//重置 
		for (int j = 0; j<5;j++)
		{
			if(desk[i][j]==1) s1++;//横 
			if (desk[j][i]==1) s2++;//纵 
			//if (i==j && desk[i][j]==1)s3++; //主对角 --只有5个，不用初始化 
			//////////if(i==4-j )s4++; //副 --------------未解之谜（应该是重复判断了） 
		}
		if (desk[i][i]==1)s3++;//主
		if(desk[i][4-i])s4++;//副 
		if (s1 == 5 || s1==0 || s2==5 ||s2==0) return false;
	}
	if (s3 == 5 || s3==0 || s4==5 || s4==0) return false;
	else return true;//和棋 
}
void dfs(int depth, int w, int b)
{
	//if (depth ==25 && w==13 && b==12 && check())//&&短路 
	if (depth==25){
		if (w==13 && b==12 && check())ans++;
		return;//depth==25无论是否和棋都要返回 
	}
	int x = depth/5;
	int y = depth%5;
	desk[x][y] = 1;//1表示白棋---放白棋 
	dfs(depth+1, w+1, b);
	desk[x][y] = 0;//-----------放黑棋 
	dfs(depth+1, w, b+1);
}
int main()
{
	dfs(0, 0, 0);
	cout << ans << endl;
	return 0;
}
