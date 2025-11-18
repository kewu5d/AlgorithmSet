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
	for (int i = 1; i <= N; i++)		cin >> stD[i];
	N++;//终点的石头也要算上 ****************
	stD[N] = L;//*****终点的岩石 
	int l = 1;
	int r = L;
	int now = 0;//now指针，指向现在跳跃的岩石位置 
	int mid;	//我们去二分答案，求谁mid就是谁 。 最大化mid 
	
	while (l <= r)
	{
		int x = 0;//x为按现在这个最短跳跃距离，需要移走的岩石 
		now = 0;//gengxin
		mid = (l + r) / 2;//假设跳跃的最小距离 --------------------------并非下标，就是答案，二分答案 
		for (int i = 1; i <= N; i++)
		{
			if (stD[i]-now >= mid) 
			{//说明该岩石可以作为台阶 
				now = stD[i];
			}
			else
			{
//				if (i == N) 
//				{
//					//最后一个岩石到终点的跳跃距离不满足最短跳跃距离，则将最后一个岩石移走 
//					;//终点岩石不可以移走，作为最后一步 ***********
//					但是这里把终点移走，**相当于**把到终点前的最后一个岩石移走，x++ 
//				}
//				else 
				x++;//不可以作为，需要移走 
			}
		}
		if (x <= M) 
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
