#include <cstdio>
#include <iostream>
using namespace std;
int f[200005];
int find(int x)
{
	if (f[x] == x)
	{//单元素集合 
		return x;
	}
	int fx = find(f[x]);//递归调用去找x所在集合的根节点 
	f[x] = fx;//路径压缩（集合的图示呈现深度为2的树） ---加快下次查找根的速度 
	return f[x] ;
}
int main()
{
	int n, m, z, x,y;
	cin >> n >> m;
	//初始化 
	for (int i = 1; i <= n;i++)
	{
		f[i] = i;
	}
	while (m--)
	{
		cin >> z;
		cin >> x >> y;
		if (z == 1)
		{//合并 
			//printf("here%d %d", f[x], f[y]);
			if (find(x) == find(y))
			{
				//已经在一个集合里 
			}
			else
			{//合并 
				f[find(x)] = find(y);//某个集合原根节点指向另一个集合的根节点 
			}
		}
		else if(z == 2) 
		{//查询 
			//printf("here%d %d", f[x], f[y]);
			if (find(x) == find(y))
			{
				cout << "Y" << "\n";
			}
			else
			{
				cout << "N" << "\n";
			}
		}
	}
	
	return 0;
}
