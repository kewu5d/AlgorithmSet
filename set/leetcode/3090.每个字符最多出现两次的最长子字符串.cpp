/*
 * @lc app=leetcode.cn id=3090 lang=cpp
 *
 * [3090] 每个字符最多出现两次的最长子字符串
 */

#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> mp;
        int r, l, ans = 0;
        for (l = r = 0; r < s.size(); r++)
        {
            //ru
            mp[s[r]]++;
            while (l <= r && mp[s[r]] > 2)
            {
                mp[s[l]]--;
                if (mp[s[l]] == 0)
                    mp.erase(s[l]);
                l++;
            }
            
            ans = max(ans, r-l+1);

        }
        return ans;
    }
};
// @lc code=end

