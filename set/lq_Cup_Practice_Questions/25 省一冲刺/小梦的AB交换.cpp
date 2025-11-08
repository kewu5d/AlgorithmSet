//我们最终需要得到的字串只有两种合法形式
//1.ABABABABABABAB   2.BABABABABABABABA
//通过模拟得知：一次swap可以解决两个位置 
//只需要让所求字串与两个合法字串进行匹配，不匹配的位置数/2就是交换次数。取min得到 最少进行的操作次数
#include <bits/stdc++.h> 
using namespace std;
int t, n;
int ans = INT_MAX;
int calc(string a, string b) 
{
	int sum=0;
	for (int i=0; i<=n*2;i++)
	{
		if (a[i]!=b[i])sum++;
	}
	return sum/2;//sum个位置不匹配，一次交换解决两个位置 
}
int main()
{
	cin>> t;
	string a, b;//两种目标合法AB串：ABABAB、BABABA
	while (t--)
	{
		cin>>n;
		string s;cin >> s;
		//构建匹配串
		for (int i=0;i<2*n;i++) 
		{
			if (i%2==1)
			{
				a +="A";b+="B";
			}
			else
			{
				a +="B";b+="A";
			}
		}
		//让s分别与两种答案匹配计算交换swap次数，取min 
		cout << min(calc(a, s), calc(b, s))<< endl;
	
	}
	return 0; 
}
 
