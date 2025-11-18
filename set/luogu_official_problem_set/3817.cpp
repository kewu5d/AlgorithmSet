#include <iostream>
#define ll long long 
using namespace std;
ll n, x, a[100005], ans;
int main()
{
	cin >> n >> x;
	for (int i=1; i<=n;i++) cin >> a[i];//1~n, a[0]:0
	
	for (int i=1; i<=n; i++)
	{
		if (a[i] + a[i-1] > x)
		{//吃右边那盒糖果 ---影响左边，和下一组的右边
			ans += a[i]  + a[i-1] - x;//吃掉的糖果数
			a[i] = x - a[i-1];
			
		}
	}
	cout << ans << endl;
	return 0;
}
