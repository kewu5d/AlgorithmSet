#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
const int N = 1e5+5;
pair<int, int> p[N];//
int id[N];
bool cmp(pair<int , int> a, pair<int, int> b)
{
    if (a.second != b.second)
    {
        return a.second < b.second;// 升序
    }
    else
    {
        return a.first < b.first;
    }
}
int main()
{ 
        int n, d, k;cin >> n >> d >> k;//d为时间差 
        for (int i=1; i<= n; i++)
        {
            cin >> p[i].first >> p[i].second;
        }
        sort(p+1, p+n+1, cmp);// 1~n
        //cout << "here!!!!!!!!!!!!!!!!11111";
//        for (int i=1; i<= n; i++)
//        {
//            cout << p[i].first << ' ' << p[i].second << endl;
//        }
        int l=1, r = 1;
        int temp = 0;
        while(r <= n)	//右边框为n 
        {	
           if (p[r].second == p[l].second && p[r].first-d < p[l].first)
           {//此id合法 
           		temp++;//加完就可以判断 
				if (temp >= k)
				{
					cout << p[l].second << endl;
					temp = 0;
					while (p[r].second == p[l].second && r<n)r++;
					l = r;//移过来尺取下一个id的点赞数 
					continue;
				}
		   }
		   else if (p[r].second != p[l].second) 
		   {
		   		l = r;//移过来尺取下一个id的点赞数 
		   		continue;
		   }
		   while(p[r].first-d >= p[l].first && l<r) 
		   {//时间间隔过长，缩小 
		   		temp--;
				l++; 
		   }
		   if (p[r].first-d < p[l].first)continue;
		   r++;
        }
    return 0; 
}
