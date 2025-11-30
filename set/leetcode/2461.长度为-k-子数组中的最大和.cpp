/*
 * @lc app=leetcode.cn id=2461 lang=cpp
 *
 * [2461] 长度为 K 子数组中的最大和
 */

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
#define ll long long
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        //1. 维护区间和--扩、缩
        //2. check
        int n = nums.size(),l = 0, r = k-1;
        ll ans = 0, sum = 0;
        unordered_map<int, int> mp;//映射表（哈希表），记录同一个数的数量
        for (int i = l; i <= r; i++)
        {
            sum += nums[i];
            mp[nums[i]]++;
        }
        if (mp.size() == k)
            ans = max(ans, sum);
        for (r++; r < n; r++, l++)
        {
            mp[nums[r]]++;
            sum += nums[r];
            mp[nums[l]]--;
            if (mp[nums[l]] == 0)
                mp.erase(nums[l]);//这个数没有了，不占子数组唯一个数
            sum -= nums[l];

            if (mp.size() == k)
                ans = max(ans, sum);
        }
        return ans;//不存在几乎唯一子数组，请你返回 0
    }
};
// @lc code=end

