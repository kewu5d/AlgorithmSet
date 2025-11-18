#include <iostream> 
using namespace std;

int gcd(int a, int b)
{
	return b==0?a:gcd(b, a%b);
}
int main()
{
	
	//cout << gcd(2632, 308);
	cout << "55,94,56"<< endl;
	return 0;
}
