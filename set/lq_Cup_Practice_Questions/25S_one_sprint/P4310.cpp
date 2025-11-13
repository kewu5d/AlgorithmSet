#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5+5;

void solve1()
{
	int n, a[N] = {0};
	int dp[N] = {0};//以a[i]结尾的子序列最长长度 
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i];dp[i] = 1;
	}
	//if (4&4 == 0)cout << "herw" ;
	int ans = 0;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<i; j++)
		{
			if (a[j] & a[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}
	//for (int i=1;i <=n; i++) cout << dp[i] << '\n';
	cout << ans << endl;
}

int dp[33][N] = {0}; //ai的范围不超过整数范围，32位足够

void solve2()
{
	//solve1的O(n^2)需要优化，这里借助位运算 
	int n, a[N] = {0};
	//int dp[33][N] = {0};//不可以设成局部变量，爆栈了都，还想运行呢
	cin >> n;
	for (int i=1; i<=n; i++)cin >> a[i];
	int ans = 0;
	for (int i=1; i<=n; i++)
	{//枚举列 
		
		//-------找i-1列，即前一列符合条件的最长长度k 
		int k = 0;
		for (int j=0; j<32; j++)//-----------------------------debug 
		{
			if (a[i] & (1<<j))k = max(k, dp[j][i-1]);
				//dp[j][i] = max(dp[j][i], dp[j][i-1]+1);//j发生改变接不上，也每找到最长长度 
		}
		//----------------------------
		for (int j=0; j<32; j++)
		{//枚举行
			if (a[i] & (1<<j))dp[j][i] = k+1;//接在符合条件的最长长度上 
			else dp[j][i] = dp[j][i-1];//直接继承
			
			ans = max(ans, dp[j][i]);
		}
	}
	cout << ans << endl;
}


void solve3()
{
	int n, a[N] = {0}, dpp[33] = {0};
	cin >> n;
	for (int i=1; i<=n; i++)cin >> a[i];
	int ans = 0;
	for (int i=1; i<=n; i++)
	{//枚举列 -------------------------优化成dpp[33]因为每次计算i只用到了 i-1，所以不需要开列，只保留行就行了 
		int k = 0;
		for (int j=0; j<32; j++)
			if (a[i] & (1<<j))k = max(k, dpp[j]); 
			
		//----------------------------
		for (int j=0; j<32; j++)
		{//枚举行
			if (a[i] & (1<<j))dpp[j] = k+1; 
			//else dp[j][i] = dp[j][i-1];//否则该行的值不变 
			
			ans = max(ans, dpp[j]);
		}
	}
	cout << ans << endl;
}
int main()
{
	//solve1();
	//solve2();	//时间优化，借助位运算 
				//dp[j][i]：表示前i个元素的j行的*最长与序列*的最长长度 
				//与*最长上升子序列*还是有所不同，并不是以a[i]结尾 
	
	solve3(); 	//可进行空间优化，dp[j]：计算i只用到了i-1，故可以只保留行号j 
				
	return 0;
}
