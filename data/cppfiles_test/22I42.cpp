// Problem: C. Train Maintenance
// Contest: Codeforces - Codeforces Round #745 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1580/C
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#include <iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<math.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> index_multiset;
//typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> index_set;
#define se second
#define fi first
#define in insert
#define ll long long
#define pb push_back
#define mp make_pair
#define mem(a) memset(a,0,sizeof(a))
#define vll vector<ll>
#define vpll vector<pair<ll,ll>> 
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define mpll map<ll,ll>
#define mpdd map<double,double>
#define len(s) s.length()
#define sz(x) (int)(x).size()
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
//const ll mod=1e9+7;
const ll mod=998244353;
ll pow1(ll x,ll y)
{ll res=1;x=x%mod;if(x==0) return 0;while(y>0){if(y&1)res=(res*x)%mod;y=y>>1;x=(x*x)%mod; }return res;}

/*ll f[400005],inverse[400005];
ll divide(ll n) 
{return pow1(n,mod-2); } 

ll ncr(ll n, ll r) 
{if(n<r) return 0;return (f[n]*((divide(f[r]) * divide(f[n-r])) % mod)) % mod; } */

/*bool prime[1000001];
void sieve() {memset(prime, true, sizeof(prime));
for (ll i = 2; i * i <= 1000000; i++)if (prime[i])for (ll j = i * i; j <= 1000000; j+= i)prime[j] = false;
prime[0] = prime[1] = false;}

vll factorize(long long n) 
{   ll count = 0; vll fac;
    while (!(n % 2)) {n >>= 1;count++;}if (count%2)fac.pb(2ll);
    for (long long i=3; i<=sqrt(n);i+=2){count=0;while(n%i==0){count++;n = n / i;}
	if (count%2) fac.pb(i);}if (n > 2) fac.pb(n); return fac;}*/

/*ll spf[1000001];

void fastsieve() {spf[1]=1;for(int i=2;i<=1000000;i++) spf[i]=i;for (int i=4;i<=1000000;i+=2) spf[i] = 2; 
for (int i=3; i*i<=1000000; i++)
{if(spf[i]==i) {for (int j=i*i; j<=1000000; j+=i)if (spf[j]==j) spf[j] = i;}}}

/*vpll fastfactorize(ll n)
{
    vpll v;
    ll prev=0,cnt=0;
    while(n!=1)
    {
        if(prev==spf[n]) cnt++;
        else
        {
            if(prev) v.pb({prev,cnt});
            cnt=1;
            prev=spf[n];
        }
        n/=spf[n];
    }
    if(n==1)
    {
        v.pb({prev,cnt});
        cnt=1;prev=spf[n];
    }
    return v;
}*/


/*const ll root = 62;

void ntt(vll& a, vll& rt, vll& rev, ll n) 
{
	for (ll i = 0; i < n; ++i)
	if (i < rev[i]) swap(a[i], a[rev[i]]);
	
	for (ll k = 1; k < n; k *= 2)
	{
		for (ll i = 0; i < n; i += 2 * k) for (ll j = 0; j < k; ++j)
		{
			ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
			a[i + j + k] = (z > ai ? ai - z + mod : ai - z);
			ai += (ai + z >= mod ? z - mod : z);
	    }
	}
}

vll conv(const vll& a, const vll& b) 
{
	if (a.empty() || b.empty()) return {};
	ll s = sz(a)+sz(b)-1, B = 32 - __builtin_clz(s), n = 1 << B;
	vll L(a), R(b), out(n), rt(n, 1), rev(n);
	L.resize(n), R.resize(n);
	
	for (int i = 0; i < n; ++i) rev[i] = (rev[i / 2] | (i & 1) << B) / 2;
	
	ll curL = mod / 2, inv = pow1(n, mod - 2);
	
	for (ll k = 2; k < n; k *= 2) 
	{
		ll z[] = {1, pow1(root, curL /= 2)};
		for (ll i = k; i < 2*k; ++i) rt[i] = rt[i / 2] * z[i & 1] % mod;
	}
	ntt(L, rt, rev, n);
	ntt(R, rt, rev, n);
	for (ll i = 0; i < n; ++i) out[-i & (n-1)] = L[i] * R[i] % mod * inv % mod;
	ntt(out, rt, rev, n);
	return {out.begin(), out.begin() + s};
}*/

ll M=500,dp[505][505],cnt[505],x[200005],y[200005],n,m,st[200005];

void update(ll idx,ll k,ll val)
{
	ll l=(idx+x[k])%(x[k]+y[k]),r=(idx-1)%(x[k]+y[k]);
	if(l<=r) while(l<=r) dp[x[k]+y[k]][l++]+=val;
	else 
	{
		for(ll i=0;i<=r;i++) dp[x[k]+y[k]][i]+=val;
		for(ll i=l;i<x[k]+y[k];i++) dp[x[k]+y[k]][i]+=val;
	}
}

ll query(ll idx)
{
	ll val=0;
	for(ll i=1;i<=M;i++) val+=dp[i][idx%i];
	return val;
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	ll i,j;
	for(i=1;i<=n;i++) cin>>x[i]>>y[i];
	for(i=1;i<=m;i++)
	{
		ll type,k;cin>>type>>k;
		if(type==1)
		{
			st[k]=i;
			if(x[k]+y[k]>M)
			{
				for(j=st[k]+x[k];j<=m;j+=x[k]+y[k]) 
				{
					cnt[j]++;
					if(j+y[k]<=m) cnt[j+y[k]]--;
				}
			}
			else update(i,k,1ll);
		}
		else 
		{
			if(x[k]+y[k]>M)
			{
				for(j=st[k]+x[k];j<=m;j+=x[k]+y[k])
				{
					cnt[j]--;
					if(j+y[k]<=m) cnt[j+y[k]]++;
				}
			}
			else update(st[k],k,-1ll);
		}
		cout<<cnt[i]+query(i)<<endl;
	}
	
	return 0;
}