#include <iostream> 
#include <algorithm> 
#define ll long long
using namespace std;
ll x, y;//xÎª³¤£¬»­Í¼ 
ll ans;
void till()
{
	if(x == 0 || y == 0)return;
	ll temp = min(x, y);
	ans += 4*temp;
	if (temp == y)x-=temp;
	else y-=temp;
	till();
}
int main()
{
	cin >> x >> y;
	till();//µİ¹éÖÖÌï
	cout << ans << endl;
	return 0;
}
