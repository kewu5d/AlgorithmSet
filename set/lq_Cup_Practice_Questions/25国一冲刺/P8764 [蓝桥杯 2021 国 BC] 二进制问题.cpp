#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[70][70][2];//1e18 < 70二进制位 
ll n, k; 
ll bit[70];//都是从1开始存 
int main()
{
	cin >> n >> k;
	int len = 1;
	while (n>0)
	{
		bit[len++] = n%2;
		n /= 2;
	}
	len--;//真实二进制位数 
	//初始化
	dp[1][1][1] = 1;
	dp[1][0][0] = 1;
	//预处理
	for (int i=2; i<=68; i++) 
	{
		for (int j=0; j<=68; j++)
		{
			if (i>=j)
			{
				dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1];
				dp[i][j][1] = dp[i-1][j-1][0] + dp[i-1][j-1][1];
			}
		}
	}
	//枚举比对n的二进制数组bit
	ll ans = 0;
	//第一部分答案，所有长度小于len的数 
	for (int i=k; i<=len-1; i++)
	{
		ans += dp[i][k][1];//首位一定为1，不然会退化 
	}
	//第二部分答案，长度等于len的数 
	int x = 1;//从后往前第i位的前面位数中用了的1的个数 
	for (int i = len-1; i>=1; i--)
	{//从len-1位倒着枚举，保证枚举出来的数小于等于n 
		if (x > k)
		break;//等于k不可以跳过哈，第i位还可以枚举0啊 
		if (bit[i] == 0) continue;
		//第i位枚举0，后面位数随便枚举一定能小于n 
		ans += dp[i][k-x][0];
		//枚举1，继续看下一位
		x++; 
		
	}
	
	cout << ans << endl;
	return 0;
	
}
