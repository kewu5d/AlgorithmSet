/*
 * @lc app=leetcode.cn id=3679 lang=cpp
 *
 * [3679] 使库存平衡的最少丢弃次数
 * //w：天数窗口长度
    //m：数字类型最多出现次数
    //arrivals[]：编号既是物品类型
    //返回w窗口内，满足m，最少需要丢弃的物品数量
 */

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        unordered_map<int, int> n_cnt;
        int diu = 0;
        //注意：天数从1开始，但下标还是从0开始存数
        for (int i = 0; i < arrivals.size(); i++)
        {
            n_cnt[arrivals[i]]++;           // 1. 新物品进入窗口
            if (n_cnt[arrivals[i]] > m)     // 2. 检查是否超限
            {
                n_cnt[arrivals[i]]--;       // 3. 撤销计数
                diu++;                      // 4. 答案：丢弃计数+1
                arrivals[i] = 0;            // 5. 标记为已丢弃（关键！）
                                            //这里标记为-1会更加清楚
            }
            if (i-w+1 < 0) continue;        // 6. 窗口未满，继续扩张
    
            n_cnt[arrivals[i-w+1]]--;       // 7. 窗口左端物品滑出
                                            //（理解！）右端已经丢弃的物品不能重复丢弃，所以标记后的品种滑出不会影响后续判断
        }
        return diu;
        //贪心：滑入一个物品，正好>m。
        //- 此时：1.丢弃这个 2.希望之前就丢弃过（预言家），让这个得以保留
        //解：很显然，万一预言失败了，得到的就不是最少丢弃次数，WA。
        //- 理解：预言家如何实现，类似于时空倒流到哪个物品的那天，把它丢弃？
        //从这个角度想，也知道实现起来很奇思妙想。故采用贪心实现1.方法
    }
};

// @lc code=end


int main()
{
    Solution sol;
    vector<int> a = {10,4,3,6,4,5,6,1,4};//天数从 1 开始编号

    int res = sol.minArrivalsToDiscard(a, 7, 1);
    cout << res << endl;
    return 0;
}

