/*输入一行包含一个字符串。
【输出格式】
如果包含 LANQIAO ，输出一个英文单词 YES ，否则输出一个英文单词 NO 。
【样例输入】
LLLLLANHAHAHAQLANIIIIALANO
【样例输出】
YES
【样例输入】
OAIQNAL
【样例输出】
NO
【评测用例规模与约定】
对于所有评测用例，输入的字符串非空串，由大写字母组成，长度不超过 1000 。
*/ 

#include <iostream>
using namespace std;

int main() 
{
	char a[1005];
	cin >> a;
	char b[] = "LANQIAO";
	int i = 0;
	int cnt = 0;
	//鄙人不才，动用暴力
	for (i; i < 1005; i++) 
	{
		if (a[i] == 'L')
		{
			//继承了找到的L位置的i值，接着往后找 
			for (i; i < 1005; i++) 
			{
				if (a[i] == 'A')
				{
					for (i; i < 1005; i++)
					{
						if (a[i] == 'N') 
						{
							for (i; i < 1005; i++)
							{
								if (a[i] == 'Q') 
								{
									for (i; i < 1005; i++)
									{
										if (a[i] == 'I') 
										{
											for (i; i < 1005; i++)
											{
												if (a[i] == 'A') 
												{
													for (i; i < 1005; i++)
													{
														if (a[i] == 'O') 
														{
															cnt = 1;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
							
				}
			}
			
		}
	}
	if (cnt == 1)
	{
		cout << "YES" << "\n";
	}
	else
		cout << "NO" << "\n";
		
//	cout << a << endl << b;
	//字符串比较函数
	 
	return 0; 
}
/*
#include <iostream>  
#include <string>  
using namespace std;  

int main() {  
    string input;  
    getline(cin, input); // 读取一行输入  

    string target = "LANQIAO"; // 目标字符串  
    int index = 0; // 用于记录目标字符串的匹配进度  

    // 遍历输入字符串  
    for (char c : input) {  
        if (c == target[index]) { // 如果当前字符匹配目标字符串的当前字符  
            index++; // 匹配进度加1  
        }  
        if (index == target.size()) { // 如果匹配完成  
            cout << "YES" << endl;  
            return 0;  
        }  
    }  

    // 如果遍历结束后仍未匹配完成  
    cout << "NO" << endl;  
    return 0;  
}*/
