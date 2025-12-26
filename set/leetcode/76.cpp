#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
    bool check(unordered_map<char, int>& T, unordered_map<char, int>& S)
    {
        for (auto it = S.begin(); it != S.end(); it++)
        {
            char c = it->first;
            if (it->second < T[c])
                return false;//说明没有覆盖重复元素
        }
        return true;
    }

    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        if (m < n) return "";
        unordered_map<char, int> cntT, cntS;
        for (char c : t) cntT[c]++;//O(n)

        int ans = m + 1, ans_l = 0, ans_r = -1;
        for (int l = 0, r = 0; r < m; ++r) 
        {
            //使用count查找，而不是find
            if (cntT.count(s[r])) cntS[s[r]]++;//T中有的元素

            while (cntS.size() == cntT.size() && check(cntT, cntS)) // 覆盖了就尝试收缩
            {
                if (r - l + 1 < ans)
                {
                    ans = r - l + 1;
                    ans_l = l; ans_r = r;
                }
                if (cntT.count(s[l])) cntS[s[l]]--;
                ++l;
            }
        }
        return ans > m ? "" : s.substr(ans_l, ans);
    }
};

int main()
{
    Solution Sol;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string ans = Sol.minWindow(s, t);
    cout << ans << endl;
    return 0;
}