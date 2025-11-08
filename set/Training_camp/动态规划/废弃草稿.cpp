#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;
LL getmod(int x)
{
    int ans = 1;
    while(x)
    {
        x /= 10;
        ans *= 10;
    }
    return ans;
}

int main()
{
    int ans = 0;
    for(LL i = 1; i <= 1E4; ++i)
    {
        LL m = getmod(i);
        LL t = i * i * i;
        if(t % m == i)
        {
            ans++;
            printf("%lld %lld\n", i, t);
        }
    }
    cout << ans;
    return 0;
}
