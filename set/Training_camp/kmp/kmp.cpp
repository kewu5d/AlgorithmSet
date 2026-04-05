#include <iostream>
#include <string>
#include <vector>
using namespace std;
//kmp优于BF算法的关键点在于：
//- 没有让主串指针i 和模式串指针j都*完全*回退
//- 保持i不动，让j回到模式串中最长相同前后缀的位置在开始匹配
//- 最长相同前后缀：原先匹配上已知的最大节省回退点
int kmp(const string& zhu, const string& mo)
{
    int n = zhu.size();
    int m = mo.size();
    if (m == 0)return 0;//模式串为空(一般不会为空，约定匹配位置为0)
    if (m > n) return -1;//一定失配

    //1. 构建nextt数组
    // next[i] 表示当 pattern[i] 失配时，j 应该跳转到的位置
    // 物理含义：⚠️pattern[0...i-1]⚠️ 子串的最长相等前后缀长度    
    vector<int> nextt(m, 0);
    nextt[0] = -1;
    int i = 2;  //当前要填 nextt[i]
    int y = nextt[i-1]; //nextt[0...i-1]都已知
    while (i < m)
    {
        if(mo[i-1] == mo[y] )
        {
            nextt[i] = nextt[i-1] + 1;
            i++;
        }
        else {
            //模式串在i-1位置发生了失配，采用自己匹配自己
            //i-1不动；y进行回退
            y = nextt[y]; //回退有限度y == -1
        }
        if (y == -1){
            nextt[i++] = 0;
        }
    }

    //2. 利用nextt数组，进行kmp匹配，返回结果
    i = 0;      //这里表示匹配主串指针
    int j = 0;
    while (i < n && j < m)
    {
        if (zhu[i] == mo[j])
        {
            i++; j++;//该位置匹配上，进行下一位置的匹配
        }//否则没匹配上，j按照nextt数组进行回退
        else if (nextt[j] == -1)
        {//回退到了限制
            //当前i位置失配，对下一个位置尝试匹配
            i++;
        }
        else {
            j = nextt[j];//j回退,i不动
        }
    }
    return (j == m)? i-j: -1;   //返回首次匹配起始下标(0-based)
}

int main()
{
    string p, s;//主串p、模式串s
    cin >> p >> s;
    int res = kmp(p, s);
    if (res != -1)
    {
        cout << res << endl;
    }
    else cout << "失配" << endl;
    return 0;
}