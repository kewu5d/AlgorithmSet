#include <iostream>
#include <cstdio>
#include <vector>
#include <limits.h>	//使用INT_MAX 
using namespace std;
int minSubArrayLen(int target, vector<int>& nums) //引用传参，并非简单的拷贝 
{
	int n = nums.size();
	int ans = n+1;	//求最小，将其一变量赋为尽可能大值 
	int l, r;
	l = r = 0;
	int sum = 0;
	while (r <= nums.size()) 
	{
		//符合条件
		if (sum >= target ) 
		{
			ans = min(ans, r - l); //记录本次合法区间长度，不要用r-l+1
			sum -= nums[l++];//缩
			continue;
		}
		//扩
		if (r == n)break;//此时已经遍历完整个数组
		sum += nums[r++];//这里不会越界，r++在后
		//这里r++后r指向的是下一个位置，并不是当前的右边界。所以计算区间长度时，要用r-l
		
	}
	//边界情况，都不满足时
	return ans == n+1? 0:ans;
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
