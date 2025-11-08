#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n, T[15], D[15], L[15], flag;
int Time, Ltime; //, t1, t2;//上一架飞机安排的降落时间,本架降落时间 
int t;//测试样例
int vis[15];//访问数组，表示第i架飞机已经安排降落 
//安排函数 
void arr(int k)
{
	if (k > n)
	{//安排到第k架 
		//cout << "YES" << endl;
		flag = 1;
		return;
	}
	for (int i=1; i<=n; i++)
	{
		if (vis[i] == 0 && Time+Ltime <= T[i]+D[i])
		{//可安排 
			int t1 = Time;//不能设全局变量，会在后续安排中改变此刻存取的值 
			int t2 = Ltime;
			Time = max(Time+Ltime, T[i]);
			Ltime = L[i];
			vis[i] = 1;
			arr(k+1);//安排下一架 
			vis[i] = 0;
			Time = t1;//回溯 
			Ltime = t2;
			
		}
		//else continue;
	}
}
int main()
{
	cin >> t;
	while (t--)
	{
		memset(vis, 0, sizeof(vis));//这种多数据样例，一般都要重置公用变量 
		flag = 0; //重置 
		cin >> n;
		for (int i=1; i<=n; i++) 
		{
			cin >> T[i] >> D[i] >> L[i];
		}
		arr(1);
		if (flag)cout << "YES" << endl;
		else cout << "NO" << endl;
		
	}
	return 0;
}
