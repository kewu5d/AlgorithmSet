#include <iostream>
#include <cstdio>
using namespace std;
int n;
bool flag[15];//初始化为0，没有使用；1表示被使用过了 
int ans[15];
void pri()
{
	for (int i = 1;i <=n; i++)
	{
		printf("%5d", ans[i]);
	}
	printf("\n");
}
void dfs(int k)
{
	if (k > n)
	{
		//输出
		pri();
		return; 
	}
	//第k位置填入数字，n个里面选一个 
	for (int i = 1;i <=n; i++)
	{
		if(flag[i] == 0) 
		{//没有使用 
			ans[k] = i;//第k位置选择了i 
			flag[i] = 1;
			//继续深入搜索，填入k+1个
			dfs(k+1);//深入搜索到底，得到一组合法解
			//归来重新选第k个位置的数字,进行回溯 
			flag[i] = 0;
		}
	}
}
int main()
{
	cin >> n;//整数n 
	dfs(1);
	return 0;
}
