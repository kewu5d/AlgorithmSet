#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        //要求：长度最小+字典序最小
        //字典序0 < 1
        //C++20：ranges::count(s, '1')
        if (count(s.begin(), s.end(), '1') < k)return "";

        //法一：枚举
        
        for (int len = k; len <= s.size(); len++)
        {
            string ans = "";
            //固定长度，暴力枚举右窗口
            for (int i = len; i <= s.size(); i++)
            {//这里是i <= s.size()，含等于，不要漏了最后一个窗口（因为这不是具体指右窗口的下标）
                string temp = s.substr(i-len, len);//这才是借助伪右窗口获取子数组
                if ( (ans.empty() || temp < ans) && count(temp.begin(), temp.end(), '1') == k)
                {
                    ans = temp;
                }
            }
            //如果这个长度找到了，即为最短，停止枚举长度，并输出最小字典序字符串
            if (!ans.empty())return ans;
        }
        //return "";
        //1.兜底的返回值  or 2.使用for (int len = k; ; len++)，不约束len<=s.size()
        //目的：告诉编译器，我已经为函数提供完整的返回值，不用警告了
    }
};

int main()
{
    Solution Sol;
    string a = "100011001";
    string ans = Sol.shortestBeautifulSubstring(a, 5);
    cout << ans << endl;
    return 0;
}