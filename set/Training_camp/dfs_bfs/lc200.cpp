#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
void dfs(vector<vector<char>>& grid, int i, int j)
{
	int n = grid.size();
    int m = grid[0].size();
	grid[i][j] = 0;//淹没此块陆地，防止重复计算
	//深搜所有连通陆地，确保不越界并且是陆地 
	if (i-1>=0&& grid[i-1][j]=='1') dfs(grid, i-1, j);//上 
	if (i+1<n&& grid[i+1][j]=='1') dfs(grid, i+1, j);//下 
	if (j-1>=0&& grid[i][j-1]=='1') dfs(grid, i, j-1);//左 
	if (j+1<m&& grid[i][j+1]=='1') dfs(grid, i, j+1);//右 
}
int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int nums = 0;
    for (int i= 0;i <n;i++)
    {
    	for (int j=0;j<m;j++)
    	{
    		if (grid[i][j] == '1')
    		{
    			nums++;
    			dfs(grid, i, j);
			}
		}
	}
	return nums;
}
int main()
{
	int n, m;//n行m列 
	scanf("%d %d", &n, &m);
	//getchar();
	vector<vector<char>> grid(n, vector<char>(m));//n行m列 
	for (int i= 0;i<n;i++)
	{
		for(int j = 0; j<m; j++)
		{//注意：存储的是字符 
			getchar();
			scanf("%c", &grid[i][j]);
			//cout << grid[i][j] << " ";
		}
	}
	int ans = numIslands(grid);
	printf("%d", ans);
	return 0;
}

/*
4 5
1 1 1 1 0
1 1 0 1 0
1 1 0 0 0
0 0 0 0 0
*/
