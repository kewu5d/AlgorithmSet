#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int suf[5005] = {6000};//suf[0]=0的话最左边没有志愿服务点 
int rsuf[5005];
int main()
{
	int n;cin >> n; 
	string s;cin >> s;
	for (int i=0; i<n; i++)
	{
		if (s[i]='0' && i==n-1)	
		{
			cout << -1 << endl;return 0;
		}
		else if (s[i]=='1')break;
	}
	for (int i=0; i<n; i++)
	{
		if (s[i]=='1')
		{
			suf[i] = i;//最近的志愿服务点 
		}
		else if (i-1 >=0)
		{
			suf[i] = suf[i-1];//左边最近的 
		} 
	}
	rsuf[n-1] = 6000;//最右边没有志愿服务点
	for (int i=n-1; i>=0; i--) 
	{
		if (s[i]=='1')
		{
			rsuf[i] = i;
		}
		else if (i+1 <n)
		{
			rsuf[i] = rsuf[i+1];//右边最近 
		}
	}
	for (int i=0; i<n; i++)
	{
		if (s[i] == '0')
		{
			cout << min(i-suf[i], rsuf[i]-i) << ' ';
		}
	}
	
	cout << endl;
	return 0;
}
