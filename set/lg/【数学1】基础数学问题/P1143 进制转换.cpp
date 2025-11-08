#include <iostream>
#include <string>
#include <cmath>	//使用pow（a,n） 
#include <vector>
#define ll long long
using namespace std;
int n, m;
string tar;
vector<char> ans;
///十进制做跳板 
int main()
{
	cin >> n >> tar >> m;//(tar)n --> (tar)m
	ll temp = 0;
	//倒着转，从低位开始 
	int idx = 0;
	for (int i=tar.size()-1; i >=0; i--)
	{
		if (tar[i] >= 65)
		{
			temp += (tar[i] - 'A' +10) * pow(n, idx);
		}
		else{
			temp += (tar[i] - '0') * pow(n, idx);
		}
		idx++;
	}
	//十进制temp，转m进制，注意》10，使用A~F
	//0:48,A:65
	while (temp !=0 ) 
	{
		//除基取余 
		char x;
		if (temp %m >=10)
		{
			x = 'A' + temp%m -10;
			ans.push_back(x);
		}else
		{
			x = temp%m + 48;
			ans.push_back(x);
		}
		temp /= m;
	}
	//倒着读 
	for (int i=ans.size()-1; i>=0; i--){
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
