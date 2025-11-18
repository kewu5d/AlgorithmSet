#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long ans;// 
int h[305];//h[0]也就是地面高度为0 
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		cin >> h[i];
	}
	//排序
	sort(h, h+n+1);//因为左闭右开，所以这里+1
	int t=n, b=0;
	while (b < t) 
	{
		ans += (h[t]-h[b]) * (h[t]-h[b]);
		b++;
		ans += (h[t]-h[b]) * (h[t]-h[b]);
		t--;
	}
	printf("%lld\n", ans);
	//cout << ans << endl;
	return 0;
}
