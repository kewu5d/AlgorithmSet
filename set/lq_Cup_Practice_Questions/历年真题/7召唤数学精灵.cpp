//暴力模拟---跑不出来的 
#include <iostream> 
#include <cstdio>
#define ll long long
ll A(int i)
{
	if (i != 0)
	{
		return i + A(i-1);
	}
	else return 0;
}
ll B(int i)
{
	if (i != 0)
	{
		return i * B(i-1);
	}
	else return 1;
}

int main()
{
	// printf("%lld", B(4));
	//int ans = 0;
//	for (int i = 1; i<= 1000; i++)
//	{
//		if((A(i) - B(i))% 100 ==0)
//		{
//			//printf("%lld ", i);
//			//ans++;
//		}
//	}
	ll ans = 2024041331404202/200 * 4;
	printf("%lld", ans+2);
	
	return 0;
}
