#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    //解法2：滑动窗口
    string shortestBeautifulSubstring(string s, int k) {
        if (count(s.begin(), s.end(), '1') < k)return "";
        int l, r, cnt = 0;//1的个数
        string ans = s;
        for (l=r=0; r < s.size(); r++)
        {
            //cnt += (int)s[r];//强制转换，是1是0就加对应的---这里是错误的（不同于python）
            cnt += s[r] - '0';
            while (cnt >= k)
            {
                //合法，更新写在while内
                string t = s.substr(l, r-l+1);
                if (t.length() < ans.length() || t.size() == ans.size() && t < ans)
                {
                    ans = t;
                }
                //缩左端点---直接缩
                cnt -= s[l++] - '0';
            }
        }
        return ans;
    }
};

int main()
{
    Solution Sol;
    string a = "100011001";
    string ans = Sol.shortestBeautifulSubstring(a, 3);
    cout << ans << endl;
    return 0;
}