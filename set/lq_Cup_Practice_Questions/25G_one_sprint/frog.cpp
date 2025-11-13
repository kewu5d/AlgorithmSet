#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int T, n, A, B, a[105], k;
int dp[105][105];//dp[i][j]：跳i次，在j位置处最大吃虫数 
void solve()
{
  int ans=-1;
  for (int i=1; i<=k; i++)
  {
    for (int j=1; j<=n; j++)
    {
      for (int x=A; x<=B; x++)
      {
        if (i-1 >=0 && j-x >= 0){
          dp[i][j] = max(dp[i][j], dp[i-1][j-x] + a[j]);//这里是+a[j]该位置的虫子数，而不是a[i] 
        }//防越界
      }			
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << endl;
  return;
}
int main()
{
  cin >> T;
  while (T--)
  {
    cin >> n >> A >> B >> k;
    for (int i=1; i<=n; i++) cin >> a[i];//虫子数,0位置没虫子---------------------****
    //初始化
    //dp[0][0] = 0; 
    memset(dp, -0x3f, sizeof(dp));
    dp[0][0] = 0;//注意顺序 
    solve();
  }
  return 0;
}
