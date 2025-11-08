#include <iostream>
#include <cstdio>
#include <string>
#include <math.h> 
using namespace std;
int a[100], b[100], c[100];//c保存a+b运算结果----开大点没事哒 
int main()
{
	string x, y;//字符串接受大数 
	cin >> x >> y;
	//数组 保存并模拟运算 ---倒着存 
	int j = 0;
	for (int i = x.length()-1; i>=0;i--)
	{
		a[j] = x[i] - '0';//字符Ascn||码相减 得到整型数字 
		j++;
	}
	//for (int i = x.length()-1; i>=0;i--)cout << a[i];
	// 012345
	//低---高（低位对齐） 
	j = 0;
	for (int i = y.length()-1; i>=0;i--)
	{
		b[j] = y[i] - '0'; 
		j++;//自然会跳出循环 
	}
	//模拟加法运算--对进位的处理
	int len = max(x.length(), y.length());//0~len-1(下标)
	for (int i = 0; i < len; i++)
	{
		c[i] += a[i] + b[i];
		if (c[i] >= 10)
		{
			c[i+1]++;
			c[i] -= 10;
		}
	}
	//倒着输出
	if (c[len] != 0)
	{//max+1(最高位发生了进位)
		for (int i = len; i>=0;i--) 
		{
			cout << c[i] ;
		}
	}
	else
	{
		for (int i = len-1; i>=0;i--) 
		{
			cout << c[i] ;
		}
	}
	cout << endl;
	return 0;
	
}
/*
11111111111111111111111111
9999999999999999999999999999999999
*/
