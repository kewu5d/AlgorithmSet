#include <iostream>
#include <string> 
using namespace std;

int n, ans, vis[25];//只能用两次 
string s[25];
char a;
string islink(string x, string y)
{
	int len1 = x.size(), len2 = y.size();
	for (int i=1; i<len1 && i<len2; i++)
	{
		if (x.substr(len1-i, i) == y.substr(0, i))
		{
			return x.substr(0, len1-i) + y;
		}
	}
	return "0";//接龙失败 
}
void dfs(string sss)
{
	if (sss.size() > ans)ans = sss.size();//最长接龙字符长度
	
	for (int i=0; i<n; i++) 
	{
		if (vis[i] != 2 )
		{
			//连接---需要知道匹配接龙的位置，所以可以在判断是否可接龙上的函数里实现接龙 
			string linked = islink(sss, s[i]);
			if (linked != "0")
			{
				vis[i]++;
				dfs(linked);
				vis[i]--;
			}
		}
	}
}
int main()
{
	cin >> n;
	for (int i=0; i<n; i++)cin >> s[i];
	cin >> a;//开头
	for (int i=0; i<n; i++)
	{
		if (s[i][0] == a)
		{
			vis[i]++;
			dfs(s[i]);
			vis[i]--;
		}
	}
	
	cout << ans << endl;
	return 0;
}
