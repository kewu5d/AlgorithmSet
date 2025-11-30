/*
 * @lc app=leetcode.cn id=1423 lang=cpp
 *
 * [1423] 可获得的最大点数
 */

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;


// @lc code=start
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //将数组复制一份，**尾-首**拼在一起
        int n = cardPoints.size();
        vector<int> arr(2*n);
        for (int i=0; i<n; i++)
        {
            arr[i] = cardPoints[i];//不要漏了
            arr[i+n] = cardPoints[i];
        }
        
        int l = 0, r = k-1, sum = 0, ans = 0;
        for (int i=l; i<=r; i++)
        {
            sum += arr[i];
        }
        if (n-1 <= r && r <= n-1+k)//check
            ans = max(ans, sum);
        for (r++; r < arr.size(); r++,l++)
        {
            sum += arr[r];
            sum -= arr[l];
            if (n-1 <= r && r <= n-1+k)
                ans = max(ans, sum);
        }
        return ans;

    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<int> a = {1, 2, 3, 4, 5, 6, 1};
    int res = sol.maxScore(a, 3);
    cout << res << endl;
    return 0;
}
