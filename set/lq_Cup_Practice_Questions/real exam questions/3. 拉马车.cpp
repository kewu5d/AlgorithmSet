/*ab方和桌上的牌，搞2个队列（先进先出） 1个vector数组 (模拟栈)
 放入牌的顺序是与桌上的顺序相反的：桌上pop，ab方push 
从A 方开始，A、B双方轮流出牌。赢牌的一方继续出牌
当游戏无法结束时，输出 -1。啥情况会？ -------假设已知在循环，次数很大时，可以认为没有胜负，整个time变量记录出牌次数 
打个标记，1为A出牌，0为B出牌 
*/

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <string>
using namespace std;
int flag = 1;//A先出牌 
int islike(char t, vector<char>& d)
{//找到了，就返回d中与t相同的字符位置 
	 //从尾巴开始找，
	 if (d.size() == 1) return 0;//一开始桌子上没牌 
	 int cnt = 1;//刚放的牌也要收 
	 vector<char>::iterator it = d.end() - 2;//`end()`：取尾元素地址的下一个地址，作为迭代器末尾标志，不储存任何元素
	 //-2,避开刚放进入的牌 
	 for (; it != d.begin();it--) 
	 {
	 	cnt++;
	 	if (*it == t)
	 	{
	 		return cnt;
		 }
	 }//it == d.begin()
	 if (*it == t)
	 {
	 	cnt++;
	 	return cnt;
	 }
	 else return 0;
}
int main()
{
	queue<char> a, b;
	vector<char> desk;//桌面
	string x, y;
	cin >> x >> y;
	for (int i = 0;x[i] != '\0';i++)//---C语言写法 
	{
		a.push(x[i]);
		//b.push(y[i]);
	}
	for (int i = 0;i < y.length();i++)//c++
	{
	//	a.push(x[i]);
		b.push(y[i]);
	}

	int times = 0; 
	while (!a.empty() && !b.empty() && times <10000) //双方手里都有牌 
	{
		times++;
		if (flag == 1)
		{//A先出牌 
			char t = a.front();
			a.pop();//出队 
			desk.push_back(t);//出牌 
			int booll = islike(t, desk);//桌子上有牌,判断t是否与其中某一张相同
			if (!desk.empty() && booll)
			{
				 //从desk后面往前收
				 while(booll--) 
				 {
				 	char ttt = desk.back();//刚放的已经在手中了
					a.push(ttt) ;
					desk.pop_back();
				}
				//此时应该继续由a出牌
				continue; 
			}
			flag = 0;
		}
		else if (flag == 0)
		{//轮到B 
			char t = b.front();
			b.pop();
			desk.push_back(t);//出牌 
			int booll = islike(t, desk);
			if (!desk.empty() && booll)
			{
				 while(booll--) 
				 {
				 	char ttt = desk.back();//刚放的已经在手中了
					b.push(ttt) ;
					desk.pop_back();
				}
				continue; //*************不要漏了 
			}
			
			flag = 1;
		} 
	}
	if (times >= 10000) 
	{
		cout << -1 <<endl;
		return 0; 
	}
	if (a.empty())
	{//a空，b为赢家 
		while (!b.empty())
		{
			cout << b.front();
			b.pop();
		}
	}
	else
	{
		while (!a.empty())
		{
			cout << a.front();
			a.pop();
		}
	}
	
	//cout << a.front() << "\n" << b.front();
	return 0;
}

/*
96J5A898QA
6278A7Q973
2J9A7QA6Q6889977

A7893KA
456XJQA
-1
*/
