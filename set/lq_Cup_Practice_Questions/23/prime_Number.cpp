//题目：1-1000000中，各质数的各位数之和等于23的，问：这样的质数有多少个 
#include <iostream> 
using namespace std;
//判断是否为质数 ： 是指大于 1 的自然数，并且只能被 1 和它本身整除
int isprime(int n)
{
	if (n <= 1)
	{
		return 0;//不是质数
	}
	for (int i = 2; i * i < n; i++)
	{
		if (n % i == 0 )
		return 0;//有除1和self外其他除数，所以不是质数 
		
	}
	return 1;
}
int summ(int n)
{
	int sum = 0;
	if (isprime(n) == 1)
	{
		while (n > 0)
		{
			sum = sum + n % 10;
			n /= 10;
		}
		
	}
	return sum;
}

int main() 
{
	 int n = 1000000;
	 int cnt = 0;
	 for (int i = 2; i <= n; i++ )
	 {
	 	summ(n);
	 	if (isprime(i) && summ(i) == 23)
	 	{
	 		cnt++;
		 }
	 }
	 cout << cnt << endl;

	 //cout << isprime(253);
	 return 0;
}

