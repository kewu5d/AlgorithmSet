/*
思路：
- 先让第二支老鼠吃所有n块奶酪，然后分析如果第i块奶酪是给第一只老鼠吃，得分会更多，得分加reward1[i] - reward2[i]
- 我们对reward1[i] - reward2[i]进行排序，选出差距（得分增值）最大的k块给第一只老鼠吃
- 即可得到最大得分
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric> // 用于 accumulate----用于求和，这里没用它，多余
#include <functional> // for greater
//最好加上这一行，显式包含头文件。不加没报错说明被隐式包含了（不推荐）
using namespace std;

int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
    int n = reward1.size();
    int ans = 0;

    // 1. 先假设全部由第二只老鼠吃，并计算差值存储在 reward1 中（空间优化）
    for (int i = 0; i < n; i++) {
        ans += reward2[i];
        reward1[i] = reward1[i] - reward2[i]; // 复用 reward1 存储 gap
		//因为计算完差值后，原始的 reward1 数据就不再需要了。
		//这样可以省去额外的内存开销。
    }

    // 2. 使用 nth_element 找出前 k 大的差值（时间优化）
    // nth_element 平均时间复杂度为 O(N)，比 sort 的 O(N log N) 快
    // greater<int>() 使得较大的元素排在前面
    nth_element(reward1.begin(), reward1.begin() + k, reward1.end(), greater<int>());

    // 3. 累加前 k 大的差值
    for (int i = 0; i < k; i++) {
        ans += reward1[i];
    }

    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;//n块,老鼠一吃k块 
    vector<int> r1(n), r2(n);
    for (int i = 0; i < n; i++)
    {
        //cin >> r1[0];
        scanf("%d", &r1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &r2[i]);
    }
    int ans = miceAndCheese(r1, r2, k);
    printf("%d\n", ans);
    return 0;
}
/*
4 2
1 1 3 4
4 4 1 1

2 2
1 1
1 1
*/