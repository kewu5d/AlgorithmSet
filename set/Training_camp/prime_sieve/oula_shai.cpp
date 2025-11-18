#include <iostream>
#include <vector>	//cpp借助stl
using namespace std;
vector<int> prime;
int n;
int isprime[10005];//1：是质数0：不是质数（也就是合数） 
int main()
{
	cin >> n;
	//初始化，一开始全部认为是质数，用质数筛合数（依据定理） 
	for (int i=2; i<=n; i++)isprime[i] = 1;
	//线性筛
	for (int i=2; i<=n; i++) 
	{
		if (isprime[i])prime.push_back(i);
		//枚举所有质数数组里的质数
		for (auto p: prime)
		{//对合数i*p进行筛除 
			int temp = i*p;
			if (temp > n)break;//合数超过讨论范围，直接break
			else isprime[temp] = 0;//筛掉此合数
			if (i % p == 0)break;//合数i*p已经被最小的质因数p给筛过了，跳过>p的其他质因数 
		}
	}
	for (auto p: prime)cout << p << " ";
	return 0;
} 
