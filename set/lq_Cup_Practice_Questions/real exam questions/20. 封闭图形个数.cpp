/*1、2、3、5、7
0、4、6、9
8
先判断封闭图个数 是否相同
不同： 图数多者大
相同：数值大则大
时间复杂度要控制在O（nlogn） ----快速排序、 
*/
#include <iostream> 
#define ll long long 
#include <cstdio>
#include <vector>
#include <algorithm> 
using namespace std;
int cnt(ll a)
{
	int c = 0;
	while (a != 0)
	{
		int x = a % 10;
		if (x == 8)
		{
			c += 2;
		}
		else if(x == 0 || x == 4 || x == 6 || x == 9)
		{
			c++;
		}
		a /= 10;
	}
	return c;
}
bool cmp(ll a, ll b)
{
	if (cnt(a) != cnt(b))
	{
		return cnt(a) < cnt(b);
	}
	else
	{
		return a < b;
	}
}
int main()
{
	int n;cin >> n;
	vector<ll> a;
	for (int i = 1; i<=n; i++)
	{
		int x;cin >> x;
		a.push_back(x);
	}
	vector<ll>::iterator it = a.begin();
//	cout << *(it+n-2);
	sort(it, it+n, cmp);
	for (int i = 0; i<n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
