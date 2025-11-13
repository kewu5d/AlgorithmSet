#include <iostream>
#include <vector>
using namespace std;
int n; // vis[4];
char a[3] = {' ', '+', '-'};//用数字0~2表示符号 
vector<int> ve;
bool check()
{
	int ans = 0; 
	for (int i=1; i<=n; i++)
	{
		if (ve[i] == 0)continue;//是空格不管它，在这之前会经计算过 
		
		//当前填的不是空格，而是是+或-，就去找下一个对象，
		//如果下一个对象有空格，计算空格构成的一个整体，再与当前对象+- 
		//草稿纸上写清楚各自的下标 
		int t = i; 
		for (int j=i+1; j<=n; j++)
		{ 
			if (ve[j] == 0)
			{
				t = t*10 + j;
			}
			else break;//没有空格/结束空格构成的整体 
			
			//ve.push_back(t);根本不需要这么复杂的操作 
		}
		//回过头来与当前对象相加减
		if(ve[i] == 1) ans += t;
		else ans -= t;
	
	}
	
	return ans == 0;
}
void print()
{
	cout << 1;
	for (int i=2; i<=n; i++)
	{
		cout << a[ve[i]] << i;//下标存符号 
	}
	cout << endl;
}
void dfs(int depth)
{
	if (depth > n)//填2~n个空 
	{//ve数组1~n个元素 
		if (check())
		{
			print();
		}
		return;
	}
	
//	for (int i=0; i<n-1; i++)//根据depth，该空三个符号任选 
	for (int j=0; j<3; j++)
	{//直接数字表示填的符号
	//char a[3] = {'+', '-', ' '};所以j=2表示填入空格' ' 
		ve.push_back(j);
		dfs(depth+1);
		ve.pop_back();
	}

}
int main()
{
	cin >> n;
	ve.push_back(-1);//非法值0下标不用，从1开始存
	ve.push_back(1);//在最前面填入+号 
	dfs(2);//对齐，填第二个数字间隔位 
	
	return 0;
}
