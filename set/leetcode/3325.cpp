#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int ch[130]{};
        int cnt = 0;//至少出现k次的字符数
        int l, r, ans = 0;
        for (l=r=0; r < s.length(); r++)
        {
            ch[s[r]]++;
            if (ch[s[r]] == k)cnt++;
            while (cnt >= 1)
            {
                if (ch[s[l]] == k)
                {
                    ch[s[l]]--;
                    cnt--;
                }
                else ch[s[l]]--;
                l++;
            }
            ans += l;
        }
        return ans;
    }
};

int main()
{
    Solution Sol;
    string a = "hxccgfp";
    int ans = Sol.numberOfSubstrings(a, 1);
    cout << ans << endl;
    return 0;
}