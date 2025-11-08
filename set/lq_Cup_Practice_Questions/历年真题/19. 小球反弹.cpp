#include <iostream>
#include <cstdio>
#include <math.h>
#define ll long long
using namespace std;
int main()
{
	ll t = 1;
	int dx = 15, dy = 17;
	while (1)
	{
		if (dx * t % 343720 == 0 && dy *t % 233333 == 0)
		{//到达某一个角落，开始往回返 
			break; 
		}
		else t++;//继续运动，时间继续 
	}
	printf ("%.2f", 2*sqrt(dx*t*dx*t + dy*t*t*dy));//注意原路返，路程*2
	return 0;
}
