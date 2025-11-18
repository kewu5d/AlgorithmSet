#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
ll ksmi(ll a, ll b, ll p )
{
	//两步：1、对指数b转换二进制；2、对a^b按二进制进行拆分 
	ll ans = 1;
	while (b != 0)
	{
		//除2取余
		int x = b%2 ;//从左往右数第一位
		b /= 2;
		if (x == 1) 
		{
			ans = (a * ans);
		}
		a = (a*a);//下一位，a^2 
	}
	return ans;
}
int main()
{
	ll a, b, p;
	cin >> a >> b >> p;
	ll ans = ksmi(a, b, p);
	cout << a << "^" <<b << " mod " << p << "=" << ans%p << endl;
	return 0;
}
