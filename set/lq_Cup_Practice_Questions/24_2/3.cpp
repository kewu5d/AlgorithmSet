//请问，有多少个不超过 2024 的正整数，与2024(按位)异或之后结果小于 2024 。
//错误思路：for循环将某数与2024转化为二进制，作为字符串存入数组，按位异或后还原，判断成立就cnt++

//正确思路：异或运算符 ^ :有1则1， 
#include <iostream>
//#include <string>
using namespace std;
//转二进制函数（没用，用不上） 
string c_Binary(int n)
{
	//十进制数n，转二进制
	string b;
	while (n > 0)
	{
		
		b = char(n % 2) + b;
		n = n / 2;
	}
	return b;
}
/*
char* c_Binary(int n)
{
	//十进制数n，转二进制
	char b[100] = {7};	//字符数组 
	//string b = "0";
	for (int i = 0; ; i++)
	{
		b[i] = n % 2;
		int n = (n - (n % 2)) / 2;
		if (n == 0) 
			break;
	}
	return b;	//函数中创建的都是随机临时变量（地址） ，无法返回该地址，如需返回需要动态申请这片空间 
}*/

int main() 
{  
    int count = 0;  
    for (int x = 1; x <= 2024; x++) 
	{  
        if ((x ^ 2024) < 2024) {  
            count++;  
        }  
    }  
    cout << "满足条件的正整数数量为: " << count << endl;  //2001
    //cout << (3 ^ 2024); 
    return 0;  
}
