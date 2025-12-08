#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //ans:最大果树数量，窗口允许连续两种类型
        unordered_map<int, int> mp;
        int ans = 0, l, r;
        for (l=r=0; r < fruits.size(); r++)
        {
            mp[fruits[r]]++;
            while (l <= r && mp.size() > 2)
            {
                mp[fruits[l]]--;
                if (mp[fruits[l]] == 0)
                    mp.erase(fruits[l]);
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};

int main()
{
    Solution Sol;
    vector<int> a = {1,2,1};
    int ans = Sol.totalFruit(a);
    cout << ans << endl;
    return 0;
}