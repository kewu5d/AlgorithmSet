/*
模拟所有可能，相邻两行星
- +、+
- -、-
- -、+：左行星向左走，右行星向右走，以上三种均不会发生碰撞
- +、-：==Boom！！！==
*/
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> asteroidCollision(vector<int>& asteroids)
{//左右匹配类问题 
	vector<int> ve;//包括传进来的参数，两个杯子(栈)
	vector<int> ss;//倒着存asteroids，保障模拟行星的顺序性 
	int x; 
	int l = asteroids.size();
	for (int i= 0; i<l; i++)
	{
		x = asteroids.back();
		asteroids.pop_back();
		ss.push_back(x);
	}//可以省略，直接将 asteroids当数组使用，利用下标访问 
	while (l)
	{
		if (ve.empty() == 1 || ss.back() > 0) 
		{//栈空 ,行星为正 
		//+ +
		//- +
			x = ss.back();
			ve.push_back(x);
			ss.pop_back();
			l--;
		}
		//碰撞循环 和另外两种情况 
		while (ve.empty() == 0 && l>0 && ss.back() < 0 ) 
		{	//l>0表示还有行星 ， //栈非空
			//判断
			if (ve.back() < 0)
			{//- -,继续入栈 
				x = ss.back();
				ve.push_back(x);
				ss.pop_back();
				l--;
			}
			else
			{//+ -，发生碰撞 
				x = ss.back();
				if (-x > ve.back())
				{
					ve.pop_back();
					continue;
				}
				else if (-x == ve.back())
				{
					ve.pop_back();
					ss.pop_back();
					l--;
				}
				else
				{
					ss.pop_back();
					l--;
				}
			}
		}	
	}
	return ve; 
}
int main()
{
	int n, x;
	vector<int> s;//不定数组模拟栈,s[0]作为栈底 
	cin >> n;
	for (int i = 0; i<n;i++) 
	{
		cin >> x;
		s.push_back(x);
	}
	vector<int> ans = asteroidCollision(s);
	for (int i = 0; i< ans.size() ;i++) 
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
