#include <iostream>
#include <map>
#define ll long long
using namespace std;
ll n, q, a[100005], l, r, sum;
int main()
{
  //区间变换一增一减,单位置增减下标值
  cin >> n >> q;
  for (int i=1; i<=n; i++){
    cin >> a[i];
    sum +=a[i];
  }
  while (q--)
  {
    cin >> l >> r;
    if (l == r)sum += l;
    else if ((r-l+1)%2 == 0)sum -= (r-l+1)/2;
    else sum += (r-l+1+1)/2;
  }
  cout << sum << endl;
  return 0;
}
