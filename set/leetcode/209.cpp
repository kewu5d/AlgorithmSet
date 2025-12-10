#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = n+1, l, r, sum = 0;
        for (l=r=0; r < nums.size(); r++)
        {//还是一样枚举右端点
            sum += nums[r];
            while (sum >= target)
            {//合法-->更新答案--->缩小，找更小的合法区间（答案）
                ans = min(ans, r-l+1);
                sum -= nums[l++];//缩小
            }
        }
        return ans>n? 0: ans;
    }
};

int main()
{
    Solution Sol;
    vector<int> a = {2,3,1,2,4,3};
    int ans = Sol.minSubArrayLen(7, a);
    cout << ans << endl;
    return 0;
}