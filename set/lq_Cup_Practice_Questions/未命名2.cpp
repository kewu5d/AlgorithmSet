#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  // 请在此输入您的代码]
  int t; cin >> t;
  while (t --){
    string s; cin>>s;
    sort(s.begin(), s.end());
    if (s[0] != s[3] && (s[1] == s[3] || s[0] == s[2])) puts("Yes");
    else puts("No");
  }
  return 0;
}
