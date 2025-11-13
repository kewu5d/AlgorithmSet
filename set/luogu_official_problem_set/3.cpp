#include <iostream>
#include <vector>
using namespace std;

int sti[11] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
//拼出 0~9需要的火柴数
//A、B相等算一个等式，记录A=B等式的等式数量
//答案减去一半 （错误想法，不需要管实际上） 
int n, ans, cnt;
vector<int> ve;

bool check(int s)
{
	int C = ve[0] + ve[1];
	int t = 0;
	if (C == 0) t += sti[0];
	while (C>0)
	{
		t += sti[C%10];
		C /= 10;
	}
	return t == s;
}
void dfs(int step, int num)
{
	if (step > 2)
	{
		if (check(num))
		{
			ans++;
			//if (ve[1] == ve[0])cnt++;//不需要 
		}
		return;
	}
	//打调试一定要在提交前，将调试改回来 
	//时间复杂度1000^2----那就开大点！！！ 
	for (int i=0; i<=1000; i++)
	{
		int t = 0;//当前填的数的火柴数 
		int ii = i;
		if (ii == 0)t += sti[0];
		while (ii > 0)
		{
			t += sti[ii%10];
			ii /= 10;
		}
		if (num >= t)
		{
			ve.push_back(i);
			dfs(step+1, num-t);
			ve.pop_back();
		}
	}
}
int main()
{
	cin >> n;
	//根数最少的2+2=5(1+1=2) 
	if (n < 4+9)
	{
		cout << ans << endl;
		return 0;
	}
	dfs(1, n-4);
	cout << ans << endl;
	return 0;
}
