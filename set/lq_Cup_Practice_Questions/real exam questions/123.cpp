#include <iostream>
#include <cmath>
#define ll long long 
using namespace std;
int t;
ll li, ri;
ll m[1414221], sum[1414221];
ll summ(ll x) 
{
	//二分查找-----x在哪个区间[1, 1414220]
	ll l=1, r = 1414220, mid;
	while (l <= r)
	{
		mid = (l+r)/2;
		if (m[mid] > x)//个数和大于x，去左半边找
		{
			r = mid-1;
		 } 
		 else{
		 	l = mid +1;
		 }
	}
	ll temp = x -m[r];//x在r+1区间里 
	return sum[r] + (1+temp)*temp/2;
	
}
int main()
{
	//(1+n)*n= 2e12
	//cout << (long long)1414220*1414220;
	//预处理找到至少1414220个小区间（粗略的） 
	for (int i=1; i<=1414220; i++)
	{
		m[i] = m[i-1] + i;//第i个小区间数字的和，前i个小区间数字的个数和 
		sum[i] = sum[i-1] + m[i];//前i个区间总和 
	}
	cin >> t;
	while (t--)
	{
		cin >> li >> ri;
		cout << summ(ri)-summ(li-1) << endl;
	}
	return 0;
}
