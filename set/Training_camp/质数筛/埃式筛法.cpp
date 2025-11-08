#include <iostream>
#include <vector>	//cpp借助stl
using namespace std;
vector<int> prime;
int n, x;
int isprime[10005];//0：是质数(省初始化)， 1：不是质数（也就是合数） 
int main()
{
	cin >> n;
	for (int i=2; i<=n; i++)
	{
		if (isprime[i] == 0)
		{//是质数 
			prime.push_back(i);//建立质数数组 
			for (int j = i*2; j<=n; j+=i)
			{
				isprime[j] = 1;//删取质数的所有倍数（合数） 
			}
			//？？？？？？？？？？？？？？？这个for循环放在内外是不是没有关系 
			//是的，就是让复杂度更高了（苦笑不得） 
		}	
	}
	//cin >> x;
	for (auto p:prime)cout << p << ' ';
	if (isprime[x])cout << "N";
	//else cout << "Y";
	return 0;
} 
