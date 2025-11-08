//面向al编程
// 2024 和 1024 的最小公倍数是多少？ 

#include <iostream>
using namespace std;

int main()
{
	//求两数的最小公倍数 
	int j = 1;
	for (int i = 1; ; i++)
	{
		//交叉倍数，避免死循环 
		while (2024 * i >= 1024 * j)
		{
			if (2024 * i == 1024 * j)
			{
				cout << 2024 * i << endl;	//259072
				return 0;
			}
			j++;
		}
			
	}
}
