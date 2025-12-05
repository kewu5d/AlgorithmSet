/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int r, l, ans = 0;
        for (l = r = 0; r < s.size(); r++)
        {
            //ru
            mp[s[r]]++;
            while (l <= r && mp.size() != r-l+1)
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

int main()
{
    Solution sol;
    string s = "pwwkew";
    int res = sol.lengthOfLongestSubstring(s);
    cout << res << endl;
    return 0;
}

