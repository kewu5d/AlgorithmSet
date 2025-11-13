#include <iostream>
#define ll long long
const int N = 1e6+10;
using namespace std;
int n, h[N];
ll m;
int main()
{
	cin >> n >>m;
	int maxlen = 0;
	for (int i=1;i<=n; i++){
		cin >> h[i];
		if (h[i]>maxlen)maxlen = h[i];
	}
	int l = 0, r=maxlen, mid;
	while (l <= r)
	{
		mid = (l+r)/2;
		ll sum = 0;
		for (int i=1;i <=n; i++)
		{
			h[i]>mid?sum+=h[i]-mid: 0;
		}
		if (sum > m)l = mid+1;
		else if (sum < m)r = mid-1;
		else break;
	}
	mid = (l+r)/2;
	cout << mid << endl;
	return 0;
}
