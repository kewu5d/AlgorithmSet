#include <iostream>
#include <cstdio>
#include <string>
#include <math.h> 
using namespace std;
int a[20000], b[20000], c[20000];//c保存a-b运算结果----开大点没事哒 
int main()
{
	string x, y;//字符串接受大数 x，y均大于0 
	cin >> x >> y;
	//数组 保存并模拟运算 ---倒着存 
	int j = 0;//在外面定义
	for (int i = x.length()-1; i>=0;i--)
	{
		a[j] = x[i] - '0';//字符Ascn||码相减 得到整型数字 
		j++;
	}
	j = 0;//置0
	for (int i = y.length()-1; i>=0;i--)
	{
		b[j] = y[i] - '0'; 
		j++;//自然会跳出循环 
	}
	//模拟减法运算--对借位的处理
	int len = max(x.length(), y.length());//0~len-1(下标)
	//if (x>y)cout << -1;
	if (x.length() > y.length() || (x.length() == y.length() && x >= y)) //相同长度时，x > y字符串可以直接比较（字典序） 
	{//说明x-y为正 
		for (int i = 0; i < len; i++)
		{
			c[i] += a[i] - b[i];
			if (c[i] < 0)
			{//需要借位 
				c[i+1]--;
				c[i] += 10;
			}
		}
	}
	else 
	{
		swap(a, b);// a-b = -(b-a)此时互换后a>b,继续使用相同代码----注意要打印个负号 
		cout << '-';
		for (int i = 0; i < len; i++)
		{
			c[i] += a[i] - b[i];
			if (c[i] < 0)
			{//需要借位 
				c[i+1]--;
				c[i] += 10;
			}
		}
	}
	//倒着输出-----去除前置0 
	while(len > 0 && c[len-1] == 0 )
	{//保存长度>0,不要越界 
		len--;//111-110=001=1,111-111=000 = 0
	}
	for (int i = len; i>0;i--) cout << c[i-1] ;
	if (len == 0)cout << '0';
	
	
	cout << endl; 
	return 0;
}
/*
88460914424991
4291703115049359
*/
