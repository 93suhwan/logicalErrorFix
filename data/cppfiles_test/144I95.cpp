#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int  
#define fi first
#define sec second
#define mp make_pair
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<ll, null_type, std::less<ll>, rb_tree_tag , tree_order_statistics_node_update> ordered_set;
 
int t, n,m;
ll mod = 1e9+7;
ll multiply(ll a, ll b){
    ll ans = 0;
    for(ll i=40; i>=0; i--){
        ans = (ans*2ll)%mod;
        if((b>>i) & 1) ans = (ans+a)%mod;
    }
    return(ans);
}

ll power(ll e, ll x, ll mod)
{
   if(e == 0) return(0);
   if(x == 0) return(1);
   ll val = power(e, x/2, mod);
   val = multiply(val, val);
   if(x & 1) val = (val*e)%mod;
   return(val);    
}

ll gcd(ll a, ll b)
{
   a = abs(a);
   b = abs(b); 
   if(a < b) return(gcd(b,a));
   if(b == 0) return(a);
   return( gcd(b,a%b) ); 
}

ll query(ll a,ll b,ll c)
{
    ll val;
    cout<<"? "<<a<<" "<<b<<" "<<c<<endl;
    cout.flush();
    cin>> val;
    return val;
}

void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    if((n%m)==0)
    {
        ll x=(n/m);
        for(ll i=0;i<k;i++)
        {
            for(ll j=1;j<=n;j+=x)
            {
                cout<<x<<" ";
                for(ll l=0;l<x;l++)
                {
                    cout<<(j+l)<<" ";
                }
                cout<<endl;
            }
        }
    }
    else
    {
        ll x=(n/m);
        ll y=x+1;
        ll c1=0,c2=0;
        for(c1=1;c1<(m*k);c1++)
        {
            c2=m*k-c1;
            if((c1*x+c2*y)==(n*k)) break;
        }
        ll nc1=c1/k,nc2=c2/k,s=1;
        for(ll i=0;i<k;i++)
        {
            for(ll j=1;j<s;j+=x)
            {
                cout<<x<<" ";
                for(ll l=0;l<x;l++)
                {
                    cout<<(j+l)<<" ";
                }
                cout<<endl;
            }
            for(ll j=s;j<(s+nc2*y);j+=y)
            {
                cout<<y<<" ";
                for(ll l=0;l<y;l++)
                {
                    cout<<(j+l)<<" ";
                }
                cout<<endl;
            }
            for(ll j=s+nc2*y;j<=n;j+=x)
            {
                cout<<x<<" ";
                for(ll l=0;l<x;l++)
                {
                    cout<<(j+l)<<" ";
                }
                cout<<endl;
            }
            s=s+nc2*y;
            if(s>n) s=1;
            else if((s+nc2*y)>(n+1))
            {
                ll z=s+nc2*y-(n+1);
                //cout<<"    "<<s<<" "<<z<<endl;
                s-=z;
            }
        }
    }
    cout<<endl;
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   ll t;
   cin>>t;
   //t = 1;
   while(t--)
   {
       solve();
   }
}
