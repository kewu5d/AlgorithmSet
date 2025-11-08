/*
请问， 2024的最大的质因数是多少？
*/ 
#include <iostream>
using namespace std;

int isprime(int n)
{
	if (n <= 1)
	{
		return 0;	//不是质数 
	}
	for (int i = 2; i * i < n; i++)
	{
		if (n % i == 0)
		{
			return 0;	//有其他除数 
		}
	}
	return 1;	//是质数 
}
int main()
{
	int n = 2024;
	int maxx = 0;
	for (int i = 1; i * i <= n; i++)
	{
		if (n % i == 0)	//是约数 
		{
			if (isprime(i))
			{
				//printf("%d", i);	C的输出写法
				//cout << i << endl; 
				if (i > maxx)
				{
					maxx = i;	//替换，而不是求和 
				}
				
			}
			//*******判断与i对应的另外的约数*********
			if (i != n / i)
			{//i是约数， 此时n/i也是约数 
				if (isprime(n / i))
				{		
					if (n / i > maxx)
					{
						maxx = i;	//替换，而不是求和 
					}
				
				}
			}
		}
	}
	cout << maxx << endl;	//24
	return 0;
}
