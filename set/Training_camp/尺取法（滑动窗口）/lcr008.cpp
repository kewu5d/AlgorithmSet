#include <iostream>
#include <cstdio>
#include <vector>
#include <limits.h>	//使用INT_MAX 
using namespace std;
int minSubArrayLen(int target, vector<int>& nums) //引用传参，并非简单的拷贝 
{
	int ans = INT_MAX;	//求最小，将其一变量赋为尽可能大值 
	int l, r;
	l = r = 0;
	int sum = 0;
	while (r < nums.size()) 
	{
		sum += nums[r];
//		if (sum < target)
//		{//不合法 
//			r++;//扩大窗口 
//			continue; 
//		}
		while (l <= r && sum >= target ) 
		{
			int x = r-l+1; //记录本次合法区间长度 
			sum -= nums[l];l++;//缩小窗口 
			ans = min(ans, x);
		}
		r++;
	}
	//边界情况，都不满足时
	if (ans == INT_MAX) 
	{
		ans = 0;
	}
	return ans;
}
int t; 
int n;//数字个数 
int ans; 
//int nums[10005];
vector<int> nums;
int main()
{
	cin >> t >> n;
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		nums.push_back(a);
	}
	//vector<int>iterator l, r;//迭代器 
	//l = r = nums.begin();
	//printf("%d", nums.size());
	ans = minSubArrayLen(t, nums);
	cout << ans << endl;
	
	return 0;
}
