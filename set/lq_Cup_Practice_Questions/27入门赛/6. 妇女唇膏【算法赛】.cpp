#include <iostream>
using namespace std;
int a[100005];
int main()
{
	int n;cin >> n;
	int ans=0;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i];
		ans |= a[i];//所有a值或在一起，找到lowbit为0的位置i 
	}
	for (int i=0; i<n; i++)
	{
		if ((ans>>i & 1) == 0)
		{
			cout << (1<<i) << '\n';
			break;
		}
	}
	return 0;
}
