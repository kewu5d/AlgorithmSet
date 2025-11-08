#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> a;
int main()
{
	a.push_back(-1);//从1开始存储 
	int n;
	cin >> n;
	for (int i=1;i <= n;i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}
	int ansss = 0;
	int ans[100005][100005] = {0};//初始化为0，1表示[i][j] i是j的因子
	for (int i = 1; i<= n;i++)
	{
		for (int j = i+1;j<=n;j++ )
		{
			if(a[i] % a[j] == 0)
			{//j是i的因子 
				ans[j][i] = 1;
				ansss++;
				
			}
			else if(a[j] % a[i] == 0){
				ans[i][j] = 1;
				ansss++;
			}
		}
	}
	cout << ansss-1 << endl;
	return 0; 
}
