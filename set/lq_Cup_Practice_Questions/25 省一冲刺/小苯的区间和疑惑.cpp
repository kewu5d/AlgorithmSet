#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 +5;
ll a[N];
ll suf[N];
ll pre[N];
int main()
{
	int n;cin >> n;
	for (int i=1;i<=n; i++)
	{
		cin >> a[i];a[i] +=a[i-1];
	}
	//for (int i=1;i<=n; i++)cout << a[i] << ' ';cout << endl;
	
	//含i的区间和最大，即sum(r) - sum(l-1)最大
	//即i右边所有最大sum值，i左边最小sum值
	//前缀和的后缀最值 ，--------------------------类似求前缀和的求法
	
	//pre[0] = INT_MAX;如果这里为了接下来的比较初始化为尽可能大值，在输出时，按照实例常识就要赋值回0 
	suf[n+1] = -1e18;
	for (int i=1; i<=n; i++)
	{
		pre[i] = min(pre[i-1], a[i]);//前缀和的前缀最小（前缀和）值 
	//	suf[i] = max(suf[i+1], a[i]);//前缀和的后缀最大（前缀和）值 
	}
	for (int i=n;i>0; i--)//从后往前 ----------------`!!!
	{
		suf[i] = max(suf[i+1], a[i]);
	}
	//pre[0] = 0;//实际意义 
	for (int i=1; i<=n; i++) 
	{
		cout << suf[i]-pre[i-1] << ' ';////含i的最大区间和
	}
	//cout << endl;
	return 0;
}
