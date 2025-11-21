#include <iostream>
#include <cstdio>
#include <limits.h>
using namespace std;
int L, N, M;//长度，岩石数（不含起终点） ，最多可移走岩石数 
int stD[50005];//各石头到起点的距离 
int maxans;
int main()
{
	cin >> L >> N >> M;
	for (int i = 1; i <= N; i++)cin >> stD[i];
	N++;//终点的石头也要算上 ****************
	stD[N] = L;//终点的岩石
	int l = 1;
	int r = L;
	int now = 0;//now指针，指向现在跳跃的岩石位置 
	int mid;	//我们去二分答案，求谁mid就是谁 。 最大化mid 
	
	while (l <= r)
	{
		int cnt = 0;//cnt为按现在这个最短跳跃距离，需要移走的岩石 
		now = 0;//更新--当前所在石头距离起点的距离
		mid = (l + r) / 2;//假设跳跃的最小距离 ---------并非下标，就是答案-二分答案 
		for (int i = 1; i <= N; i++)
		{
			if (stD[i]-now >= mid) 
			{//说明该岩石可以作为台阶 
				now = stD[i];//跳过来
			}
			else cnt++;//不可以作为，需要移走 
		}
		if (cnt <= M) 
		{//合法 
			maxans = max(maxans, mid);//这个mid可能时最优解 
			//去右半边猜，最大化最短跳跃距离答案
			l = mid + 1;
		}
		else
		{//不合法，就是移多了岩石，猜大了，去左半边 
		//猜的越大，移走岩石数会越多 
			r = mid - 1; 
		}
	}
	printf("%d", maxans);
	return 0;
}
/*
8 3 1
2
4
7

2?
*/
