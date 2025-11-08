//如果连 1cm 长的小段都切不出来，输出 0
#include <iostream>
#define ll long long
//#define int long long
using namespace std;
const int N = 1e5+5;
ll k, t[N];
int main()
{
	int n; cin >> n >> k;
	ll maxlen = 0;
	for (int i=1;i <=n;i++){
		cin >> t[i];
		if (t[i]>maxlen)maxlen = t[i];
	}
	ll l  = 1, r = maxlen, mid;
	while (l <=r)
	{
		mid = (l+r)/2;
		ll cnt = 0;
		for (int i=1;i <=n;i++){
			cnt += t[i] / mid;
		}
		if (cnt >= k)l = mid+1;
		else r = mid-1;
	}
	cout << l-1 << endl;
	return 0;
}
