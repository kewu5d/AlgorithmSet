#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
    bool check(unordered_map<char, int> T, unordered_map<char, int> S)
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
        // 重复字符 ，重复出现在子串中
        // s中找t
        //s 和 t 由英文字母组成,字符<124
        int m = s.length(), n = t.length();
        if (m < n)
            return "";
        unordered_map<char, int> cntT, cntS;
        for (char i : t) {
            cntT[i]++;
            //cntS[i]++;
        }
        int ans = n + 1, l, r;
        int ans_l = 0, ans_r = 0;//记录字串区间
        for (l = r = 0; r < m; r++) 
        {
            if (cntT.find(s[r]) != cntT.end())
            {
                cntS[s[r]]++;//在T中找得到,才添加
            }
            while (s.size() == t.size() && check(cntT, cntS))
            {
                //S的子串中覆盖了T
                //ans = min(ans, r-l+1);
                if (r-l+1 < ans)
                {
                    ans_l = l;ans_r = r;
                }

                if (cntT.find(s[l]) != cntT.end())
                {
                    cntS[s[l++]]--;//缩短窗口
                }
            }
        }
        return ans > n? "": s.substr(s[ans_l], ans_r - ans_l + 1);
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