/*
 * @lc app=leetcode.cn id=2762 lang=cpp
 *
 * [2762] 不间断子数组
 */
#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        deque<int> min_e, max_e;//递增递减队列，存下标i，这里采用存元素
        long long ans = 0;
        int l, r;
        for (l=r=0; r < nums.size(); r++)
        {
            //维护min-e, max_e的队首为：窗口的最小、大值
            while(!min_e.empty() && min_e.back() > nums[r]) min_e.pop_back();
            min_e.push_back(nums[r]);

            while(!max_e.empty() && max_e.back() < nums[r]) max_e.pop_back();
            max_e.push_back(nums[r]);

            while (max_e.front() - min_e.front() > 2)
            {
                if (nums[l] == min_e.front()) min_e.pop_front();
                if (nums[l] == max_e.front()) max_e.pop_front();
                l++;//缩
            }
            ans += r-l+1;
        }
        return ans;
    }
};
// @lc code=end

