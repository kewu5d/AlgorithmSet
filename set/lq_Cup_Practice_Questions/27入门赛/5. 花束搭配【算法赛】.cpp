#include <iostream>
#include <algorithm>	//
#define ll long long
using namespace std;
const int N = 2e5+10;
ll a[N], b[N], c[N];//c存a-b 
int main()
{
	int n;cin >> n;
	if (n==1)
	{
		cout << 0 << '\n';return 0;
	}
	for (int i=1; i<=n; i++)cin >>a[i];//wai
	for (int i=1; i<=n; i++)cin >>b[i];//内 
	//暴力----TLE(n*2过不了)
	ll ans= 0;
	for (int i=1; i<=n; i++)c[i] = a[i]-b[i];
	sort(c+1, c+n+1);
//	int l=1, r=n;//双指针 
//	while (l<r)
//	{
//		if (c[r]+c[l]>0)
//		{//c[l]:min, c[r]:max
//			ans += (r-l);//固定r，向l的组合都合法 
//			 r--;// 
//		}
//		else l++; 
//	}
	for (int i=1; i<=n; i++)
	{
		int cnt = lower_bound(c+1, c+n+1, -c[i]) - c+1;
		if (-c[i] > 0)cnt--;
		ans+= cnt;
	}
	cout << ans*2 << '\n';
	return 0;
}
