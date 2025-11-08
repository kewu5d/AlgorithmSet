#include <iostream>
#define double int
using namespace std;
double a, b, c; 
double x, y, z;
bool check(double i, double j, double m, double y, double z)
{
	if (y/100 != y/10%10 && y/100 != y%10 && y%10 != y/10%10)
	{
		if (z/100 != z/10%10 && z/100 != z%10 && z%10 != z/10%10)
		{
			if (i!=y/100 && i!=y/10%10 && i!=y%10 &&  i!=z/100 && i!=z/10%10 && i!=z%10 )
			if (j!=y/100 && j!=y/10%10 && j!=y%10 &&  j!=z/100 && j!=z/10%10 && j!=z%10)
			if(m!=y/100 && m!=y/10%10 && m!=y%10 &&  m!=z/100 && m!=z/10%10 && m!=z%10)
			{
				if (y/100!=z/100 && y/100!=z/10%10 && y/100!=z%10   &&   y/10%10!=z/100 && y/10%10!=z/10%10 && y/10%10!=z%10)
				if (y%10!=z/100 && y%10/100!=z/10%10 && y%10!=z%10 )
				return true;
			}
		}
	}
	return false;
}
int main()
{
	cin >> a>>b>>c;
	int flag =0;
	for (int i=1; i<=9;i++)
		for (int j=1; j<=9; j++)
			for (int m=1; m<=9;m++)
			{
				if (i!=j && i!=m && j!=m)
				{
					double x = i*100+j*10+m;
					double y = x/a * b;
					double z = x/a * c;
					if (x < 1000 && y<1000&&z<1000&& check(i, j, m, y,z))
					{
					    flag =1;
						cout << x <<' '<< y <<' '<< z << endl;
					}	
				}
				
			}
	if (flag ==0)cout << "no!!!" << endl;
	return 0;
}
