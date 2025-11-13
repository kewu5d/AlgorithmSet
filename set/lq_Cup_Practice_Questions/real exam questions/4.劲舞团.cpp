#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
typedef struct 
{
	char ans;
	char you;
	ll time;
}txt;
int main()
{
	txt t;
	cin >> t.ans >> t.you >> t.time;
	ll pretime = t.time;
	int K=0, temp = 0;
	if (t.ans == t.you)K=1;
	while (cin >> t.ans >> t.you >> t.time)
	{
		//
		if (t.time == -1) break;//不能自动结束读入 
		//
		if (t.ans == t.you && t.time-pretime <=1000)
		{
			K++;
		}
		else if(t.ans == t.you) 
		{
			if (K > temp)temp =K;
			K = 1;//没连上，但按对了，K=1 
		}
		else 
		{//没对上，K=0 
			if (K > temp)temp =K;
			K=0; 
		}
		pretime = t.time;
	}
	K = temp;
	cout << K << endl;
	return 0;
}

