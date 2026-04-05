#include <iostream>
#include <string>
using namespace std;
int main()
{
    string p, s;//主串p、模式串s
    cin >> p >> s;
    
    for (int i = 0; i < p.size(); i++)
    {
        int j;
        for (j = 0; j < s.size(); j++)
        {
            if (p[i] == s[j]) i++;
            else{
                i = i - j;//在i位置失配，i回退
                break;//跳过，j回退
            }
        }
        if (j == s.size())
        {//模式串全部匹配上，返回第一次出现串的首字符位置
            cout << i - j << endl;
            return 0;
        }
    }
    cout << "失配" << endl;
    return 0;
}