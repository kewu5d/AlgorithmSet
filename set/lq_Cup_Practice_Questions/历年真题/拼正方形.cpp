#include <iostream>
#include <math.h>
#define ll long long
using namespace std;
int main()
{
  ll S = 7385137888721*4 + 10470245;
  ll ans = 1000000;
  while (ans*ans < S)
  {//±©Á¦Ñ­»· 
      ans++;
  }
	cout << ans-1 << endl;
	return 0 ;
}
