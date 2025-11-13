#include <iostream>
#include <string>
#include <limits.h>
#define ll long long
using namespace std;
int minimumRecolors(string blocks, int k)
{
	int l=0, r = l+k-1;
	int ans = k+1, temp= 0;//[l, r]内W的个数 
	for (int i=l; i<=r; i++)
	{
		if (blocks[i] == 'W')temp++;
	}
	ans = min(temp, ans);
	while (r < blocks.length()-1)
	{
		if (blocks[l] == 'W')temp--;l++;
		r++;
		if (blocks[r] == 'W')temp++;
		ans = min(ans, temp);
	}
	return ans; 
}
int main()
{
	string b;cin >> b;
	int k;cin >> k;
	int ans = minimumRecolors(b, k);
	cout << ans << endl;
	return 0;
	
}
