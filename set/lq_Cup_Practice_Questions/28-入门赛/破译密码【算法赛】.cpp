#include <bits/stdc++.h>
using namespace std;
struct node
{
	int a, b;
	int no;
}c[1005];
int n;
vector<node> x, y;//按Johnson算法分为两部分 
bool cmp1(node t1, node t2)
{
	return t1.a < t2.a;
}
bool cmp2(node t1, node t2)
{
	return t1.b > t2.b;
}
int main()
{
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> c[i].a;
		c[i].no = i;
	}
	for (int i=1; i<=n; i++)cin >> c[i].b;
	for (int i=1; i<=n; i++)
	{
		if (c[i].a <= c[i].b)
		{
			x.push_back(c[i]);
		}
		else y.push_back(c[i]);
	}
	sort(x.begin(), x.end(), cmp1);
	sort(y.begin(), y.end(), cmp2);
	//模拟甘特图---芯片处理顺序x.no-->y.no
	int temp[1005] = {0};
	for (int i=0; i<x.size(); i++)temp[i] = x[i].no;
	for (int i=x.size(), j=0; j<y.size(); j++)
	{
		temp[i+j] = y[j].no;
	}
	//模拟
	int atime=0, btime=0;
	for (int i=0; i<x.size()+y.size(); i++) 
	{
		atime += c[temp[i]].a;
		if (btime < atime){
			btime = atime;//需要等 
		}
		btime += c[temp[i]].b;
	}
	cout << btime << endl;
	return 0;
}
