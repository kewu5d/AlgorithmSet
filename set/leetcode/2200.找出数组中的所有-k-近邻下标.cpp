/*
 * @lc app=leetcode.cn id=2200 lang=cpp
 *
 * [2200] 找出数组中的所有 K 近邻下标
 */

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int n = nums.size(), j = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != key) {
                continue;
            }
            //找到=key的下标。将key影响的区域[i-k, i+k]均入数组
            j = max(j, i - k);
             //（关键！）j不会回退，保证不受上一个key的领域影响，重复入数组
            while (j <= min(i + k, n - 1)) { //保证不能越界
                ans.push_back(j++);
            }
            //由于j不会回退，j最多加n次。故虽两层循环，时间顶多是n+n的，故是O(n)的。空间是O(1)
        }
        return ans;
    }
};
// @lc code=end

