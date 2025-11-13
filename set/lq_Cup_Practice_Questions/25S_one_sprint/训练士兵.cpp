#include <iostream>
#include <limits.h>
#define ll long long
using namespace std;
const ll N = 1e6+5;
ll n, p[N], c[N], s;
ll allone, sum, cnt[N];//分别表示：全单训一次、全部单训、需要训练N次的士兵花销 
int main()
{
	cin>>n >> s;//集训次数 
	ll maxcnt = 0;//士兵中最多训练次数 
	for (int i=1;i<=n;i++)
	{
		cin >> p[i] >> c[i];//第i名，单独训练，所需次数 
		if(maxcnt < c[i]) maxcnt = c[i];
		sum += p[i]*c[i];
		allone += p[i];
		cnt[c[i]] += p[i];//***
	}
	//枚举+贪心：每一次全训一次是单训好还是集训好
	ll ans = 0;
	for (int i=1;i <=maxcnt; i++)
	{
		if (allone <= s){//直接单训得了 
			cout << sum+ans << endl;return 0;
		}
		//集训
		sum -= allone;//省单训 
		ans += s;//集训花销 
		allone -= cnt[i];//训i次就顶级了 
		
	}
	cout << sum + ans << endl;
	return 0;
	

	
}
