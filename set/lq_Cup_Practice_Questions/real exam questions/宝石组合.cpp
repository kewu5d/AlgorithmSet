#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
ll s, h[N], n;
struct res
{
	ll a, b, c;//下标 
	ll cnt;
}ans;
ll gcd(ll a, ll b)
{
	return b==0?a:gcd(b, a%b);
}
ll lcm(ll a, ll b)
{
	//a，b均大于1 
	return a*b/gcd(a, b);
}
ll lcm_pro(ll a, ll b, ll c) 
{
	return lcm(a, lcm(b, c));
}
int main()
{
	cin >> n;
	for (int i=1;i<=n; i++)cin >> h[i];
	sort(h+1, h+1+n);
	for (ll i=1; i<=n-2; i++)
	{
		for (ll j=i+1; j<=n-1; j++)
		{
			for (ll k=j+1; k<=n; k++)
			{
			//	ll temp = i*j*k * lcm_pro(i, j, k) / (lcm(i, j) * lcm(i, k) * lcm(j, k));
				//不是下标，是h值
				ll temp =  h[i]*h[j]*h[k] * lcm_pro(h[i], h[j], h[k]) / (lcm(h[i], h[j]) * lcm(h[i], h[k]) * lcm(h[j], h[k]));
				
				
//				if (temp == s)
//				{
//					//ans.cnt++;
//					continue;//跳过字典序更大的 
//				}
				if (temp > s) 
				{
					s = temp;
					ans.a = h[i];ans.b = h[j]; ans.c = h[k];
				}
				//s = max(s, temp);
				//ans.a = i;ans.b = j; ans.c = k;   写在这里，都会执行 
			}
		}
	}
	cout << ans.a << ' ' << ans.b << ' ' << ans.c << ' ';
	return 0;
}
