#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
//乘积严格小的核心：大区间合法，小区间一定也合法 
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int l, r;
	l = r = 0;
	int cj=1, ans=0;
	for (; r < nums.size(); r++)
	{
		cj *= nums[r];
		
		while (cj >= k && l <= r) 	//*********** l <= r保障不合法，但不会无脑缩小 
		{//不合法 
			cj /= nums[l] ;
			l++;//缩小 ,直至合法 
		} 
		if (cj < k)
		{
			ans += r-l+1;	//大区间合法，小区间一定也合法
							//直接计算固定r窗口后的子数组数目即可
			 
		}
	}
	return ans ;
}
int main()
{
	int k, n;
	vector<int> nums;	//可变数组名 就相当于是个地址 
	scanf("%d %d", &k, &n);
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		nums.push_back(a);
	}
	int ans;
	//边界********* 
	ans = numSubarrayProductLessThanK(nums, k);
	printf("%d", ans);
	return 0;
}
