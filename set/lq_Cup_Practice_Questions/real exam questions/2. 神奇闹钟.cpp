/*格式为 уууу-MM-ddHH:mm:ss 
这个时间点之前 (包含这个时间点) 的最近的一次闹铃时间是哪个时间---先判断下这个时间是不是 
重点：从纪元时间（1970 年 1 月 1 日 00：00：00）开始响，每x分钟响一次
	输入时间前x分钟内，必定响过 
	@@@时间-》秒数，秒数-》时间来处理。关键在于时间的处理和时间的读取输出上。
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;
typedef struct 
{
	int year, month, day;
	int hour, m, s;
}Time;

int main()
{
	int T; cin >> T;
	//Time t[T];
	//for (int i = 0 ;i<T; i++)
	while (T--)
	{
		string tt;int x;
		//cin >> tt;
		printf("%s", &tt);
		getchar();
		printf("%d", &x);
		Time* s = (Time*)malloc(sizeof(Time));
		s->year = tt.stoi(tt.substr(0, 4));
		s->month = tt.stoi(tt.substr(5, 2));
		s->day = tt.stoi(tt.substr(8, 2));
		s->hour = tt.stoi(tt.substr(11, 2));
		s->m = tt.stoi(tt.substr(14, 2));
		s->s = tt.stoi(tt.substr(17, 2));
		//转化为距离1970.1.1的秒数---注意闰年 
		//处理输入样例所在年月的天数
		 
	}
		
	
	
	
}
