
/*

补全质数，得到给定字符串长度，
筛出这个长度的质数，比较不打*的部分是否相同
不打*部分完全相同的质数存在，输出最小的那个
输出-1：
-  不打*的部分都不完全相同 

注意：首位不打*, 根据位数确定范围
- 先预处理所有数是否为质数 
*/
#include <bits/stdc++.h>
//#include <iostream>
//#include <string>
//#include <cstring> 
//#include <cstdlib>
//#include <algorithm>
using namespace std;
const int N = 1e7;
int isprime[N], flag, minans;//最小符合质数 
string s;
int vis[10];//位数是否计算过 
void aishai()
{
	isprime[0] = isprime[1] = 1;
	isprime[2] = 0;//2是质数
	for(int i=2;i <N; i++) 
	{
		if (isprime[i]==0)
		{
			for (int j=i*2; j<N; j+=i)
			{//质数的倍数 
				isprime[j] = 1;//筛掉 
			}
		}
	}
}

void dfs(int depth, int x)
{
	if (depth > s.size())
	{
		if (isprime[x]==0)
		{
			minans = min(minans, x);
			flag = 1; 
		}
		return;
	}
	
	for(int i=0; i<s.size(); i++)
	{
		if (s[i] != '*' && vis[i] == 0)
		{//只有打*才搜0~9 
			depth++;
			vis[i] = 1;//(s[i]-48)字符转int 
			x += (s[i]-48) * pow(10, s.size()-i-1);
			//加入这里是最后一个位置，需要再这里就判断
			//因为打*位置不在最后一位值，到不了上面的判断
			if (depth > s.size())
			{
				if (isprime[x]==0)
				{
					minans = min(minans, x);
					flag = 1; 
				}
				//vis[i] = 0;//回退到打星前 
				return;
			} 
		}
		else if (i != depth-1)continue; 
		else {//0~9填在打*位置要配对上i=depth-1 
			for (int j=0; j<=9; j++) 
			{
				vis[i] = 1;
				x += j * pow(10, s.size()-i-1);
				dfs(depth+1, x);
				vis[i] = 0;
				x -= j * pow(10, s.size()-i-1);
				memset(vis+i+1, 0, sizeof(vis[0])*(10-i-1));//回退到打星前 
			}
			
		}
	}
	
}
int main()
{
	//预处理--埃式筛法
	aishai();
	// -----
	int t; cin >> t;
	while (t--)
	{
		cin >> s;
		flag = 0;minans = N;
		memset(vis, 0, sizeof(vis));
		dfs(1, 0);
		if (flag == 0)cout << -1 << endl;
		else cout << minans << endl;
	}
	return 0;
}
