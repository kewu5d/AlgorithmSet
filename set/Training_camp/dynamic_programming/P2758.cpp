/*dp[i][j]:以i结尾的子串变成以j所需要的最少的修改次数
 
dp[i-1] [j-1]:新增的i、j字符相同就直接继承
				不相同，改一次 
dp[i-1][j] 
dp[i][j-1]

改一个数，在之后插入一个--》操作+2
不等价于

 取min
 */
 #include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int dp[2005][2005];
string A, B;
int main()
{
	cin >> A >> B;
	A = 'B' + A;B = 'C' + B;//1下标开始，防越界
	//初始化 
	for (int i=1; i<=A.size()-1; i++)dp[i][0] = i;//将子串1全部删掉，变成空串2 
	for (int j=1; j<=B.size()-1; j++)dp[0][j] = j;//对空串1一直插入字符，变成子串2 
	
	for (int i=1; i<=A.size()-1; i++)
	{
		for (int j=1; j<=B.size()-1; j++)
		{
			if (A[i] == B[j])dp[i][j] = dp[i-1][j-1];
			else
			{
				dp[i][j] = min(dp[i-1][j-1]+1, min(dp[i-1][j]+1, dp[i][j-1]+1));
			}
		}
	}
	cout << dp[A.size()-1][B.size()-1] << endl;
	return 0;
}
