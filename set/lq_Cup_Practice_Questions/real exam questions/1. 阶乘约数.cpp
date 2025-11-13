#include <iostream>
#define ll long long
using namespace std;
int main()
{
  int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
  ll ans = 1;
  for (int i=0; i<sizeof(prime)/sizeof(prime[0]); i++)
  {
  	int cnt = 0, n=100;
  	while (n != 0)
  	{
  		cnt += (n /= prime[i]);//Legendre¹«Ê½
	}
	ans *= cnt+1;
  }
  cout << ans << endl;
  return 0;
}
