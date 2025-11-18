#include <vector> 
#include <cstdio>
#include <iostream>
using namespace std;
vector<vector<int>> generateMatrix(int n) 
{
	vector<vector<int>> a(n, vector<int>(n));
	int t, b, l, r;	//4个边界
	t = l = 0;
	b = r = n - 1;
	//暴力模拟
	int num = 1;
	while(num <= n * n)		//这里填入最后一个数n*n，只会进入第一个循环 
	{
		for (int i = l; i <= r; i++)
		{//从左往右 
			a[t][i] = num;
			num++;
		}
		t++; //往下缩 
		for (int i = t; i <= b; i++)
		{//从上往下 
			a[i][r] = num;
			num++;
		}
		r--;
		for (int i = r; i >= l; i--)
		{//从右往左 
			a[b][i] = num;
			num++;
		}
		b--;
		for (int i = b; i >= t; i--)
		{//从下往上 
			a[i][l] = num;
			num++;
		}
		l++;
	}
	return a; 
}
int main()
{
	int n;
	scanf("%d", &n);
	
	vector<vector<int>> ans = generateMatrix(n);
	//输出
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	
	}
	 
	return 0;
}
