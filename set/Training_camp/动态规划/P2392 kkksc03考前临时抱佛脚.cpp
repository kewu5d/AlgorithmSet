//两道题一起做，取耗时多的，同一科，做完一科，继续坐下一道题（有的话） 
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int s[5], tm[5][25];//s表示第i科的题目数,tm表示耗时 
int main()
{
	cin >> s[1] >>s[2]>>s[3]>>s[4];
	for (int i=1; i<=4; i++)
	{	
		for (int j=1; j<=s[i]; j++)
			cin >> tm[i][j];	
	}
	int ans=0;int l, r;//左右脑耗时 
	for (int i=1; i<=4;i++)
	{
		l=r=0;
		int x=s[i];
		sort(tm[i]+1, tm[i]+x+1);
		//这里用了贪心，但是只保证了区部最优，保证不了这一科的全局最优 
		while (x>=1)
		{
			if (l<=r)l += tm[i][x];//脑有余地 
			else	r += tm[i][x];
			x--;
		}
		ans += max(l,r);
	}
	cout << ans;
	return 0;
}
 
