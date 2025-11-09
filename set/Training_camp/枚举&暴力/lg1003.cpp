#include <iostream>
#include <cstdio>	//继承C语言中的<stdio.h> 
using namespace std;
int n;	//总n张地毯 
int x, y;
typedef struct
{
	int a, b, g, k;
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
		if (x >= d[i].a && x <= d[i].a + d[i].g)
		{
			if (y >= d[i].b && y <= d[i].b + d[i].k)
			{
				ans = i;
				break;//很重要！倒着枚举第一个满足条件的毯子就是 
			}
		}
	}
	printf("%d\n", ans);
	
	return 0;
}
