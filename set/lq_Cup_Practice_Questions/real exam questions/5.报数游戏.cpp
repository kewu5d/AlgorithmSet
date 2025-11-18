//最小公倍数120，240.。。 

#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
int main()
{
	ll cnt = 0;//奇数i， 偶数j 
//	ll i = 20; 
//		cnt++;
	ll j = 0;
	//cnt++;
	while(1) 
	{
//		i += 20;
//		//if (i == j)i+=20;//跳过，接着报 
//		cnt++;
//		if (cnt == 202420242024)break;
		j+= 24;
		//if (i == j)j+=24;
		cnt++;
		if (cnt == 101210121012)break;//偶数 
		//else cout << cnt << " " ;
	}
	//cout << j << endl;
	printf("%lld", j);
	return 0;
}
