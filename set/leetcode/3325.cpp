#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int ch[26]{};
        //int cnt = 0;//至少出现k次的字符数
        int ans = 0, l = 0;
        for (char c: s)
        {
            ch[c - 'a']++;
            //if (ch[s[r]] == k)cnt++;
            while (ch[c - 'a'] == k)
            {
                ch[s[l] - 'a']--;
                l++;
            }
            ans += l;
        }
        return ans;
    }
    /*
    大胆点：
    1、26个字母，只开26个单位空间来存，用char - 'a'作下标
    2、不单独弄一个变量记录符合条件的字符数，刚刚添加完ch[c - 'a']++，立马判断是否合法
    3、直接用==，不要>=。因为出while循环，此时窗口一定不合法，不会出现 > 的情况
    */
};

int main()
{
    Solution Sol;
    string a = "hxccgfp";
    int ans = Sol.numberOfSubstrings(a, 1);
    cout << ans << endl;
    return 0;
}