#include <iostream>
#include <cmath>
#include <vector>	//避免10转2时倒着读，无法补0（满足32位） 
#define int long long
using namespace std;
int a[33];//存储二进位 -----这里使用vector下标从0开始存，而我的本意是从1开始 
signed main()
{
	int n ; 
	cin >> n;
	//十进制转2
	int len = 0;
	while (n != 0)
	{
		a[len+1] = n%2;//这里已经实现了倒着读 
		n /= 2;
		len++;
	}
	//倒着读
//	int t[len+1];
//	for (int i=1; i<=len; i++){
//		t[i] = a[len-i+1];
//	}
//	for (int i=1;i <=len;i++)a[i] = t[i];
	
	//补0 ----全局，可省 
//	while (len < 32){
//		a.push_back(0);len++; 
//	}
	//交换------可以使用swap函数 
	int temp[33] = {0};
	for (int i=1; i<=16; i++)
	{
		temp[i] = a[16+i];
		temp[16+i] = a[i];
	}
	for (int i =1; i<=32; i++)a[i] = temp[i];
	//2转10
	int ans = 0;
	for (int i=0; i<32; i++)
	{
		ans += a[i+1] * pow(2, i);
	}
	cout << ans << endl;
	return 0;
}
