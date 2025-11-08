/*小蓝有一个数组 a[1], a[2], ..., a[n] ，请求出数组中值最小的偶数，输出这个值。
【输入格式】
输入的第一行包含一个整数 n 。
第二行包含 n 个整数，相邻数之间使用一个空格分隔，依次表示 a[1], a[2], ..., a[n] 。
【输出格式】
输出一行，包含一个整数，表示答案。数据保证数组中至少有一个偶数。
【样例输入】
5
4321 2143 1324 1243 4312
【样例输出】
1324

*/

#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;	//紧跟其后 
	//int t = n + 1;
	int a[n + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];//数据保证数组中至少有一个偶数。
	}
	int minn = 1000000;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] <= minn)
		{
			if (a[i] % 2 == 0)	//是偶数 
			{
			minn = a[i];
			}
		}
		
	}
	cout << minn << endl;
	return 0;

}
