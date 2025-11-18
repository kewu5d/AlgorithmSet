
//结构体排序+二分 

#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
struct node 
{
	int pos, cnt;
}a[100005];
ll n, q, m;

bool cmp(node x, node y)
{
	return x.cnt < y.cnt;
}
int main()
{
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i].cnt;
		a[i].pos = i;
	}
	sort(a+1, a+1+n, cmp);
	cin >> q;
	while(q--)
	{
		cin >> m;
		ll l = 1, r = n, mid, flag=0;
		while (l <= r)
		{
			mid = (l+r)/2;
			if (a[mid].cnt > m)r = mid-1;
			else if (a[mid].cnt < m)l = mid+1;
			else {
				flag = 1;break;//还是要多打括号 
			}
		}
		if (flag == 1)cout << a[mid].pos << endl;
		else cout << '0' << endl;
	}
	return 0;
}




