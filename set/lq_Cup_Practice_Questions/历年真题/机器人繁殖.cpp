#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	double s;
	int n, a0;
	cin >> n >> s;
	a0 = (s-1-n)/(pow(2, n+1)-1) + 1;
	cout << a0 << endl;
	return 0;

}
