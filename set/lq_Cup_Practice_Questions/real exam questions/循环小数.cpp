#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int p, q;
long long k, l, m, n;
long long x, y;//分子，分母 
long long gcd(long long a, long long b)
{
	return b==0? a: gcd(b, a%b);
}
int main()
{
	cin >> p >> q;
	string s;cin >> s;
	m = p-1, n = q-p+1;
	int t1=m, t2 = n;
	for (int i=0; i<m; i++)
	{
		k += (s[i]-'0') * pow(10, t1-1);
		t1--;
	}
	for (int i=p-1; i<q; i++)
	{
		l += (s[i]-'0') * pow(10, t2-1);
		t2--;
	}
	//得到了k、l、m、n，运用公式求解
	x = k * (pow(10, n)-1) + l;
	y = (pow(10, n) - 1) * pow(10, m);
	long long temp = gcd(x, y);
	cout << x/temp << ' ' << y/temp << endl;
	return 0;
}
