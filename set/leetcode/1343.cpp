/*
 * @lc app=leetcode.cn id=1343 lang=cpp
 *
 * [1343] 大小为 K 且平均值大于等于阈值的子数组数目
 */

 #include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;


// @lc code=start
#define ll long long
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        ll l = 0, r = k - 1;
        threshold *= k;//原地求和
        ll sum = 0, res = 0;
        for (int i = l; i <= r; i++)
        {
            sum += arr[i];
        }
        if (sum >= threshold)res++;
        r++;
        for (; r < arr.size(); r++, l++)
        {
            sum += arr[r];
            sum -= arr[l];
            if (sum >= threshold)res++;
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution Sol;
    vector<int> arr = {2, 2, 2, 2, 5, 5, 5, 8};
    int ans = Sol.numOfSubarrays(arr, 3, 4);
    cout << ans << endl;
    return 0;
}
