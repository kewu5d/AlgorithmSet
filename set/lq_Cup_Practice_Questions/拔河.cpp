#include <iostream>
#include <cstdio>
#include <algorithm>
#include <limits.h>
#include <cmath>
#define ll long long
using namespace std;
int a[105];
//long long suma[105] ;
int main()
{
	int n;cin>>n;
	for (int i=1; i<=n; i++)cin >> a[i];//第i名同学的力量
	//for (int i=1; i<=n; i++)suma[i] = suma[i-1] + a[i];

	ll minans = INT_MAX; 
	for (int l=1; l<n; l++)
	{
		for (int r=n; r>l; r--)
		{//初始化左右端点的起始位置-------可以不全选，但要保证原有顺序
			 int i=l,j=r;//使用i，j来扩大两个队伍 
			 ll sum1 = a[i], sum2 = a[j];
			 while (i < j)
			 {
			 	if (sum1 == sum2)
				{
					cout << 0 << endl;
					return 0;
				}
				else if (sum1 < sum2)
				{
					minans = min(minans, abs(sum1-sum2));//abs绝对值 
					sum1 += a[++i];
				}
				else {
					minans = min(minans, abs(sum1-sum2));
					sum2 += a[--j];
				} 
			 }
		}
	}
	cout << minans << endl;
	return 0;
}
