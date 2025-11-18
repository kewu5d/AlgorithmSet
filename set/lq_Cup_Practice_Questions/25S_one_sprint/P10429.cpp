
/*
两队伍编号连续 
可以有队员不选！！！ 
- 左队伍：
	枚举左端点，右端点不定
	
- 右队伍：
	枚举右端点，左端点不定，但必须大于左队伍的右端点 

队伍内的力量之和：前缀和优化

找出差距最小的选队伍方式 ，输出最小差距
*/

#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll n, a[1005], suma[1005];
ll minans = 1e18;
int main()
{
	cin >> n;
	for (int i=1; i<=n;i++) 
	{
		cin >> a[i];
		suma[i] = suma[i-1] + a[i];
	}
	//l -- i --- j---r
	for (int l=1; l<n; l++)
	{
		for (int r=n; r>l; r--)
		{
			int i=l;//左队伍的右端点i 
			int j=r;//右队伍的左端点j
			//用这两个指针来扩大左右队伍，使得二者力量差最小
			ll s1 = a[i];
			ll s2 = a[j];//力量 
			while (i < j)
			{
				if (s1 == s2)
				{
					cout << 0 << endl;
					return 0; 
				}
				else if (s1 > s2)
				{
					minans = min(minans, s1-s2);
					s2 += a[--j];
				}
				else {
					minans = min(minans, s2-s1);
					s1 += a[++i];
				}
			}
		}
	}
	cout << minans << endl;
	
	return 0;
}
