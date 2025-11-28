/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l = 0, r = k - 1;
        double sum = 0;
        for (int i = l; i <= r; i++)
        {
            sum += nums[i];
        }
        r++;
        double temp = sum;
        for (; r < nums.size(); r++, l++)
        {
            temp += nums[r];
            temp -= nums[l];
            sum = max(sum, temp);
        }
        return sum / k;
    }
};
// @lc code=end

