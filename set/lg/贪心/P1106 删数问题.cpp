#include <iostream>
#include <string>
#include <vector>
using namespace std;
string n;
int k;
vector<char> ans;
int main()
{
	cin >>n;cin >> k;
	//保留len(n) -k位数----逆向 
	//从左往右选数保留
	//第一数不能选0！！！！ -----------------------此思想错误，0可以做开头并且忽略掉 --------最后去除前导0即可 
	int cnt = n.size()-k;
	int pos = -1;
	while (cnt)
	{
		int temp = 257;//超过字符最大值 
		for (int i=pos+1; i<=n.size()-cnt; i++)
		{//在0~size-cnt必须要选出第一位（否则无法达到删除k位数的题目要求），以此类推 
			if (n[i] < temp )
			{	
				temp = n[i];pos = i;
			}
		}
		ans.push_back(n[pos]);
		cnt--;//选出了一个数 
	}
	//去除前导0
	int start=0;//别忘了ans是字符类型 
	while (ans[start] == '0'&& ans.size()>1) start++;
	for (int i=start; i<ans.size(); i++) cout << ans[i];
	cout << endl;
	return 0;
}
