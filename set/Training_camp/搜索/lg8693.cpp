#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
char map[305][305];//地图 
int visit[305][305];//1表示访问过了，BFS不再走一遍 
typedef struct pos
{
	int x, y;
	int time;
}pos;
queue<pos> q;
//上下左右动 ,判断后动不了就不动，但time要+1 
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};//0~3下标 
int main()
{
	int n, k;
	cin >> n >>k;
	//读入地图 ---字符 
	for (int i = 1;i<=n;i++)
	{//从1，1开始 存储 
		scanf("%s", &map[i][1]);//%s格式符默认读取到空格或换行符停止
	}
	pos now, next;
	now.x= now.y = 3;//起点
	visit[3][3] = 1;
	now.time = 0;
	q.push(now);
	int flag = 2;//2:5*5,   1:3*3,  0: 1*1 
	while (!q.empty())
	{//队非空 
		now = q.front();
		q.pop();//取队首
		if (now.time == k) 
		{
			flag = 1;
		}
		else if(now.time == 2*k)
		{
			flag = 0;
		}
		if (flag != 0) 
		{//还没瘦成正常人，都可以战术性原地逗留，原位置时间改变，且进入队列 
			next.x = now.x;
			next.y = now.y;
			next.time = now.time+1;//时间加1 
			q.push(next);
		}
		//开始移动----上下左右 
		int ok = 0; //是否可以动 
		for (int i=0;i <=3;i++) 
		{
			next.x = now.x + dx[i];
			next.y = now.y + dy[i];
			//判断该方向能走不 ,前提没被访问过 
			int idx = 0;
			if (visit[next.x][next.y] == 0)
			{
				for (int ii = next.x-flag; ii<= next.x+flag; ii++)
				{
					for (int jj = next.y-flag; jj <= next.y+flag; jj++)
					{
						//无越界&&&&没障碍 
						if (1<=ii && ii<=n && 1<=jj && jj <= n && map[ii][jj] != '*') 
						{//可以走 
							idx++;	
							ok = 1;			
						}
						else
						{
							ok = 0;
							break;//一个不符合，直接跳出 
						} 
					}
					if (ok == 0)break;
				}
				//判断过后，能走
				int t = flag*2 + 1;
				if(idx == t*t)
				{//小明占地位置均合法，可以行进 
					ok = 1;
					if (next.x == n-2 && next.y == n-2)
					{
						printf("%d", now.time +1);
						return 0;//************************走到终点end 
					}
					next.time = now.time +1;
					visit[next.x][next.y]= 1;
					q.push(next);
				}
			}
		}
		//思想错误************可以选择待在原地，在任何位置 ，只要flag！=0，还是个胖子的时候都可以战术性逗留 
//		if (ok == 0)
//		{//不能动，就待原地 
//			next.x = now.x;
//			next.y = now.y;
//			next.time = now.time+1;//时间加1 
//			q.push(next);
//		}
	}
	
}
