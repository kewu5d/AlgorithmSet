#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
char a[55][55];
int w[55], b[55], r[55];
int main()
{
	cin >> n >> m;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] != 'W')
			{
				w[i]++;//第i行涂成W的涂色次数 
			}
			if (a[i][j] != 'B') b[i]++;
			if (a[i][j] != 'R') r[i]++;
		}
		w[i] += w[i-1];
		b[i] += b[i-1];
		r[i] += r[i-1];
	}
	
	
	//meiju
	int ans = 25000, temp =0;
	for (int i=1; i<=n-2; i++) 
	{
		for (int j=i+1; j<=n-1; j++)
		{
		
			temp += w[i] - w[0];
			temp += b[j] - b[i];
			temp += r[n] - r[j];
			ans = min(ans, temp);
			temp = 0;
		}
	}
	cout << ans << endl;
	
	return 0;
}
