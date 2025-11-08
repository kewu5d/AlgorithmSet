//当然也有可能某些寄包柜中一个格子都没有

#include <iostream>
#include <map> 
#define ll long long 
using namespace std;
const int N = 1e5 + 10;
map<pair<int, int>, int> mp;//访问方式：mp[{i, j}] 
int flag; //1存2查询
int i, j;
ll k;//物品k 
int n, q;
int main()
{
	cin >> n >> q;
	while (q--) 
	{
		cin >> flag;
		if (flag == 1)
		{
			cin >> i >> j >> k;
			mp[{i, j}] = k;//在第i个柜子的第j个格子存物品k 
		}
		else
		{
			cin >> i >> j;
			cout << mp[{i, j}] << endl;
		}
	}
	return 0;
}
