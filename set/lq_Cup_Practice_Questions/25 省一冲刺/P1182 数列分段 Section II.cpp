


//一眼二分答案

#include <iostream> 
#define ll long long
using namespace std;
ll n, m, a[100005];
bool check(ll x)
{
	int cnt = 1, sum = 0;
	for (int i=1; i<=n; i++)
	{
		if (a[i] > x) return true;//猜小了 
		if (sum + a[i] > x)
		{
			sum = a[i];//以a[i]为第一个新开一段 
			cnt++;
		}
		else sum += a[i];
	}
	return cnt > m;//猜小了 
}
int main()
{
	cin >> n >> m;
	for (int i=1;i<=n;i++)cin >> a[i];
	
	ll l = 0, r = 1e14, mid;
	while (l <=r)
	{
		mid = (l+r)/2;
		if (check(mid))
		{//分多了，猜小了 
			l = mid+1;
		}
		else  r = mid-1;//猜大了 
	}
	cout << l << endl;
	
	return 0;
}
