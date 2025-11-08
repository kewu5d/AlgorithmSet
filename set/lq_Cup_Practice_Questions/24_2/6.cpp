//小蓝准备请自己的朋友吃饭。小蓝朋友很多，最终吃饭的人总数达 2024 人（包括他自己）。
//请问如果每桌最多坐 n 人，最少要多少桌才能保证每个人都能吃饭。

#include <iostream>
using namespace std;

int main()
{
	int sum = 2024;
	int n = 0;
	cin >> n;
	if (sum % n == 0)	//正好 
	{
		cout << sum / n  << endl;
	}
	else				//有余数 
	{
		cout << sum / n + 1 << endl;
	}
	
	return 0; 
}
