/**
 *   Author: aksayushx
**/
#include<bits/stdc++.h>
#define F       first
#define S       second
#define all(a)  a.begin(),a.end()
#define sz(x)   (long long)x.size()
#define uniq(a) a.erase(unique(all(a)),a.end())
#define pb      push_back
#define mp      make_pair
#define mod     1'000'000'007
#define MOD     998244353
#define pi      3.141592653589793238462
#define pll     pair<ll,ll>
#define setp(x) fixed<<setprecision(x)
#define deb(x)  cerr<<#x<<"="<<x<< '\n'
using namespace std;
typedef long long ll;
typedef long double ld;

ll power(ll x,ll y,ll m);
ll modInverse(ll n,ll m);
ll nCr(ll n,ll r,ll m);
ll ceiling(ll x,ll y);


const ll inf=1e16;


ll powe(ll x){
    ll v=1;
    for(ll i=1;i<=x;i++){
        v*=10;
    }
    return v;
}

void aksayushx()
{
    ll n,k;
    cin>>n>>k;
    ll dp[n+1][k+1][2]={0};
    for(ll i=1;i<=k;i++){
        dp[1][i][0]=0;
        dp[1][i][1]=1;
    }
    for(ll i=2;i<=n;i++){
        for(ll mx=1;mx<=k;mx++){
            if(mx<i){
                for(ll prev=1;prev<=mx;prev++){
                    dp[i][mx][0]+=(dp[i-1][prev][0]+dp[i-1][prev][1]);
                    dp[i][mx][0]%=MOD;
                }
                dp[i][mx][0]+=(mx-1)*(dp[i-1][mx][0]+dp[i-1][mx][1]);
                continue;
            }
            dp[i][mx][0]+=(mx-1)*dp[i-1][mx][0];
            dp[i][mx][1]+=(mx-1)*dp[i-1][mx][1];
            dp[i][mx][0]%=MOD;
            dp[i][mx][1]%=MOD;
            dp[i][mx][0]+=(dp[i-1][mx][0]+dp[i-1][mx][1]);
            dp[i][mx][0]%=MOD;
            for(ll prev=1;prev<mx;prev++){
                dp[i][mx][1]+=(dp[i-1][prev][0]+dp[i-1][prev][1]);
                dp[i][mx][1]%=MOD;
            }
            //cout<<i<<' '<<mx<<' '<<dp[i][mx][0]<<' '<<dp[i][mx][1]<<'\n';
        }
    }
    ll ans=0;
    for(ll mx=1;mx<=k;mx++){
        ans+=dp[n][mx][0];
        ans%=MOD;
    }
    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifdef AKSAYUSHX
    (void)!freopen("input.txt","r",stdin);
    (void)!freopen("output.txt","w",stdout);
    (void)!freopen("error.txt","w",stderr);
    #endif
    int t=1,x=1;
    //cin>>t;
    while(t--)
    {
        //cout<<"Case #"<<x++<<": ";
        aksayushx();
    }
    return 0;
}


// Returns x raised to the power y modulo mod
ll power(ll x, ll y, ll m=mod)  
{  
    ll res = 1; 
    x = x % m;
    if (x == 0) return 0;
    while (y > 0)  
    {  
        if (y & 1)  
            res = (res*x) % m;  
        y = y>>1; 
        x = (x*x) % m;  
    }  
    return res;  
}

ll modInverse(ll n,ll m=mod) 
{ 
    return power(n, m-2,m); 
}

ll ceiling(ll x,ll y)
{
    return (x+y-1)/y;
}
/*
ll nCr(ll n,ll r,ll m=mod) 
{ 
    if (r == 0) 
        return 1;
    return (fac[n] * modInverse(fac[r],m) % m * modInverse(fac[n - r],m) % m) % m; 
}*/ 