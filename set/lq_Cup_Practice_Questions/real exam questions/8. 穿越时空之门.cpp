#include <iostream>
#include <cstdio>
using namespace std;
 //除R取余倒着读
int two(int i)
{//转二后各位数 之和
	int ans = 0;
	while (i!=0) 
	{
		
		ans += i%2;
		i /= 2;
	}
	return ans;
}
int four(int i)
{//转二后各位数 之和
	int ans = 0;
	while (i!=0) 
	{
		
		ans += i%4;
		i /= 4;
	}
	return ans;
}
int main()
{
	int ans=0;
	for (int i=1;i <=2024 ;i++)
	{
		if (two(i) == four(i))
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
