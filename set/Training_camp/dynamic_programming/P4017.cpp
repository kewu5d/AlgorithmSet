
生产者：只能被吃，作为食物链开始 
顶级消费者： 

怎么找到生产者？顶级消费者（不用找）？
- 
food[i][j] :1表示：i作为j的食物，0表示没有关系 
green[]：生产者：没有出现在右边


最优解---动态规划：dp[i]：以第i生物结尾的最长食物链 
从下往上？从上往下？ 

题目理解错误：
我以为是求最长食物链的长度， 
而实际上是求生产者到顶级消费者的食物链的条数 

#include <iostream>
#define ll long long
const ll mod = 80112002;
using namespace std;
int main()
{
	int n, m;cin >> n >> m;
	for (int i=1; i<=m; i++) 
	{
		int a, b;cin >>a >> b;
		food[a][b] = 1;
	}
	
}
