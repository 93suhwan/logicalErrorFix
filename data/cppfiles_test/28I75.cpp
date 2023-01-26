#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long int ll;
typedef tree<
    ll,
    null_type,
    less<ll>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;
ll mod = 1000000007;
ll power1(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans *= a; // ans%=mod;
        }
        a *= a;
        b /= 2;
    }
    return ans;
}
ll power(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans *= a;
            ans %= mod;
        }
        a *= a;
        a %= mod;
        b /= 2;
    }
    return ans % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    // t = 1;
    cin >> t;
    while (t--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        b%=3;
        c%=2;
        ll ans=abs(3*c-2*b);
        if(c>0){
            if(b>0){
                if( a%2==1)
                cout<<0<<endl;
                else{
                    cout<<1<<endl;
                }
            }
            else{
                if(a<=3){
                    cout<<3-a<<endl;
                }
                else{
                    a-=3;
                    if(a%2==0)
                    cout<<0<<endl;
                    else{
                        cout<<1<<endl;
                    }
                }
            }
        }
        else{
            if(b%2==0){
                if( a%2==0)
                cout<<0<<endl;
                else{
                    cout<<1<<endl;
                }
            }
            else{
                if(a<=2){
                    cout<<2-a<<endl;
                }
                else{
                    a-=2;
                    if(a%2==0)
                    cout<<0<<endl;
                    else{
                        cout<<1<<endl;
                    }
                }
            }
        }
    }
}