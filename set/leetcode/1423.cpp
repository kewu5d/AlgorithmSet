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
    //法一：逆向思维--最小化剩余n-k张牌点和
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int m = n - k;
        //这里前m项和[0,m)，在for循环外已经利用reduce求好了
        int s = reduce(cardPoints.begin(), cardPoints.begin() + m);
        int min_s = s;
        for (int i = m; i < n; i++) {
            s += cardPoints[i] - cardPoints[i - m];//扩缩一步到位
            min_s = min(min_s, s);
        }
        return reduce(cardPoints.begin(), cardPoints.end()) - min_s;
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
