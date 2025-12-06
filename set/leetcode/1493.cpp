/*
 * @lc app=leetcode.cn id=1493 lang=cpp
 *
 * [1493] 删掉一个元素以后全为 1 的最长子数组
 */
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l, r, ans = 0, not_one = 0;//, cnt = 0;//cnt:窗口长度，可以不需要
        for (l=r=0; r < nums.size(); r++)
        {
            //ru
            //cnt++;//不用数组，降空间
            if (nums[r] != 1)not_one++;
            //窗口是否合法？
            while (l <= r && not_one > 1)
            {
                //cnt--;//缩
                if (nums[l] != 1)not_one--;
                l++;
            }
            ans = max(ans, r-l+1);  //-not_one);
        }
        return ans-1;   //必须删一个，特殊全1数组元素也要删
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<int> a = {1,1,0,1};
    int res = sol.longestSubarray(a);
    cout << res << endl;
    return 0;
}

