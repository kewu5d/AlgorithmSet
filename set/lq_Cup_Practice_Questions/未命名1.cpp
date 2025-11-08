#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5+5;
long long n, w[2*N];
long long sum;
int main()
{
  cin >> n;
  for (int i=1; i<=2*n; i++)cin >> w[i];
  sort(w+1, w+1+2*n);
  //for (int i=1;i <=2*n;i ++)cout << w[i] << ' ';
  int cnt = n, i = 1;
  while (cnt--)
  {
    sum += w[i]*w[2*n-i+1];
    //cout << w[i] <<' ';
    i++;
  }
  cout << sum << endl;
  return 0;
}
