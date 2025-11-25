/*
分析（题意）：
- n块奶酪都要吃完，同一块奶酪不同老鼠得分不同，第一只恰好吃k块，
	最大得分
思路：
- 先让第二支老鼠吃所有n块奶酪，然后分析如果第i块奶酪是给第一只老鼠吃，得分会更多，得分加reward1[i] - reward2[i]
- 我们对reward1[i] - reward2[i]进行排序，选出差距（得分增值）最大的k块给第一只老鼠吃
- 即可得到最大得分
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
	int gap[100005] = { 0 };//这里gap也可以是vector数组，在sort排序时，使用`begin()`、`end()`：获取迭代器 
	int n = reward1.size();
	for (int i = 0; i < n; i++)
	{
		gap[i] = reward1[i] - reward2[i];
	}
	sort(gap, gap+n);//******************一定要画图搞明白，排序区间 
	//答案
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += reward2[i];
	}
	//让第一只老鼠吃，弥补差距，扩大得分 
	while (k > 0)
	{
		ans += gap[n-1];
		n--;
		k--;
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
		cin >> r2[i];
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

