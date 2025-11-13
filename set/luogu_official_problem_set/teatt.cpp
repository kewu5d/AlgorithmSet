#include<iostream>
#define int long long
#define inf 2e9
#define debug cout << "zlqwq"
#define llinf 1e18

using namespace std;
int t,k,n,m,f[2005][2005],ans[2005][2005];
signed main() {
	cin >> t >> k;
	for(int i = 0;i <= 2000;++i) {
		f[i][0] = 1;
	}
	for(int i = 1;i <= 2000;++i) {
		for(int j = 1;j <= 2000;++j) {
			f[i][j] = (f[i - 1][j - 1] + f[i - 1][j]) % k;
			if(f[i][j] == 0 && i >= j) {
				ans[i][j]++;
			}
			ans[i][j] += ans[i][j - 1] + ans[i - 1][j] - ans[i - 1][j - 1];
		}
	}
	while(t--) {
		cin >> n >> m;
		cout << ans[n][m] << '\n';
	}
	return 0;
}

