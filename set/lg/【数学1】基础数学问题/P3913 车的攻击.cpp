#include <iostream>
#include <cstdio>
#include <unordered_set> 
#define int long long
using namespace std;
//int desk[][]会MLE
//set<int> setr, setc;
//由于此题只需要去重
unordered_set<int> setr, setc;

int n,k, r, c;
signed main()
{
	//cin >> n >> k;
	scanf("%lld %lld", &n, &k);
	for (int i=1; i<=k ;i++)
	{
		//cin >> r >> c;
		scanf("%lld %lld", &r, &c);
		setr.insert(r);//使用insert 
		setc.insert(c);
	}
	//cout << setr.size() * n + setc.size()*(n - setr.size()) << endl;
	printf("%lld", setr.size() * n + setc.size()*(n - setr.size()));
	return 0;
}
