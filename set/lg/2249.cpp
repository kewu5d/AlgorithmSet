#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e6+5;
int numb[N];
int n, m;
int main()		//有一个超时样例！！！！！！！！！！！ 
{				//可惜打不了表（bushi） 
    scanf("%d %d", &n, &m);
    for (int i=1;i<=n; i++)scanf("%d", &numb[i]);
    
    while (m--)
    {
        int l = 1, r = n;
        //int flag = 1;
        int t;scanf("%d", &t);
        int temp = -1;
        while (l <= r)
        {
            int mid = l + (r-l)/2;//mid=1+(r-1)/2是一种防止l+r溢出整数范围的一种写法，数学上等价(l+r)/2
//            if (t == numb[mid])
//            {
//                // 注意：返回第一次出现的编号
//                while(mid-1 > 0)
//                {
//                    if(numb[mid-1] == t)mid--;
//                    else  break; 
//                }
//                printf("%d ", mid);
//                flag = 0;break;
//
//             }
			 
            if (t <= numb[mid]) 		//等于也去左边找，找相同的第一个位置
			{									//---不用担心会不会左边界卡住相同的数，自身模拟下就知道了 
				r = mid-1;	
				if (t == numb[mid])temp = mid;
			} 										
             else l = mid+1;//猜小了 
        }
        //if (flag)printf("%d ", -1);
        if (numb[l] == t)printf("%d ", l);
        else
        {
        	printf("%d ", temp);//始终没找到，temp为-1 
		}
    }
    return 0;
}
