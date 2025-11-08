#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define ll long long 
using namespace std;
int minEatingSpeed(vector<int>& piles, int h) 
{
	int len = piles.size();//0~len
	int maxans = 0;
	for (int i=0; i<len; i++)
	{
		maxans = max(piles[i],maxans);
	}
	int l=1, r=maxans;//二分答案区间 
	int mid;//猜测答案 
	int minans = r+1;
	int time;
	while (l <= r)
	{
		mid = (l+r)/2;
		time = 0; //piles发生了改变？？ ---取模，除法 
		for (int i=0; i<len; i++)
		{
			if (piles[i] < mid )//&& piles[i]%mid !=0)
			{
				time++;
			}
			else if (piles[i] % mid == 0)
			{
				time += piles[i]/mid;//可以整除 
			}
			else
			time += piles[i]/mid + 1;//不能 
		}
		if (time <= h)
		{//合法 ---但还能再慢一些吗 
			minans = min(minans, mid);
			r = mid-1; 
		}
		else l = mid+1;//时间来不及，吃快一点 
	}
	return minans;
}
vector<int> p;
int main()
{
	int n; int h;cin >> n >> h;//根据题目函数提示，int就够了 
	for (int i=1; i<= n; i++)
	{
		int t;cin >> t;
		p.push_back(t);
		
	}
	int ans = minEatingSpeed(p, h);
	
	cout << ans << endl;
	return 0;
}
