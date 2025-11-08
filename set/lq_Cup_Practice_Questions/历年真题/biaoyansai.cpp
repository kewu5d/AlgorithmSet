#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6+5;
int a[N], sum[N];
int main()
{
	int n,k;cin >>n>> k;//选k人 
	for (int i=1;i <=n;i++)	cin >>a[i];
	sort(a+1,a+n+1);
	for (int i=1; i<=n;i++)sum[i]=sum[i-1]+a[i];
//	if (k == 1)
//	{
//		cout << 0 << endl;
//		return 0;
//	}
	//先计算出第一个窗口的差异值
	long long ans=1e18, temp = 0, r=k;
	for (int i=r; i>=1; i--) 
	{
		for (int j=1; j<i; j++)
		{
			temp += a[i]-a[j];
		}
	}
	//cout << temp << endl; 
	ans = min(ans, temp);
	//滑动
	for (int i=2; i<=n-k+1; i++)
	{
		
		temp -= ((sum[r]-sum[i-1])-(k-1)*a[i-1]);//剔除i-1的贡献 
		temp += ((k-1)*a[r+1] - (sum[r]-sum[i-1]));//添加上r+1的贡献 
		ans = min(ans, temp);
		r++;
	}
	cout << ans << '\n';
	return 0;
}
