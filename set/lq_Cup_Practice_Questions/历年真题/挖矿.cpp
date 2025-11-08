/*思路：3种走法：
一直往右，
一直往左，
采到矿后换一次方向 （只换一次，左右摆就是浪费步数） 
	换方向是否能回到0点然后向反方向走需要判断m-2i > 0 */
#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e6 +5;
//int a[100005];//矿洞的位置，下标是矿洞的编号（第几个）
int l[N], r[N];//分为左右半边 
int suml[N], sumr[N];
int main()
{
	int n, m;cin >> n >> m;
	//for (int i=1; i<= n; i++) 	cin >> a[i];//其值为矿洞所在数轴上的下标 
	int pos;
	for (int i = 1; i<=n; i++)
	{
		cin >> pos;
		if (pos < 0)
		{//矿洞所在数轴位置在负半轴 
			l[-pos] = 1;//有矿洞可以挖 
		}
		else if (pos > 0)
		{
			r[pos] = 1;
		} 
		else
		 {
		 	l[0] = r[0] = 1;//挖矿的一开始就需要判断起点时候就能挖到 
 		 }
	}
	int flag=0;if(l[0] == 1)flag=1;
	int ans = 0;//取3条策略的最值
	//往左 -----1
	int temp=0;
	for (int i = 1; i<=m; i++)
	{
		suml[i] = suml[i-1] + l[i];
	}
	temp += suml[m] + flag;
	ans = max(temp, ans);
	//往右-----2
	temp=0;
	for (int i = 1; i<=m; i++)
	{
		sumr[i] = sumr[i-1] + r[i];
	}
	temp += sumr[m] + flag;
	ans = max(temp, ans);
	//一次折返----3
	temp = 0;
	if (suml[m] == 0)//一直往左没有矿，就按策略2走 
	{
		
	}
	else
	{//否则往左走， 找到第一个矿就折返 
		for (int i =1; i<=m;i++){
			if (l[i] == 1 && l[i+1] != 1)
			{//走了i步，折返 
				if (m-2*i>0 )
				{//可以折返回0点，往右走 
					temp = 1 + sumr[m-2*i] + flag;
					ans = max(temp, ans);
					break;
				}
				else ans == max(temp, suml[i]);
			}
		}
	} 
	//先右后左
	for (int i =1; i<=m;i++)
	{
		if (r[i] == 1 && r[i+1]!=1)
		{//走了i步，折返 
			if (m-2*i>0 )
			{//可以折返回0点，往右走 
				temp = 1 + suml[m-2*i] + flag;
				ans = max(temp, ans);
				break;
			}
			else ans == max(temp, sumr[i]);
		}
	} 
	cout << ans << endl;
	return 0;
}
