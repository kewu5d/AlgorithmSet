#include <iostream>
#include <cstdio>
using namespace std;
int n;
int a[11], flag[11];//标记数组i位置是否使用，1使用，0未使用 
void dfs(int pos)
{//填第pos个位置为x; pos:1~n
	if (pos > n)
	{//填好了 
		for (int i=1;i<=n;i++)
			printf("%5d", a[i]);
		printf("\n");
		return;
	}
	//填下一个位置 
	for (int i=1; i<=n; i++)
	{
		if (flag[i]==0)//未使用 
		{
			a[pos] = i;
			flag[i] = 1;
			dfs(pos+1);
			flag[i] = 0;//回溯 
		}
	}
}
int main()
{
	cin >> n;
	dfs(1);//填第一个位置
	return 0; 
}
