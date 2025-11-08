#include <iostream>
#include <cstdio>
#include <math.h>
#define ll long long
using namespace std;
//总S：9^10000	!3:8^10000	!7:8^10000	!3!7:7^10000
//根据容斥原理(画个venn图)：37:S - !3 - !7 + !3!7 
ll ksmi(ll a, ll b, ll mod) 
{
	ll ans = 1;
	while (b != 0)
	{
		int x = b % 2;
		b/=2;
		if (x == 1)
		{
			ans = (ans*a) % mod;
		}
		a = (a*a) % mod;
	}
	return ans;
}
int main()
{
	ll mod = 1e9 +7;
	ll ans = ksmi(9, 10000, mod) - ksmi(8, 10000, mod)*2 + ksmi(7, 10000, mod);
	cout << ans % mod << endl;
	return 0;
}
