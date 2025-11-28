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
        //1.维护区间和
        //2.判断前后是否越界，填数
        int n = nums.size();//下标兼个数
        vector<int> avgs(n);
        ll now = 0, sum = 0;//sum：[now-k,now+k]的和
        //ll l = now-k, r = now+k;
        for (int i = now-k; i <= now+k; i++)
        {
            if (i < 0 || i >= n)
            {//越界
                sum += 0;
            }
            else sum += nums[i];
        }
        if (now-k < 0 || now+k >= n)
            avgs[now] = -1;
        else avgs[now] = sum / (2 * k + 1);//外面已经填数一次（窗口）
        //for循环里面开始填剩下n-1次
        for (; now < n; )
        {
            //1.维护sum
            if (now-k < 0)
            {}
            else sum -= nums[now-k];
            now++;
            if (now >= n)
                break;//完成了遍历，避免越界
            //没有完成，继续右移
            if (now+k >= n)
            {}
            else sum += nums[now+k];

            //2.填入
            if (now-k < 0 || now+k >= n)
                avgs[now] = -1;
            else avgs[now] = sum / (2 * k + 1);
        }
        return avgs;
    }
};
// @lc code=end

