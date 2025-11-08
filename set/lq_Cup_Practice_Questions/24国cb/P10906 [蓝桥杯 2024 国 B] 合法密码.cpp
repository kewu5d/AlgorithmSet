#include <iostream>
#include <string>
using namespace std;
int ans;
string s = "kfdhtshmrw4nxg#f44ehlbn33ccto#mwfn2waebry#3qd1ubwyhcyuavuajb#vyecsycuzsmwp31ipzah#catatja3kaqbcss2th";
bool check(string x)
{
	int f1=0, f2 = 0;
	for (int i =0; i<x.size(); i++)
	{
		if (x[i] <+ '9' && x[i] >= '0')f1 =1;
		if (x[i] == '#')f2 = 1;
	}
	if (f1+f2 == 2)return true;
	else return false;
	//return f1==f2==1;
	
}
int main()
{
	for (int i=0; i<=s.size()-8; i++)
	{//枚举起始点
		for (int j=8; j<=16; j++)
		{
			string t = s.substr(i, j);
			if (check(t))ans++;
		}
		
	}
	cout << ans << endl;
	
	return 0;
}
