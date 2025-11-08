#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const ll mod = 1e9+7;//对这个数取余，操作均为ll 
const ll N = 1e5+5;
ll a[N], n, num[N];//num为该长度的火柴数 
ll C(ll a, ll b)
{//组合1和2就可以了 
	return (b==1LL?a:a*(a-1LL)/2LL) %mod;//到处疯狂取mod 
}
int main()
{
	cin >> n;
	ll maxlen=0;
	for (int i=1; i<=n;i++)
	{
		cin>>a[i];
		maxlen = max(a[i], maxlen);
		num[a[i]]++;
	}
	ll ans = 0;//方案数 
	//暴力枚举长度 
	for (int i=2; i<=maxlen; i++)
	{
		ll temp;
		//乘法原理--temp*(temp2)
		
		if(num[i] >=2LL)
		{
			temp = C(num[i], 2LL) % mod;
			//外层能挑出两根，才可以进入内循环挑另外两根组合成第三根 
			for (int j=1; j<=i/2; j++) 
			{
				if (j ==i-j && num[j]>=2LL)ans+= temp * C(num[j], 2LL) % mod;//两根j凑一根i 
				else if (j!=i-j && num[i-j]>=1LL && num[j]>=1LL)
				{//&&num，有这长度的才能选吖 
					ans += temp * C(num[j], 1LL)*C(num[i-j], 1LL) % mod;
				}
				ans %= mod;//有没有符合的火柴，对ans取余没有影响 
			}
		} 
		
	}
	cout << ans%mod << endl;
	return 0;
	
	
}
