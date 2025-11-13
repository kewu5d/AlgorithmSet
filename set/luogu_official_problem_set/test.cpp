#include <iostream>
using namespace std;
int t, k, n, m;
int c[2005][2005];//组合数---递推公式 
int sum[2005][2005];//答案前缀和 
int main()
{
	cin >> t >> k;//k = [2,21]
	for (int i=0; i<=2000;i ++) c[i][0] = 1;
	for (int i=1; i<=2000; i++)
	{
		for (int j=1; j<=2000; j++)
		{
			c[i][j] = (c[i-1][j] + c[i-1][j-1]) % k;//在这里取模 
			if (j<=i && c[i][j]==0)
			{
				sum[i][j]++;
			}
			sum[i][j] = sum[i][j-1] + sum[i-1][j]-sum[i-1][j-1] + sum[i][j];
		}
	}
	while (t--)
	{
		cin >> n >> m;
		cout << sum[n][m] << endl;
	}
	return 0;
}
