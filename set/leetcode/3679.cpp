/*
 * @lc app=leetcode.cn id=3679 lang=cpp
 *
 * [3679] 使库存平衡的最少丢弃次数
 */

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        //w：天数窗口长度
        //m：数字类型最多出现次数
        //arrivals[]：编号既是物品类型
        //返回wck内，满足m，最少需要丢弃的物品数量
        unordered_map<int, int> n_cnt;//数字类型次数
        int diu = 0;//, res = arrivals.size()+1;
        //注意：天数从1开始，但下标还是从0开始存数
        for (int i = 0; i < arrivals.size(); i++)
        {
            n_cnt[arrivals[i]]++;
            if (n_cnt[arrivals[i]] > m)
            {
                n_cnt[arrivals[i]]--;
                diu++;
                arrivals[i] = 0;
                //品种0不存在/不合法，表示这一个品种已经被丢弃。
                //后续缩窗口的时候，品种0数量减一不影响、不会重复丢弃该天的原品种个数
            }
            if (i-w+1 < 0)continue;
            //res = max(diu, res);

            n_cnt[arrivals[i-w+1]]--;
            //当末尾的数，在扩的时候被丢弃了
        }
        return diu;

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

