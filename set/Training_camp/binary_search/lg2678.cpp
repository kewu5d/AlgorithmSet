#include <iostream>
#include <algorithm>
using namespace std;
const int Num = 50005;
int dist[Num];//各个石头到起点的距离distance
int L, N, M;
int main()
{
	cin >> L >> N >> M;//M最多移走石头数
	for (int i = 0; i < N; i++)cin >> dist[i];//中间N块
	dist[N] = L;//终点这块石头
	int l = 1, r = L, mid = 0, res = 0;//res:最大化最短距离
	while (l <= r)
	{
		//1. 初始化
		int now = 0;//当前位置到起点距离
		int cnt = 0;//移走的石头数
		mid = l + (r - l) / 2;//二分答案res

		//2. 移石头整个过程
		for (int i = 0; i <= N; i++)
		{//这里<=N：遍历所有石头，包括终点(dist[N])
		//区别：跳到终点石头，不符合条件是移走所在的最后一块
		//而跳到中间任意石头，不符合条件是移走将要跳的石块
			if (dist[i] - now >= mid)
			{
				now = dist[i];
			}
			else cnt++;//必须移走当前这块石头dist[i]（对于终点，逻辑上等同于移走前一块）
		}
		//3. 汇总核查check
		//这里1.2.可以作函数分离check的bool函数
		if (cnt <= M)
		{
			res = max(res, mid);
			//最大化
			l = mid + 1;
		}
		else r = mid -1;
	}
	cout << res << endl;
	return 0;
}
/*
8 3 1
2
4
7

2?
*/
