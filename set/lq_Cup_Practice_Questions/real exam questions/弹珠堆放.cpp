#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int b[100000], bsum[100000];//预开大小 
int main()
{
	int h=1;//高度
	b[h]  = 1;//h层数量 
	bsum[h] = 1;//高h总数 
	while (bsum[h] <= 20230610) 
	{
		h++;
		b[h] = b[h-1] + h;
		bsum[h] = bsum[h-1] + b[h];
	}
	cout << h-1 << endl;
	return 0;
}
