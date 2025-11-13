#include <iostream>
#include <cstdio>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;
int qjsum(vector<int>& nums, int l, int r)
{
	int mid = (l + r) / 2;
	//从中间往两边延申 ,这是分治出来的第三种情况，包含mid在内 
	int lsum, rsum;
	lsum = rsum = nums[mid];
	int x = 0;//临时 
	for (int i = mid; i >= l; i--)	//注意这里是往左延申，所以是i--
	{
		x += nums[i];
		lsum = max(x, lsum);
	}
	x = 0;//genxin	
	for (int i = mid; i <= r; i++)
	{
		x += nums[i];
		rsum = max(x, rsum);
	}
	return (rsum + lsum - nums[mid]);//减去重复加的 
}
int maxsum(vector<int>& nums, int l, int r)
{
	if (l == r)//递归出口
	{
		return nums[l];
	}
	int mid = (l + r) / 2;
	int lmax = maxsum(nums, l, mid);//1---递归 也包含mid
	//这里的mid+1作为新的左边界，不可以mid同时作为左右边界，不然会陷入死循环 
	int rmax = maxsum(nums, mid+1, r);//2---递归
	int mmax = qjsum(nums, l, r);//3---函数解决 包含mid，答案区间即含左边又含右边
	int maxans = max(max(lmax, rmax), mmax);
	return maxans;
}
int maxSubArray(vector<int>& nums) {
	int l = 0, r = nums.size() - 1;
	return maxsum(nums, l, r);
}
int main()
{
	int n, x;
	cin >> n;
	vector<int> nums;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		nums.push_back(x);
	}
	int ans = maxSubArray(nums);
	cout << ans << endl;
	return 0;
}

/*
9
-2 1 -3 4 -1 2 1 -5 4
*/

