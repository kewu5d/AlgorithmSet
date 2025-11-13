#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N = 1e5+5;
ll a[N], n, k, ans;
int main()
{
	cin >>n>>k;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i]; a[i] +=a[i-1];
	}
	for (int l=1; l<=n; l++)
	{
		for (int r=l; r<=n; r++)
		{
			if( (a[r] - a[l-1])%k == 0 )ans++;
		}
	}
	cout << ans << endl;
	return 0; 
	
}
