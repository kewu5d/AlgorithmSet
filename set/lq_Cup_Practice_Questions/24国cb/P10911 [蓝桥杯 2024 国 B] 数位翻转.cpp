 /*

最多选m，也可以不选。范围0~m次反转 ，翻转区间不相交！！

最值问题：dp？二分？贪心？
- 20%的数据，暴力应该可以拿到
 		遍历一遍所有数反转后是变大了还是变小了
		 找出变大的m个连续区间



题解1：
- 十进制转二进制，存入二进制数组d 

- reverse()函数翻转二进制数组d
- 将二进制转回十进制


最多有m*2 + 1个区间：
	指最多选m个区间导致最终分割成m*2+1个区间
	
题解2：


- 算出翻转后的贡献序列 
对贡献序列进行dp ，最后答案为：原总和+贡献
	dp：
	- dp[i][j][0]:表示到第i个数，前面共取j个连续段
					而第i个数不取。得到的最大和
	- dp[i][j][1]:表示到第i个数，前面共取j个连续段
					而第i个数取。得到的最大和
					
转移方程：
	-  第i个数不取，可以有上一个数的任意状态（取/不取）转移而来 
	dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1])
	- 取的话，可以是与上一段合并连续，也可以单独成一段
	dp[i][j][1] = max(dp[i-1][j-1][0], dp[i-1][j][1]) + b[i]
*/


#include <iostream> 
#include <algorithm>
#define int long long //不开long long见祖宗 
using namespace std;
int n, m, a[1005], b[1005], sum;//b为贡献数组 
int dp[1005][1005][2];
int rev(int x)
{
	int t = x;
	int bit[33], i = 1;
	while (t > 0) 
	{
		bit[i++] = t%2;
		t /= 2;
	}
	//reverse(bit+1, bit+i);//不需要，除基取余倒着读，自带翻转
	int t2 = 0, k = 1;
	for (i=i-1; i>=1; i--)
	{
		t2 += bit[i] * k;
		k *= 2;
	}
	return t2-x;
}
signed main()
{
	cin >> n >> m;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i];
		sum += a[i];
		b[i] = rev(a[i]);//翻转后在一次性得到贡献 
		//cout << b[i] << ' ';
	}
	//初始化？ 
	
	for (int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]);
			dp[i][j][1] = max(dp[i-1][j-1][0], dp[i-1][j][1]) + b[i];
			
			
		}
	}
	int ans = 0;
	for (int j=1; j<=m; j++)ans = max(ans, max(dp[n][j][0], dp[n][j][1]));
	cout << ans + sum << endl;
	return 0;
}



