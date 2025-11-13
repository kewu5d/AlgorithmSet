/*
注意点：至少选择士兵数，确保能组成k个纯职业小组
		这里的要确保，所以并不是仅仅至少
		就是选i个，无论如何都能组成 
	
思路：大雨中，认不清职业，最坏的情况就是每次都没连续选上同一职业的士兵 
 
错误点：使用i来代替bi，也就是职业编号 ???????????????
*/

#include <iostream>
#include <cstdio>
#include <vector>
#define ll long long 
using namespace std;
//ll a[10005];//同一职业人数 //职业数>=10^9,    使用vector存ai会更稳妥 
//ll b[10005];//职业数 
int main()
{
	vector<ll> ai, ans;
	ai.push_back(-1);//从1开始存储 
	ans.push_back(-1);
	int n;//n组数据，就要进行n次判断
	cin >> n;
	int nn = n;
	ll nt;
	ll k;
	//
	//int anss[n+1];
	while (n--) 
	{
		int sumx = 0;//总士兵数 
		cin >> nt >> k;
		for (int i=1; i<= nt; i++) 
		{
			int x,y;
			cin >> x;//职业编号 
			cin >> y;//bi号职业的人数
			ai.push_back(y);
			ans.push_back(0);
			sumx += y;
		}
		int sumxxx = sumx;
		int  idx = 0;
		if (sumxxx < k*3)
		{
			cout << -1 << endl;
			break;
		}
		while (sumx)
		{
			for (int i=1; i<= nt; i++)
			{
				if (ai[i] > 0)
				{
					ai[i]--;
					ans[i]++;//选过来 	
					sumx--;
				}
				else break;
				if (ans[i] >= 3 && ans[i]%3 == 0) 
				{
					idx++;
					if (idx == k)
					{
						cout << sumxxx-sumx << endl;
						//anss[n--] = sumxxx-sumx;
						break;
					}
				}
			}
			if (idx == k)
			{
				break;
			}
		}
		if (idx != k)cout << -1 << endl;
		//anss[n--] = -1;
	}
//	for (int i = nn; i> 0 ;i--)
//	{
//		printf("%d\n", anss[i]);
//	}
	return 0;
}
