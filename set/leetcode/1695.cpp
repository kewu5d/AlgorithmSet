/*
 * @lc app=leetcode.cn id=1695 lang=cpp
 *
 * [1695] 删除子数组的最大得分
 */
#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        //若干不同元素
        unordered_map<int, int> mp;
        int n = nums.size();
        vector<int> sum_n(n, 0);//前缀和
        sum_n[0] = nums[0];
        for (int i = 1; i < n; i++)sum_n[i] = sum_n[i-1] + nums[i];
        
        int ans = 0, l, r;
        for (l=r=0; r < n; r++)
        {
            mp[nums[r]]++;
            while(l <= r && mp[nums[r]] > 1)
            {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0)mp.erase(nums[l]);
                l++;
            }
            // 修复：处理 l=0 的边界情况
            int sum = (l == 0) ? sum_n[r] : sum_n[r] - sum_n[l-1];
            ans = max(ans, sum);
        }
        return ans;
    }
};
// @lc code=end
int main()
{
    Solution Sol;
    vector<int> a = {4,2,4,5,6};
    int ans = Sol.maximumUniqueSubarray(a);
    cout << ans << endl;
    return 0;
}
