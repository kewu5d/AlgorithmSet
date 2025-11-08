#include <iostream>
#include <algorithm>
using namespace std;

int n, s[15], b[15], minans = 1e9+5;
int vis[15];
//int si, bi;//s乘积， b相加
//该调料是否添加，至少添加一种即选或不选 ，不可以都不选 
void dfs(int step, int si, int bi)
{
	if (step > n)
	{
		if (si == 0 && bi == 0)return;//不可以不添加
		else{
			if (si > bi)minans = min(si-bi, minans);
			else minans = min(minans, bi-si);
		}
		return; 
	}
	
 	for (int i=1; i<=n; i++) 
 	{
 		if (vis[i] == 1)continue;
 		for (int j=0; j<=1; j++)
 		{//选或不选 
 			if (j == 0)
 			{//不选 
 				vis[i] == 1;//但是访问过哈 
 				dfs(step+1, si, bi);
 				vis[i] == 0;
			}
			else {
				vis[i] = 1;
				
				//bi += b[i];
				if (si == 0)
					dfs(step+1, s[i], bi+b[i]);
				else dfs(step+1, si*s[i], bi+b[i]);
				
				vis[i] = 0;
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> s[i] >> b[i];

	dfs(1, 0, 0);
	cout << minans << endl;
	return 0;
}
