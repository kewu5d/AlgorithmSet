#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 1e5+5;
int m, n;//m学校、m学生
int a[N], b[N];//b为估分 
long long  ans;//----------***估分与分数线差距过大，会爆int，所以用ll来存 
int main()
{
	//本题使用二分查找找到估分左右区间 
	//但不知道与哪个差距小，所以都要做差比较取最小
	 cin >> m >> n;
	 for (int i=1; i<=m; i++)cin >> a[i];
	 for (int i=1; i<=n; i++)cin >> b[i];
	 sort(a+1, a+1+m);
	 while (n)
	 {
	 	int l=1, r=m, mid;
	 	while (l <= r)
	 	{
	 		mid = l + (r-l)/2;
	 		if (a[mid] > b[n])r = mid-1;
	 		else l = mid +1;
		}
		if (b[n]-a[r] >= a[l]-b[n] && r != 0 && l != m+1){
			ans += a[l]-b[n];
		}
		else if (r == 0)ans+= a[l]-b[n];//最左边没学校
		else if (l == m+1) ans += b[n]-a[r];//右没 
		else ans += b[n]-a[r];
		n--;
	 }
	 cout << ans << endl;
	 return 0;
}
