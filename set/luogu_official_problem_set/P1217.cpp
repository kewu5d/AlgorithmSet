#include <iostream>
using namespace std;
int a, b;
bool ishuiwen(int x)
{
	int t=0, n=x;
	while (n>0)
	{
		t = t * 10 + n%10;
		n/= 10;
	}
	return t == x;
}
bool isprime(int x)
{
	for (int i=2; i*i <=x; i++)
	{
		if (x%i == 0)return false;
	}
	return true;
}
int main()
{
	cin >> a >> b;
	if (a%2==0)a++;//从奇数开始
	for (int i=a; i<=b; i+=2)
	{
	///*
		if (i>11 && i<=99){//11是质数 
			i = 101-2;continue;
		}
		if (i>1000 && i<=9999){
			i = 10001-2; continue;//加上之后就不会在这个区间 
		}
		if (i>100000 && i<=999999){
			i = 1000001-2; continue;
		}
		if (i>10000000 && i<=99999999){
			i = 100000001 - 2; continue;
		}//只能减去偶数位数的回文数，而不是所有偶数位数 
		//*/
		if (ishuiwen(i) && isprime(i))
		{
			cout << i << '\n';
		}
	}
	return 0;
}
