#include <iostream>
#include <cstdio>
#include <queue> 
#define ll long long
using namespace std;
ll ans;
int main()
{
	//数字小的优先级更大 
	priority_queue<int, vector<int>, greater<int>> q;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		q.push(x);//一次排序O(logn)
	}
	//每次合并找最小的两堆，倒着 
	int t;
	while (q.size() != 1)
	{
		t = q.top();//查看队首
		q.pop();
		t += q.top();//本次第二少的堆
		q.pop();
		q.push(t);
		ans += t;
	}
	//q.size() == 1，不用搬
	printf("%d\n", ans);
	return 0;
	
}
/*
总结
- 优先队列：适合动态插入，代码编写简单，通用性强。
- 另一种做法：双队列：
	利用了本题中“每次取最小合并”产生的和具有单调性的特点，
	运行效率略高于优先队列。
*/
