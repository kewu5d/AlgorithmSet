/*
 * @lc app=leetcode.cn id=1456 lang=cpp
 *
 * [1456] 定长子串中元音的最大数目
 */

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxVowels(string s, int k) {
        int l = 0, r = k-1;
        int res = 0;
        for (int i = l; i <= r; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i'\
            || s[i] == 'o' || s[i] == 'u')
            {
                res++;
            }
        }
        int temp = res;
        for (r++; r < s.length(); r++, l++)
        {
            //右边新元素l+k
            if (s[r] == 'a' || s[r] == 'e' || s[r] == 'i'\
            || s[r] == 'o' || s[r] == 'u')
                temp++;
            //左边老元素l
            if (s[l] == 'a' || s[l] == 'e' || s[l] == 'i'\
            || s[l] == 'o' || s[l] == 'u')
                temp--;

            res = max(res, temp);
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution sol;
    string s = "abciiidef";
    int k = 3;
    cout << sol.maxVowels(s, k) << endl;
    return 0;
}


