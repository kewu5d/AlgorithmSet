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
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		q.push(x);
	}
	//每次找最小，倒着 
	int t;
	if (q.size() == 1)
	{
		printf("%d\n", q.top());
	}
	while (q.size() != 1)
	{
		t = q.top();//查看队首
		q.pop();
		t += q.top();
		q.pop();
		q.push(t);
		ans += t;
	}
	
	printf("%d\n", ans);
	return 0;
}
