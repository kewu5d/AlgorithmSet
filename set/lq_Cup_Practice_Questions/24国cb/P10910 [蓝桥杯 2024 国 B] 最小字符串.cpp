#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s, c;
int n,  m;
int main()
{
	cin >> n >> m;
	cin >> s >> c;
	sort(c.begin(), c.end());//先对待插入字符按升序排列
	
	for (int i=0, j=0; i<=n && j<=m;)
	{
		if (i == n)	cout << c[j++];
		else if (j == m) cout << s[i++];
		else if (c[j] < s[i])
		{
			cout << c[j];//插入在这里
			j++;
		}
		else {
			cout << s[i];//大于等于都输出原s字符串中的字符 
			i++;
		}
	}
	cout << endl;
	return 0;
}
