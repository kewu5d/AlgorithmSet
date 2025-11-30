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
    //法二：正向思维--假设全部正着拿。要想最大化，就使倒着拿替换后的和最大化即可
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        // 先计算取前 k 张的分数
        int sum = 0;//求和可以用reduce或者accumulate完成
        for (int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }
        int ans = sum;
        // 逐步用后面的牌替换前面的牌
        // 即：减少前面取的，增加后面取的
        for (int i = 1; i <= k; i++) {
            sum -= cardPoints[k - i];      // 减去前面第 k-i 张
            sum += cardPoints[n - i];      // 加上后面第 i 张
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
