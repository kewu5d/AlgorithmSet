#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> p;
ll a[4][1000];
string s;
int main(void) 
{
    cin>>s;
    for(ll i=0;i<s.length();i++){
        //for(ll j=i;j<=i+3;++j){
            a[i%4][s[i]]++;//0,1,2,3各位置字符数，s[i]字符做下标 
        //}
    }
    ll ans=0;
    for(ll i=0;i<s.length()-3;i++)	//枚举到len-3为止，加上本身和最后三个字符，凑最后一个可能密钥 
	{
        if(a[i%4]['b']>0){
            if(a[(i+1)%4]['l']>0){
                if(a[(i+2)%4]['u']>0){
                    if(a[(i+3)%4]['e']>0)
					{
                        a[i%4]['b']--;
                        a[(i+1)%4]['l']--;
                        a[(i+2)%4]['u']--;
                        a[(i+3)%4]['e']--;
                        ans++;
                        i+=3;//配合i++,相当于i+=4连续判断下一个完整（4个为一组）可能的密钥 
                    }
                    //当以上条件不能同时满足时，只i++，换个blue的起始点枚举判断b-l-u-e 
                }
            }
        }
    }
    cout<<ans;
    return 0;    
}
