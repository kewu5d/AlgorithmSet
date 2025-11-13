#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
int pushed[100005];
int poped[100005];
bool wedoit(int* pushed, int* poped, int l)
{
	stack<int> s;
	int i=0, j=0;
	while (l--)
	{//执行l次 
		if (s.empty() == 1 || 1)
		{//栈空，入栈 ;或者直接入栈 冗余代码 
			s.push(pushed[i]) ;
			i++; 
		}
		while (s.empty() == 0 && s.top() == poped[j])
		{//出栈 
			s.pop();
			j++;
		}
	}
	if (s.empty() == 0) 
	{
		return 0;//No 
	}
	else return 1;
	
}
int main()
{
	int q, l, x;//l为长度
	cin >> q;//询问次数
	while (q--)
	{//循环询问q次 
		cin >> l; 
		for (int i=0; i<l; i++)
		{
			cin >> x;
			pushed[i] = x;
		}
		for (int i=0; i<l; i++)
		{
			cin >> x;
			poped[i] = x;
		}
		int ans = wedoit(pushed, poped, l);
		//防止骗分，更新，为下次测试 点做准备 
		memset(pushed, 0, sizeof(pushed));
		memset(poped, 0, sizeof(pushed));
		if (ans == 1)
		{
			cout << "Yes" << endl;
		}
		else cout << "No" << endl;
	}
	
}
