#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        //窗口-子数组
        //总和 - 子区间和 = x
        //子数组长度需要最大化，这样移除的元素个数是最少操作数
        int tot = reduce(nums.begin(), nums.end());
        int ans = 0, flag = 0, l, r, sum = 0;
        int n = nums.size();
        for (l=r=0; r < n; r++)
        {
            sum += nums[r];
            while(l <= r && tot - sum < x)
            {
                sum -= nums[l++];
            }
            if (tot - sum == x){
                flag = 1;
                ans = max(ans, r-l+1);
            }    
        }
        return flag?n-ans:-1;
    }
};

int main()
{
    Solution Sol;
    vector<int> a = {1,1,4,2,3};
    int ans = Sol.minOperations(a, 5);
    cout << ans << endl;
    return 0;
}