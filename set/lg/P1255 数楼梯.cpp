#include <iostream>
using namespace std;
int n;
int f[5005][5005];//f[n][高精度表示]级台阶的走法数 
int len;//，倒序输出f[n][ ] 
void high_add(int x)
{
	//这种判断方式，如果中途恰好两数在同一位数为0，就会提前终止 
	//for (int i = 1; f[x-1][i] != 0 || f[x-2][i]!=0; i++)
	//i <= 5000直接把时间复杂度拉满，牺牲时间 
	for (int i = 1; i <= 5000; i++)
	{
		f[x][i] += f[x-1][i] + f[x-2][i];//从个位往后加 
		if(f[x][i] >= 10) 
		{
			f[x][i] -= 10;
			f[x][i+1]++;
		}
		len = i+1;
	}
	//去除前导0
	while (f[x][len] == 0) len--;
}
int main()
{
	cin >> n;
	f[1][1] = 1, f[2][1] = 2;
	for (int i= 3;i <=n; i++)
	{
		high_add(i);
		//for (int j = len; j>0; j--) cout << f[i][j];
		//cout << ' ';
	}
	//输出
	if (n ==1 || n==2)
	{
		cout << f[n][1];
	}else
	{
		for (int i = len; i>0; i--) cout << f[n][i];
	 } 
	cout << endl;
	return 0;
	
}
