#include <bits/stdc++.h>
#define lp(i,a,b) for(ll i=a;i<b;i++)
#define float double
#define PI 3.14159265358979323846
#define pb push_back
#define mp make_pair
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define ceil(a) (ll) ceil(a)
#define floor(a) (ll) floor(a)
#define pow(a,b) (ll) pow(a,b)
#define fixed(x) cout<<fixed<<setprecision(6)<<x;
#define gcd(a,b) (ll) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define integer_to_string to_string
#define IOS  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;
using namespace std;
const ll  mod = 1000000000 + 7;
ll modd(ll a, ll b) {
  ll c = a % b;
  return (c < 0) ? c + b : c;
}
long long fact(long long x)
{
    long long c=1;
    if(x==0 || x==1) return 1;
    for(long long i=1;i<=x;i++)
    {
        c*=((i)%mod);
        c%=mod;
    }
    return c%mod;
}
ll digits(long long x)
{
    ll c=0;
    if(x==0) return 1;
    while(x>0)
    {
        x/=10;
        c++;
    }
    return c;
}
long long poww(long long x,long long y)
{
    long long c=1;
    for(ll i=1;i<=y;i++)
    {
        if(c>=1000000000000000000) return c;
        c*=x;
    }
    return c;
}
ll ncr(ll n,ll r)
{
    ll c1=1,c2=1,x=n,y=r;
    for(ll i=1;i<=r;i++)
    {
        c1*=x;
        c2*=y;
        ll z=gcd(c1,c2);
        c1/=z;
        c2/=z;
        x--;y--;
    }
    return (c1/c2);
}
/* Iterative Function to calculate (x^y)%p
in O(log y) */
ll power(ll x,ll y, ll p)
{
    ll res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
    // equal to p

    while (y > 0)
    {

        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

// Returns n^(-1) mod p
ll modInverse(ll n, ll p)
{
    return power(n, p - 2, p);
}

// Returns nCr % p using Fermat's little
// theorem.
ll nCrModPFermat(ll n,ll r, ll p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;

    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    ll fac[n + 1];
    fac[0] = 1;
    for (ll i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}

int main()
{
    IOS;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll t=1;
    cin>>t;
    while(t--)
    {
         ll n;
         cin>>n;
         ll a[n];
         //vector<pair<ll,ll>> o,e;
         vector<pair<ll,ll>> ans;
         multiset<pair<ll,ll>> s;
         multiset<pair<ll,ll>> :: iterator it;
         for(int i=0;i<n;i++)
         {
             cin>>a[i];
             s.insert(pair<ll,ll>(a[i],i));
             //if(a[i]%2==0) e.pb(pair<ll,ll>(a[i],i));
            // else o.pb(pair<ll,ll>(a[i],i));
         }
         /*while(1){
             it=s.begin();
         if(it->first==0) s.erase(it);
         else break;
         }*/
         while(s.size()>1)
         {
             it=s.begin();
         if(it->first==0) {s.erase(it);continue;}
             auto x=s.begin();
             auto y=s.end();
             y--;

             for(int j=0;j<it->first;j++)
             {
                 ans.pb(pair<ll,ll>(x->second,y->second));
             }
             ll k=y->first-x->first,k1=y->second;
             s.erase(x);
             s.erase(y);
             s.insert(pair<ll,ll>(k,k1));
         }
         /*e.pb(pair<ll,ll>(0,0));
         o.pb(pair<ll,ll>(0,0));
         sort(e.begin(),e.end());
         sort(o.begin(),o.end());
         for(int i=0;i<e.size()-1;i++)
         {
             if(e[i].first==0) continue;
             for(int j=0;j<e[i].first;j++)
             {
                 ans.pb(pair<ll,ll>(e[i].second,e[i+1].second));
             }
             e[i+1].first-=e[i].first;
             e[i].first=0;
         }
         for(int i=0;i<o.size()-1;i++)
         {
             if(o[i].first==0) continue;
             for(int j=0;j<o[i].first;j++)
             {
                 ans.pb(pair<ll,ll>(o[i].second,o[i+1].second));
             }
             o[i+1].first-=o[i].first;
             o[i].first=0;
         }
         for(int j=0;j<min(o[o.size()-1].first,e[e.size()-1].first);j++)
             {
                 ans.pb(pair<ll,ll>(o[o.size()-1].second,e[e.size()-1].second));
             }
             cout<<ans.size()<<endl;
             for(int i=0;i<ans.size();i++)
             {
                 cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
             }*/
              cout<<ans.size()<<endl;
             for(int i=0;i<ans.size();i++)
             {
                 cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
             }
    }





   return 0;
}// find out what are sortings and vectors using arryas and swaps prob.....
