#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
ll L;
int n, m;
ll d[50005];//各石头到起点的距离。起点为0，终点为n+1 
ll x;//最短跳跃距离x：1~l	去猜去最大化x 
ll maxans;
int main()
{
	cin >> L >> n >> m;
	for (int i = 1; i <= n; i++)	cin >> d[i];
	d[n+1] = L;//终点（不可以移走） 
	int now=0, p=1;//目前所在岩石 ,p为目标岩石 
	int l =1, r=L;//最短跳跃距离x：1~l	去猜去最大化x 
	x = (l+r)/2;//取中间【1，l】 
	while (l <= r) 
	{
		int temp = 0;now =0, p=1;//更新 
		while (now != n+1 && p <= n+1)  
		{//没到终点 
			if (d[now]+x > d[p]) //&& p!= n+1)
			{//说明下一块石头p满足不了x，移走这块岩石(不能是终点)------------>但是可以移走终点前的最后一块石头来满足要求 
				temp++; 
				p++;
			}
			else
			{//满足 
				now = p;//跳跃过去 
				p++;
			}
		}
	//	if (temp == m)break;	temp <=m都是合法解。取max 
		if(temp <= m)
		{//移走少了，x猜小了 ,但是一个合法解 
			maxans = max(maxans, x);
			l = x+1;	x = (l+r)/2;
		}
		else
		{
			
			r = x-1;x = (l+r)/2;
		}
	}
	//cout << maxans << endl;
	printf ("%lld\n", maxans);
	return 0;
}
