#include <iostream>
#define int long long
using namespace std;
int n, k, a[100005], ans;
int like[100005];//对k取模的余数，首次出现标记为1，再出现说明该区间为k倍区间 
				//记录余数i出现的次数，下次出现时k倍区间数+出现次数 ，出现次数再+1
signed main()
{
	cin>>n >> k;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i];
		a[i] += a[i-1];//自前缀 
		a[i] %= k;
	}
	//O(n^2)：10^10,限时两秒2*10^8，肯定会超时的 
//	for (int l=1; l<=n; l++)
//		for (int r=n ; r>=l; r--)
//			if ((a[r] - a[l-1]) %k == 0)ans++;
	like[0] = 1;//注意余数0最开始就有，相当于前i个数为k倍子区间 
	for(int i=1; i<=n; i++)
	{
		if(like[a[i]] == 0)like[a[i]]++;//记录首次出现位置
		else {
			ans += like[a[i]];
			like[a[i]]++;
		}
	}
	
	cout << ans << endl;
	return 0;
}
