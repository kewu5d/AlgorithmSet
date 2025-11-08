#include <iostream>
#include <cstdio>
#include <map>
#include <limits.h>
#include <algorithm> 
using namespace std;
pair<int, int> p[100005];
int main()
{
	int n, k; cin >> n >> k;//n块，k个小朋友 
	int x = 1;//二分答案区间1~x 
	for (int i= 1; i<=n; i++)
	{
		cin >> p[i].first >> p[i].second;//第i块f*s =h*w
		int t = max(p[i].first, p[i].second);
		x = max(x, t) ;
	}
	int l=1, r=x;//边长往最大边长猜 
	int mid;int maxans=0;
	int temp;//目前切出的正方形巧克力块数 
	while (l <= r) 
	{
		mid = (l+r)/2;temp=0; 
		for (int i=1; i<=n; i++)
		{//如何处理切？？？ 
			temp += p[i].first/mid * (p[i].second/mid);
		}
		if (temp >= k)
		{//合法，还能不能再大一点
			maxans = max(mid, maxans);//mid是猜测答案哈 
			l = mid+1;
		}
		else r=mid-1;
	}
	cout << maxans << endl;
	return 0;
}
