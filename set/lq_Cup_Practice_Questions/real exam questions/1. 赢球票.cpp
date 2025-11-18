/*
N张
数数cnt，cnt>N是无法拿走卡片.或者卡片全部被取走 
取余，是像个圆圈一样循环起来 
注意！！！！！！！求收取卡片的数字之和 
注意！！！！！！！！！！！！随便你从哪里开始数，求最多 
*/
#include <iostream> 
#include <cstdio>
#include<cstdlib> 
#include <cstring>
#include <math.h>
using namespace std;
int main()
{
	int n;cin >> n;
	int a[105];
	int flag[105] = {0};//0没取1取过了 
	for (int i=0; i<n;i++)
	{
		cin >> a[i];
	}
	int cnt = 1;
	int ans = 0;//求最大，初始化最小 （一张没取） 
	for (int i = 0;i<n;i++)
	{
		memset(flag, 0, sizeof(flag));//#include <cstring>
		int s = i;//start,第i-1轮 
		int temp= 0;//本轮的答案 
		int num = n;
		cnt = 1; 
		while (cnt <= n)
		{
			if(a[s] == cnt && flag[s] == 0) 
			{
				temp += cnt;
				flag[s] = 1;//取走
				num--;
				if (num == 0)break;
				s = ++s % n ;//!!!!取余 
				cnt = 1;
			}
			else if (flag[s] == 1)
			{
				s = ++s % n ;
				//cnt++;直接跳过这个被已经拿走了，数 下一个，cnt不变 
			} 
			else
			{
				s = ++s % n ;
				cnt++;
			}
		}
		ans = max(ans, temp);
	}
	
	cout << ans << endl;
	return 0;
}

