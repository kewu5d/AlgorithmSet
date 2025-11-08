#include <iostream>
#include <cstdio>
#include <vector>
#define ll long long 
using namespace std;
int minEatingSpeed(vector<int>& piles, int h) {

	int l, r, mid, k;
	l = 1;
	int maxsj = 0;
	for (int i = 0; i < piles.size(); i++)
	{
		maxsj = max(piles[i], maxsj);
	}
	r = maxsj;
	ll time;//*****保险一点 
	while (l <= r)
	{
		time = 0;
		mid = (l+r)/2;
		for (int i = 0; i < piles.size(); i++)
		{
			time += piles[i] / mid;
			if (piles[i]%mid != 0)
			{//有余数，还要再花一小时 
				time++; 
			}
		}
		if (time <= h)
		{//合法，可能是最优解，让狒狒吃得再慢一些 
			r = mid - 1;
			k = mid;
		}
		else
		{//猜的速度，太慢了，往右半边猜，吃快点 
			l = mid + 1;			
		}
	}
	return k;
}

int main()
{
	int n, H, x;
	cin >> n >> H;
	vector<int> piles;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		piles.push_back(x);
	}
	int k = minEatingSpeed(piles, H);
	cout << k << "\n";
	return 0;
	
}
