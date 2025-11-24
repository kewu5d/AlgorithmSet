#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);//比cin更快

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // 1. 先对初始数据排序
    sort(a.begin(), a.end());

    // q1 存放初始排序后的果子
    queue<int> q1;
    for (int x : a) q1.push(x);

    // q2 存放合并后产生的新果子
    queue<int> q2;

    long long ans = 0;

    // 执行 n-1 次合并---不同于优先队列判断队列元素个数了！！！
    for (int i = 0; i < n - 1; i++) {
        long long x, y;

        // 取第一个最小数
        if (q2.empty() || (!q1.empty() && q1.front() < q2.front())) {
            x = q1.front();
            q1.pop();
        } else {
            x = q2.front();
            q2.pop();
        }

        // 取第二个最小数
        if (q2.empty() || (!q1.empty() && q1.front() < q2.front())) {
            y = q1.front();
            q1.pop();
        } else {
            y = q2.front();
            q2.pop();
        }

        // 合并并加入消耗
        ans += (x + y);
        // 将新的一堆放入 q2，q2 依然保持单调性
        q2.push(x + y);
    }

    printf("%lld\n", ans);
    return 0;
}
/*
总结
- 优先队列：适合动态插入，代码编写简单，通用性强。
- 另一种做法：双队列：
	利用了本题中“每次取最小合并”产生的和具有单调性的特点，
	运行效率略高于优先队列。
*/
