#include <iostream>
#define int long long
using namespace std;
int t, k, n, m;
int ans[2005][2005];
int c[2005][2005];
signed main()
{
	cin >> t >> k;
	//重要
	for(int i=0; i<=2000; i++) {
		c[i][0] = 1;//单独处理 
	}
	
	//在while询问外，初始化所有
	for (int i=1; i<=2000; i++)
	{
		for (int j=1; j<=2000; j++)
		{
			c[i][j] = (c[i-1][j] + c[i-1][j-1]) % k;//避免超过存储范围
			if (c[i][j] == 0 && j <= i) ans[i][j]++;
			ans[i][j] = ans[i][j-1] + ans[i-1][j] -ans[i-1][j-1] + ans[i][j];
		}
	}
	while (t--) 
	{
		cin >> n >> m;
		cout << ans[n][m] << endl;
	}
	return 0;
}
