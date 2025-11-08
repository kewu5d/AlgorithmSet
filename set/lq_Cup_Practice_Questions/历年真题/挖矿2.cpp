#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 2e6 +5;
int l[N], r[N];//数轴左右两边的矿洞位置，1：有矿 
int flag;
int main()
{
	int n, m; //cin >>n>>m;//m移动步数 
	scanf("%d %d", &n, &m);
	for (int i = 1; i<=n; i++)
	{
		int t;
		//cin >>t;
		scanf("%d", &t);
		if (t>0)r[t]=1;
		else if(t<0)l[-t] = 1;
		else 
		{
			//l[0]=r[0]=1;
			flag = 1;//标记起点就能挖到矿 
		}
	}
	for (int i=1; i<=n; i++)
	{
		l[i] += l[i-1];
		r[i] += r[i-1]; //前缀和 :表示走i步能获得的矿石数 
	}
	//向左向右
	int ans=0;
	for (int i=0; i<=m; i++) 
	{//向左走i步，往右返 m-2*i步 ；i:0~m步 
	//向右走i步，往左返 m-2*i步 ----------注意一开始向右走和向左返回右是不同的！！！ 
		int temp = 0;//重置 
		//一开始向左 
		temp += l[i];
		if (m-2*i >0)
		{//可以返回起点向右 
			temp += r[m-2*i];
		}
		//else  ;//返回失败，只能采到l[i]块矿石 
		ans = max(ans, temp);
		//一开始向右 
		temp=0;
		temp += r[i];
		if (m-2*i >0)		temp += l[m-2*i];
		ans = max(ans, temp);
	}
	//cout << ans+flag << endl;
	printf("%d", ans+flag);
	return 0;
	
}

