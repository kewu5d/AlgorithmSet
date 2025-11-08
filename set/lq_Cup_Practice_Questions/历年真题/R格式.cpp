//我的错误思想：想着将2^n计算出来存进数组，在进行高精度乘法。难以处理点：如何存进数组？在用快速幂吗？ 
//以及只保存小数点后两三位的样子--增加处理步骤 
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
vector<int> b;//b保存答案 ---不知道开多大就用变长数组 
int main()
{
	int n;
	string d;
	cin >> n >> d; //d乘以2^n,四舍五入取整------》b中 
 	int fpoint, ipoint=0;//记录下小数点的位置 
	for (int i = d.length()-1; i>=0; i--)
	{
		if (d[i] != '.')
		{
			b.push_back(d[i] - '0');//注意这里需要实现**倒着存**了 
		}
		else 
		{
			fpoint = d.length()-i-1;//小数部分的长度 ***四舍五入判断fpoint-1*** 
			//ipoint = i;//整数部分的长度 
		}
	}
	//模拟乘法
	int len = d.length() - 1;// = b.size();//b数组长度
	while (n--) 
	{//2^n转换为乘以n次2
		len++;b.push_back(0);//与2（1位数）相乘 ，长度最多+1 
		for (int i= 0;i<len; i++) 
		{
			b[i] = 2*b[i];//不是+= 
		}
		//处理进位
		for (int i = 0;i< len; i++) 
		{
			if (b[i] >= 10)
			{
				b[i+1] += b[i]/10;
				b[i] %= 10;
			}
		}
	}
	//去除前导0 
	while (b[len-1] == 0 && len >1) len--;
	//四舍五入
	if (b[fpoint-1] >= 5) 
	{
		while (++b[fpoint] == 10)
		{
			fpoint++;
		}
	}
	for (int i = len-1; i>fpoint-1; i--)cout << b[i];
	cout << endl;
	return 0;
	
}
 
