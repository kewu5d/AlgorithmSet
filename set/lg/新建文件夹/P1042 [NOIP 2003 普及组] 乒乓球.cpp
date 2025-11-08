//列表显示：正在进行第三局，比分为：
//另：7局4胜 ----------并没有这个隐形要求 
//但是！！有一个隐形要求：就是赛点追平会进行加赛 

#include <iostream> 
#include <string>
using namespace std;

string s, t;
int main()
{
	cin >> s;
	while(cin >> t)
	{
		s += t;
	}
	//11
	int i = 0, round = 1; 
	int w, l;
	w = l = 0;
	while (s[i] != 'E' )//|| round > 7)
	{
		if (s[i] == 'W')w++;
		else if (s[i] == 'L')l++;
		
		if ((w == 11 && l < 10) || (l == 11 && w <10))
		{
			cout << w << ':' << l << '\n';
			round++;
			w = l = 0;
		}
		else if (w >= 10 && l >= 10)
		{//发生了加赛 
			if (w - l >= 2 || l - w >= 2)
			{
				cout << w << ':' << l << '\n';
				round++;
				w = l = 0;
			}
		}
		i++;
	}
	if (s[i] == 'E')
	{
		cout << w << ':' << l << '\n';
	}
	round = 1;
	w = l = i = 0;
	cout << '\n' ;
	//21分制 ---------可以包装成函数， 
	while (s[i] != 'E' )
	{
		if (s[i] == 'W')w++;
		else if (s[i] == 'L')l++;
		
		if ((w == 21 && l < 20) || (l == 21 && w < 20))
		{
			cout << w << ':' << l << '\n';
			round++;
			w = l = 0;
		}
		else if (w >= 20 && l >= 20)
		{//发生了加赛 
			if (w - l >= 2 || l - w >= 2)
			{
				cout << w << ':' << l << '\n';
				round++;
				w = l = 0;
			}
		}
		i++;
	}
	if (s[i] == 'E')
	{
		cout << w << ':' << l << '\n';
	}
	return 0;
}
