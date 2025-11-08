#include <bits/stdc++.h>
using namespace std;
int n, r;
vector<int> ans;
int vis[22];
void print()
{
	for (int i=0; i<ans.size(); i++)
	{
		printf("%3d", ans[i]);
	}
	printf("\n");
}
void dfs(int d)
{
	if (d > r)
	{
		//输出
		print();
		return ;
	}
	//for (int i=上一个选中的数+1; i<=n; i++)	//就是刚进vector容器里的数+1，注意判断容器是否为空 
	int i;
	if (!ans.empty()) i = ans.back() +1;
	else i = 1;
	for (i; i<=n; i++)
	{
		if (vis[i] == 1)continue;
		//else
		vis[i] = 1;
		ans.push_back(i);
		dfs(d+1);
		vis[i] = 0;
		ans.pop_back();
	}
}
int main()
{
	cin >> n>> r;
	
	dfs(1);//选第一个 
	return 0; 
}
