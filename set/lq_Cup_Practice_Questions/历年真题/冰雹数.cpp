#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
int main()
{
  // 请在此输入您的代码
  int n;cin >> n;
  ll ans = 0;//定义理论小值，求最大值
  while (n)
  {
    ll i = n;
    while (i != 1)
    {
      if (i % 2 ==0)
      {
        i >>= 1;//除2 
      }
      else
	  {
	  	i = i*3 +1;
	  	ans = max(i, ans);//冲击过程发生于此 
	   } 
    }
    n--;
  }
  cout << ans << endl;
  return 0;
}
