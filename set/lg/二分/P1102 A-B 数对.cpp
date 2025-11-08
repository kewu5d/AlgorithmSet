#include <iostream>
#include <cstdio>
#include <map>
#define ll long long
const int N = 2e5 +5;
using namespace std;
ll n, a[N], c;
map<ll, ll> mp;
int main()
{
	scanf("%lld %lld", &n, &c);
	for (int i=1;i <=n;i++){
		scanf("%lld", &a[i]);
		mp[a[i]]++;
		//a[i] -= c;
	}
	ll ans = 0;
	for (int i=1; i<=n; i++)
	{
		ans += mp[a[i] + c];
	}
	printf("%lld\n", ans);
	return 0;
	
}
