/*
问题：2023有多少个约数 
*/ 
#include <iostream>
using namespace std;

int main() 
{
	int n = 2023;
	int cnt = 0;
	for (int i = 1; i <= n/i; i++)
	{
	//n/i:避免使用sprt函数，但要<=， 避免遗漏n是完全平方的情况 
		if (n%i == 0)
		{
			if (i != n/i)	//*********注意这里是不等于************* 
			{
				cnt += 2;	//i和 n/i 都是n的约数 
			}
			else
			cnt++;	//只有i是n的约数 (i^2 = n)
		}
		
	}
	cout << cnt << endl;
	return 0;
}
/*
#include <iostream>  
#include <cmath>  
using namespace std;  

int main()   
{  
    int n = 2023;  
    int divisorCount = 0;  
    int sqrtN = static_cast<int>(sqrt(n));  

    for (int i = 1; i <= sqrtN; i++)  
    {  
        if (n % i == 0)  
        {  
            divisorCount++; // 计数i  
            if (i != n / i)  
            {  
                divisorCount++; // 计数n/i  
            }  
        }  
    }  
    cout << "The number of divisors is: " << divisorCount << endl;  
    return 0;  
}*/
