/**
 *    Author:        Rye
 *    Data:        2021-11-02
**/
#include<bits/stdc++.h>
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
using namespace std;

const int maxn = 3e5+5;
const int mod = 1e9+7;

int a[maxn];

ll pow_mod(ll a,ll b){
    ll ans = 1;
    ll base = a%mod;
    while(b){
        if(b & 1) ans = (ans*base)%mod;
        base = (base*base)%mod;
        b >>= 1;
    }
    return ans;
}

ll lcm(ll a,ll b)
{
    return a*b/__gcd(a,b);
}


int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll x0,n;
        cin>>x0>>n;
//        n--;
        if(n==0)
        {
            cout<<x0<<endl;continue;
        }else
        {
            if(x0&1)
            {
                x0+=(n-1)/4*4+1;
//                cout<<x0<<" "<<(n-1)/4*4+1<<endl;
                for(ll nn = (n-1)/4*4+2; nn <= n; nn++)
                {
//                    cout<<nn<<" "<<((nn-1)%4==3||(nn-1)%4==0)<<endl;
                    if((nn-1)%4==3||(nn-1)%4==0)
                        x0+=nn;
                    else x0-=nn;
                }
            }else
            {
                x0-=(n-1)/4*4+1;
                cout<<x0<<" "<<(n-1)/4*4+1<<endl;
                for(ll nn = (n-1)/4*4+2; nn <= n; nn++)
                {
                    if((nn-1)%4==3||(nn-1)%4==0)
                        x0-=nn;
                    else x0+=nn;
                }
            }
            cout<<x0<<endl;
        }
    }
    return 0;
}
