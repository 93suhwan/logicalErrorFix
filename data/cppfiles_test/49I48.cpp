#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
typedef long long ll;
typedef long double ld;
#define INF LLONG_MAX
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define g(a,b) get<a>(b)
#define REP(i,a,b) for(ll i = a; i<=b; i++)
#define REPI(i, a, n)  for(ll i = a; i >= (n); --i)
#define ordered_set tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update> 
#define endl "\n"
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ordered_set member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set*/

// DISJOINT SET UNION START
ll fn(ll x,ll rn[]) // finding the component
{
    if(x==rn[x]) // Top of its component
        return x;
    else //making parent node of each node of the component the highest node
        return rn[x]=fn(rn[x],rn);
}
bool un(ll x,ll y,ll rn[],ll sz[])// union of components
{
    x=fn(x,rn);
    y=fn(y,rn);
    if(x==y)// if connected already
        return false;
    if(sz[x]<sz[y])// otherwise connectiing light to heavy by swapping
        swap(x,y);
    sz[x]+=sz[y];
    rn[y]=x;// making parent node;
    return true;
}
//DISJOINT SET UNION END
ll gcd(ll a, ll b){if(!b)return a;return gcd(b, a % b);}
ll lcm(ll a , ll b){return (a*b)/gcd(a,b);}
ll MOD=998244353;
ll mod=1000000007;
ll power(ll x,ll y, ll p){ll res=1;x%=p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;}
ll inv(ll val, ll MODx = MOD) 
{
    return power(val, MODx - 2, MODx);
}
vector <ll> fac, ifac;
void preFac(ll sz) 
{
    fac.resize(sz + 1),
    ifac.resize(sz + 1);
    fac[0] = 1;
    for(int i = 1; i <= sz; i++) 
    {
        fac[i] = (i * fac[i - 1]) % MOD;
    }
    ifac[sz] = inv(fac[sz]);
    for(int i=sz-1;i>=0;i--) 
    {
        ifac[i]=((i+1)*ifac[i+1])%MOD;
    }
}
ll nCr(ll N, ll R)
{
    if(R <= N  and  R >= 0) {
        return ((fac[N] * ifac[R]) % MOD * ifac[N - R]) % MOD;
    }
    return 0;
}
static vector<ll> v[1000005];
static vector<ll> val(1000005);
static vector<ll> cnt(1000005,0);
static vector<vector<ll>> queries[1000005];
static vector<ll> ans(1000005);
static ordered_set store;
void dfs(ll pres,ll prev)
{
    if(store.find({cnt[val[pres]],val[pres]})!=store.end())
    {
        store.erase(store.find({cnt[val[pres]],val[pres]}));
    }

    cnt[val[pres]]++;
    store.insert({cnt[val[pres]],val[pres]});

    for(auto u:queries[pres])
    {
        pair<ll,ll> pp;
        auto it=store.lower_bound({u[0],INF});
        if(it==store.end())
        {
            ans[u[2]]=-1;
        }
        else
        {
            pp=*it;
            ll remove_elements=(ll)store.order_of_key(pp);
            ll real_order=u[1]+remove_elements;
            if(real_order>store.size())
            {
                ans[u[2]]=-1;
            }
            else
            {
                pair<ll,ll> qq=*store.find_by_order(real_order-1);
                ans[u[2]]=qq.S;
            }
        }
    }
    for(auto u:v[pres])
    {
        if(u!=prev)
        {
            dfs(u,pres);
        }
    }
    store.erase(store.find({cnt[val[pres]],val[pres]}));
    cnt[val[pres]]--;
    if(cnt[val[pres]]>0)
    {
        store.insert({cnt[val[pres]],val[pres]});
    }
}
int main() 
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    ll t;
    cin>>t;
    while(t--)
    {
        store.clear();
        ll n,q;
        cin>>n>>q;
        REP(i,1,n)
        {
            ans[i]=0;
            v[i].clear();
            queries[i].clear();
            cnt[i]=0;
            cin>>val[i];
        }
        REP(i,2,n)
        {
            ll x;
            cin>>x;
            v[i].PB(x);
            v[x].PB(i);
        }
        REP(i,1,q)
        {
            ll v,l,k;
            cin>>v>>l>>k;
            queries[v].PB({l,k,i});
        }
        dfs(1,-1);
        REP(i,1,q)
        {
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
}
//try thinking from a different angle after spending some time
//PLEASE CHECK EDGE CASES!!!