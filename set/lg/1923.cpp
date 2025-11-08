#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
const ll N = 5e6 + 7;
ll n, a[N], k;
int main()
{
	//cin >> n >> k;//第k小
	scanf("%lld %lld", &n, &k);
	for (ll i=0; i<n; i++) scanf("%lld", a+i);
	nth_element(a, a+k, a+n);//重新排列 
	//cout << a[k] << endl;
	printf ("%lld\n", a[k]);
	return 0;
}
