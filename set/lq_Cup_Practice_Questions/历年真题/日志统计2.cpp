#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
int like[N];//各id的点赞数-----点赞数随着滑动窗口会发生改变 
int ishot[N];//0不是热贴，1是热帖 
bool cmp(pair<int, int> x, pair<int, int> y)
{
//	if (x.second != y.second)return x.second < y.second;
	return x.first < y.first;
	//按id升序排序后在按ts排序 
}
int main()
{
	int n, d, k;cin >> n >> d >> k;//id:0~10^5
	pair<int, int> p[N];
	for (int i=1; i<=n; i++)
	{
		cin >> p[i].first >> p[i].second;//ts,id
	}
	sort (p+1, p+n+1, cmp) ;
	int l, r;l= r=1;
	while (r <= n)
	{
		like[p[r].second]++;
		while (p[r].first - p[l].first >= d) //&& l<r可省 
		{//不合法 
			like[p[l].second]--;
			l++;
		}
		if (like[p[r].second] >= k) ishot[p[r].second] = 1;
		r++;
	}
	//暴力判断输出
	for (int i=0; i<N;i++) 
	{
		if(ishot[i])cout << i << endl; //此时i就是下标id 
	}
	return 0;
}
