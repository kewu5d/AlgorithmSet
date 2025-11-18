#include <iostream>
using namespace std;
int a(int i)
{
	//递归出口忘记写了
	if (i==0) return 0;
	return i+a(i-1);
}
int b(int i)
{
	if (i == 0)return 1;
	return i*b(i-1);
}
int main()
{
//	for (int i=1;i<=10000; i++)
//	{
//		if((a(i)-b(i)) % 100 ==0)cout << i << ' ';
//	}
//	通过输出找规律。 1，3单独算，之后每个200就会有4个数学精灵 
	long long ans = 2024041331404202/200 *4 + 2;
	cout << ans << endl;
	return 0;
}
