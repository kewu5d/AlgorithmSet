/*
 * @lc app=leetcode.cn id=2841 lang=cpp
 *
 * [2841] 几乎唯一子数组的最大和
 */

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;


// @lc code=start
#define ll long long
class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
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
        if (mp.size() >= m)
            ans = max(ans, sum);
        for (r++; r < n; r++, l++)
        {
            mp[nums[r]]++;
            sum += nums[r];
            mp[nums[l]]--;
            if (mp[nums[l]] == 0)
                mp.erase(nums[l]);//这个数没有了，不占子数组唯一个数
            sum -= nums[l];

            if (mp.size() >= m)
                ans = max(ans, sum);
        }
        return ans;//不存在几乎唯一子数组，请你返回 0
    }
};
// @lc code=end

int main()
{
    Solution sol;
    int b;cin >> b;
    vector<int> a(b);
    for (int i=0; i<b;i++)cin >> a[i];
    int m, k;
    cin >> m >> k;
    ll ans = sol.maxSum(a, m, k);
    cout << ans << endl;
    return 0;
}

