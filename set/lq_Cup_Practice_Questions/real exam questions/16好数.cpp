#include <iostream>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int idx = 1;
  int sum = 0;
  for (int i = 1; i<= n; i++)
  {
  	int x = i;
  	idx = 1;
    while (i!=0)
    {
      if (idx%2 == 1 && x%10%2 == 1) 
      {
        x /= 10;//是奇数,去掉一位判偶数，轮流判之
        idx++;
      }
      else if (idx%2 == 0 && x%10%2 == 0 ) {
        x /= 10;
        idx++;
      }
      else{
        break;//i不是好数
      }
    }
    if (x == 0)
    {
      sum++;
    }
 }
  // 请在此输入您的代码
  cout << sum << endl;
  
  return 0;
}
