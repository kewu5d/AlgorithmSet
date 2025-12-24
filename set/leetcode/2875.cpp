/*
 * @lc app=leetcode.cn id=2875 lang=cpp
 *
 * [2875] 无限数组的最短子数组
 */
#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        int k = target / total;
        int rem = target % total;//remainder余数
        int n = nums.size();
        int ans = target + 1, l, r;//sum = 0;
        long long sum = 0;//sum至多小于两个total，需要用long long
        for (l=r=0; r < 2*n; r++)
        {
            sum += nums[r % n];//for判断条件+取余实现遍历两次nums数组
            while (sum > rem)
            {
                sum -= nums[l % n];
                l++;
            }
            if (sum == rem)
            {
                ans = min(ans, r-l+1);
            }
        }
        return ans > target? -1: ans + k * n;
    }
};
// @lc code=end
int main()
{
    Solution Sol;
    vector<int> a = {2,1,5,7,7,1,6,3};
    int ans = Sol.minSizeSubarray(a, 39);
    cout << ans << endl;
    return 0;
}
