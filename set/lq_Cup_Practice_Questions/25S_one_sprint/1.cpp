#include <bits/stdc++.h>
using namespace std;

int n, card[105];
int vis[105];//是否数过 
int main()
{
	cin >> n;
	int maxcard = 0; 
	for (int i=0; i<n; i++){
		cin >>card[i];
		maxcard = max(maxcard, card[i]);
	}
	
	int maxans = 0;
	for (int i=0; i<n; i++)
	{
		int pos = i;//枚举开始数的card位置
		memset(vis, 0, sizeof(vis)) ;
		int cnt = 1;//数数
		int num = n;//总牌数
		int ans = 0;
		//两种情况跳出循环：1.全部数完，2.数到的数字大于最大牌面数 
		while (num>0)
		{
			if (card[pos] == cnt && vis[pos] ==0)
			{
				//ans++;
				ans += card[pos];
				vis[pos] = 1;
				cnt = 1;//下一个重新数 
				num--;
				pos = (pos+1)%n;
			}
			else if (vis[pos]== 1)
			{
				pos = (pos+1)%n;
			}
			else {//没拿过但是不等于cnt 
				cnt++;
				if (cnt > maxcard)break;
				pos = (pos+1)%n;
			}
		}
		maxans = max(maxans, ans);
		
	}
	cout << maxans << endl;
	return 0;
}
