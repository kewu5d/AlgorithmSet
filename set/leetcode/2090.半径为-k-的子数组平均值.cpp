/*
 * @lc app=leetcode.cn id=2090 lang=cpp
 *
 * [2090] 半径为 k 的子数组平均值
 */

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;


// @lc code=start
#define ll long long
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();//下标兼个数
        vector<int> avgs(n, -1);
        ll sum = 0;//sum：[now-k,now+k]的和
        for (ll i = 0; i < n; i++)
        {//这个i是整个窗口的最右端--无论这是什么样子的窗口
            //1.扩
            sum += nums[i];//最右端i
            if (i < 2 * k)continue;

            //2.更新: i-k才是我们要的合法区间的中间元素
            avgs[i-k] = sum / (2 * k + 1);//其余都是已经初始好的-1

            //3. 缩
            sum -= nums[i-k-k];//最左端i-2*k
        }
        return avgs;
    }
};
// @lc code=end

