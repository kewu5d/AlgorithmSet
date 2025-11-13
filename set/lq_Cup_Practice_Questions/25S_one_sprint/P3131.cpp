#include <iostream>
#include <algorithm>
using namespace std;
int n, id[50005], sumid[50005];
int pos[7] = {-1, -1, -1, -1, -1, -1, -1};//初始化为-1（不能用0，0是余数之一），表示没有记录 
int main()
{
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		cin >> id[i];
		sumid[i] = sumid[i-1] + id[i];
		sumid[i] %= 7;
	}
	int maxans = 0;
	for (int i=0; i<=n; i++)//需要从0开始，前缀和的计算也是r-(l-1) 
	{
		//记录该余数首次出现位置 
		if (pos[sumid[i]] == -1) 
		{
			pos[sumid[i]] = i;
		}
		else{
			//再次出现
			maxans = max(maxans, i-pos[sumid[i]]);
		}
	}
	cout << maxans << endl;
	return 0;
}
