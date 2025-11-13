#include <iostream>
#include <vector>
using namespace std;
int n,step, sum;//sum为总步数
int desk[21][21];//1就表示访问过
vector<int> ans;//行进路径 
int x[21], y[21];//靶子 
//int  flag=0;
void print()
{
  for (int i=0;i<ans.size();i++)
  {
    cout << ans[i] << ' ';
  }
}
void dfs(int depth, int i, int j)
{
	
	if (i<0 || j<0 || i>=n || j>=n)return;//越界 
	if (x[i]<=0 || y[j] <= 0) return;
	//cout << depth << ' ';
    if (step == sum-1)
    {//路径唯一,深搜到终点判断是否步数够了
    	if ( depth==n*n-1)
		{//并且按照默认唯一路径 
			for (int i=0;i<n;i++)
			{
				if (x[i]!=1)return;
			}
			for (int j=0;j<n;j++)
			{
				if (y[j]!=1)return;	
			}
			print();
		 } 
        return;
    }
    
    //深搜下、上、左、右 
    if (j+1<n && desk[i][j+1]==0)
    {
    	step++;
	    desk[i][j+1] = 1;
	    x[i]--,y[j+1]--;
	    ans.push_back(depth+1);
    	dfs(depth+1, i, j+1); //右--1
		step--;
	    desk[i][j+1] = 0;//越界风险 
	    x[i]++,y[j+1]++;
	    ans.pop_back();
	}
	
    if (i+1<n && desk[i+1][j]==0)
    {
    	step++;
	    desk[i+1][j] = 1;
	    x[i+1]--,y[j]--;
	    ans.push_back(depth+n);
    	dfs(depth+n, i+1, j);//下--2
		step--;
	    desk[i+1][j] = 0;
	    x[i+1]++,y[j]++;
	    ans.pop_back();
	}
	if (j-1>=0 && desk[i][j-1]==0)
    {
    	step++;
	    desk[i][j-1] = 1;
	    x[i]--,y[j-1]--;
	    ans.push_back(depth-1);
    	dfs(depth-1, i, j-1);//左 --3
		step--;
	    desk[i][j-1] = 0;
	    x[i]++,y[j-1]++;
	    ans.pop_back();
	}
    
	if (i-1>=0 && desk[i-1][j]==0)
    {
    	step++;
	    desk[i-1][j] = 1;
	    x[i-1]--,y[j]--;
	    ans.push_back(depth-n);
    	dfs(depth-n, i-1, j);//上--4
		step--;
	    desk[i-1][j] = 0;
	    x[i-1]++,y[j]++;
	    ans.pop_back();
	}
    
	
}
	
int main()
{
    cin >> n;
    for (int i=0;i<n;i++)//0~n
    {
        cin >>y[i];
        sum += y[i];//总步数 
    }
    for (int i=0;i<n;i++)
    {
        cin >>x[i];
    }
    dfs(0, 0, 0);//从0位置深搜 
    return 0;

}
/*
4
2 4 3 4
4 3 3 3
*/
