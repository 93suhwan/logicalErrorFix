#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll int64_t
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define pb push_back
#define mp make_pair
#define pf push_front
#define rep(i,a,b,k) for(ll i=a;i<b;i+=k)
#define rept(i,a,b) for(auto i=a;i!=b;++i)
#define drep(i,a,b,k) for(ll i=a;i>=b;i-=k)
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,0,sizeof(a))
#define w(t) while(t--)
#define array(arr,n) vector<ll>arr(n);for(ll i=0;i<n;i++)cin>>arr[i];
#define ni1(t) ll t;cin>>t;
#define ni2(a,b) ll a,b;cin>>a>>b
#define ni3(a,b,c) ll a,b,c;cin>>a>>b>>c
#define ni4(a,b,c,d) ll a,b,c,d;cin>>a>>b>>c>>d
#define ni5(a,b,c,d,e) ll a,b,c,d,e;cin>>a>>b>>c>>d>>e
#define ni6(a,b,c,d,e,f) ll a,b,c,d,e,f;cin>>a>>b>>c>>d>>e>>f
#define ns(s) string s;cin>>s
#define print(x) for(auto ele:x)cout<<ele<<" ";cout<<endl;
#define printp(x)  for(auto ele:x)cout<<ele.first<<" "<<ele.second<<endl;
#define printm(m) for(auto x:m)cout<<x.first<<" "<<x.second<<endl;
const ll mod=1000000007;
const ll siz1=200005;
const ll siz2=1000005;
const ll INF = 1e16;
const ll intmax = INT_MAX;
const ll intmin = INT_MIN;
#define khatam return 0
#define xt first
#define yt second
#define all(x) x.begin(),x.end()
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vll;
typedef unordered_map<ll,ll> ull;
typedef map<ll,ll> mll;
typedef pair<ll,ll>pll;
inline ll mod_add(ll a,ll b,ll m){a = a % m;b = b % m;return (((a + b) % m) + m) % m;}
inline ll mod_mul(ll a,ll b,ll m){a = a % m;b = b % m;return (((a * b) % m) + m) % m;}
inline ll mod_sub(ll a,ll b,ll m){a = a % m;b = b % m;return (((a - b) % m) + m) % m;}
ll binPow(ll x,ll n,ll m){ll res=1;while(n){if(n&1) res=(res*x)%m;x=(x*x)%m;n>>=1;}return res;}
ll modInv(ll i, ll m) {return binPow(i,m-2,m);}
//vl fact(siz1);
//ll ncr(int n,int r) {return (n>=r?(fact[n]*modInv(fact[r],mod))%mod*modInv(fact[n-r],mod)%mod:0);}
//void factorial(){fact[0]=1;rep(i,1,siz1,1)fact[i]=(fact[i-1]*i)%mod;}
ll no_of_digits(ll a){ll cnt=0;while(a>0){a/=10;cnt++;}return cnt;}
ll _log(ll a,ll b){ll cnt=0;while(a>0){a/=b;cnt++;}return cnt;}
void init(int p){cout<<fixed<<setprecision(p);}
inline ll getmin(ll a,ll b){return min(a,b);}
inline ll getmin(ll a,ll b,ll c){return min(min(a,b),c);}
inline ll getmin(ll a,ll b,ll c,ll d){return min(a,min(b,min(c,d)));}
inline ll getmax(ll a,ll b){return max(a,b);}
inline ll getmax(ll a,ll b,ll c){return max(a,max(b,c));}
inline ll getmax(ll a,ll b,ll c,ll d){return max(a,max(b,max(c,d)));}
ll curr=0;
bool op(pair<string,ll> &a,pair<string,ll> &b){
    return a.xt[curr]<b.xt[curr];
}
bool op1(pair<string,ll> &a,pair<string,ll> &b){
   
    return b.xt[curr]<a.xt[curr];
}


void solve()
    {
        ni2(n,d);
        vector<pair<string,ll>>val(n);
        rep(i,0,n,1){cin>>val[i].xt;val[i].yt=i;}
        rep(i,0,n,1){
           curr=i;
           if(i%2==1){sort(all(val),op);}
          
        }
        rep(i,0,n,1){
            curr=i;
             if(i%2==0) {sort(all(val),op1);}
        }
        
        drep(i,n-1,0,1)cout<<val[i].yt+1<<" ";cout<<endl;
    }

int main(){
    fast();
    //ni1(t);w(t)
    solve();
    #ifndef ONLINE_JUDGE
        cerr<<"\nTime elapsed: "<<1000*clock()/CLOCKS_PER_SEC<<"ms\n";
    #endif
    khatam; 
}