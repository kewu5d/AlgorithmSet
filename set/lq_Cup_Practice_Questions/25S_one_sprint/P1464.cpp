#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
ll x, y, z;
ll w[25][25][25];//0~20，题目大于 20或小于0都会打到这个范围 
ll f(ll a, ll b, ll c)
{
	//先判断下a、b、c是否合法啊，下标只能在0~24 --------------------否则会爆RE噢 
	
	//同时满足按，满足条件的先后顺序
	if (a<=0 || b<=0 || c<=0) 
	{
		if (a<0 || b<0 || c<0) return 1;
		return w[a][b][c] = 1;//负数下标存不了 
	}
	else if (a>20 || b>20 || c>20)
	{
		return w[20][20][20] = f(20, 20, 20);
	}
	else if(w[a][b][c] != 0)
		return w[a][b][c];//--------------------放这里再判断 
	else if (a<b && b<c)
	{
		w[a][b][c-1] = f(a, b, c-1);
		w[a][b-1][c-1] = f(a, b-1, c-1);
		w[a][b-1][c] = f(a, b-1, c);
		return f(a, b, c-1)+f(a, b-1, c-1)-f(a, b-1, c);
	}
	else {
		w[a-1][b][c] = f(a-1, b, c);
		w[a-1][b-1][c] = f(a-1, b-1, c);
		w[a-1][b][c-1] = f(a-1, b, c-1);
		w[a-1][b-1][c-1] = f(a-1, b-1, c-1);
		return f(a-1, b, c)+f(a-1, b-1, c)+f(a-1, b, c-1)-f(a-1,b-1,c-1);
	}
}
int main()
{
	while (true)
	{
		cin>> x>>y>>z;
		if (x==-1 && y==-1 && z==-1)break;
		printf ("w(%lld, %lld, %lld) = %lld\n", x,y,z, f(x,y,z));
	} 
	return 0;
} 
