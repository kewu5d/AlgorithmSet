#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n, k[205], a,b;//起点a，终点b 
int step[205];//到i楼至少步数 
int main()
{
	cin >> n >> a >> b;
	for (int i=1; i<=n; i++)cin >> k[i];
	memset(step, -1, sizeof(step));
	step[a] = 0;//不要忘了 
	queue<int> qu;
	qu.push(a);
	//int cnt = 1;//不写这个也可以，因为只记录首次到该层的次数，不会反复横跳 
	while (!qu.empty() )// && cnt <=10000)
	{
		int now = qu.front();
		qu.pop();
		for(int i=0; i<=1; i++)
		{
			int next;
			//if (i==0 && now+k[now] <=b  && step[now]!=-1)//----这里不越界的条件不是[a,b]，而是1~n层楼，只是从a要到b而已 
														   //-----step[now+-k[now]]==-1，这里判断下一步的楼层是否可走 
			if (i==0 && now+k[now] <=n  && step[now+k[now]]==-1)
			{//上 ,不越界，没有访问过 
				next = now+k[now];
				step[next] = step[now]+1;
				qu.push(next);
			}
			//else if (i==1 && now-k[now] >= a && step[now]!=-1)
			else if (i==1 && now-k[now] >= 1 && step[now-k[now]]==-1)
			{//下 
				next = now-k[now];
				step[next] = step[now]+1;
				qu.push(next);
			} 
		}
		//cnt++;
		
		if (step[b]!=-1)break;
	}
	cout << step[b] << endl;
	return 0;
	
}
