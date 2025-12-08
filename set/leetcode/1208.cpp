
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        //子字符串--连续
        //开销差分数组
        int n = s.size();
        int diff[100005] = {0};
        for(int i = 0; i < n; i++)
            diff[i] = abs(s[i]-t[i]);
        int ans = 0, cost = 0, l, r;
        for (l=r=0; r < n; r++)
        {
            cost += diff[r];
            while(l <= r && cost > maxCost)
            {
                cost -= diff[l++];
            }
            ans = max(ans, r-l+1);
        }
        return ans;

    }
};
int main()
{
    Solution Sol;
    string s = "pxezla", t = "loewbi";
    int ans = Sol.equalSubstring(s, t, 25);
    cout << ans << endl;
    return 0;
}