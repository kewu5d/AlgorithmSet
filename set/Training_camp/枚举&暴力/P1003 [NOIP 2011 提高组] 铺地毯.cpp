#include <iostream>
#include <cstdio>	//继承C语言中的<stdio.h> 
using namespace std;
int n;	//总n张地毯 
int x, y;
typedef struct
{
	int a, b, g, k;//注意：g、k表示长度，不是右下角坐标！
}date;	//地毯的位置信息 
date d[10005];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)	
	{//n个地毯铺设位置 
		scanf("%d %d %d %d", 
		&d[i].a, &d[i].b, &d[i].g, &d[i].k);
	}
	scanf("%d %d", &x, &y);
	//枚举---倒着枚举 
	int ans = -1;
	for(int i = n; i >= 1; i--)
	{
		//如果这张地毯正好盖住了查询点，输出地毯的编号，结束
		if (x >= d[i].a && x <= d[i].a + d[i].g &&
		y >= d[i].b && y <= d[i].b + d[i].k)
		{
			printf("%d\n", i);
			return 0;
		}
	}
	printf("%d\n", -1);
	
	return 0;
	//主要改进点:
	// ? 合并条件判断 - 减少嵌套
	// ? 直接输出返回 - 避免使用额外变量ans
}
