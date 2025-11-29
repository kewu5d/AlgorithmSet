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
        //1. 维护区间和
        //2. check
        ll n = nums.size();
        ll l = 0, r = k-1, ans = 0, sum = 0;
        unordered_set<int> st;
        for (int i = l; i <= r; i++)
        {
            sum += nums[i];
            st.insert(nums[i]);
        }
        if (st.size() >= m)
            ans = max(ans, sum);
        for (r++; r < n; r++, l++)
        {
            st.insert(nums[r]);
            sum += nums[r];
            if (st.find(nums[l]) != st.end())
            {//左窗口还找的到
                st.erase(nums[l]);//时间：2*logN
                //bug:这里不能把左窗口删掉，因为set是去重了的
            }
            sum -= nums[l];

            if (st.size() >= m)
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

