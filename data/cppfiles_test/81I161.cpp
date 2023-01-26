#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define ll long long
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_pset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define endl '\n'
#define pll pair<ll,ll>
#define rep(i,n) for(ll i=0;i<n;i++)
#define mod 998244353
#define INF 10000000000000000
#define ff first
#define ss second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define pie 3.141592653589793238462643383279
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
#define SB(a) sort(a.begin(),a.end(),greater<ll>());
#define SS(a) sort(a.begin(),a.end());
#define vll vector<ll>
#define vpll vector<pll>
vector<bool> prime;
vector<ll> fact,inv,primes,factors,pf;
void fast()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
void factorize(ll a)
{
	factors.clear();
	for(ll i=1;i*i<=a;i++)
	{
		if (i*i==a) factors.pb(i);
		else if (a%i==0)
		{
			factors.pb(i);
			factors.pb(a/i);
		}
	}
	sort(factors.begin(),factors.end());
}
ll power(ll a,ll b)
{
	if(a==1||b==0)	return 1;
	ll c=power(a,b/2);
	ll res=1;
	res=c*c;
	if(res>=mod)	res%=mod;
	if(b%2)	res*=a;
	if(res>=mod)	res%=mod;
	return res;
}
ll modInv(int a)
{
	return power(a,mod-2);
}
void factorial(ll n)
{
	fact.resize(n+1);
	fact[0]=1;
	for(ll i=1;i<=n;i++)
	{
		fact[i]=fact[i-1]*i;
		if(fact[i]>=mod)	fact[i]%=mod;
	}
}
void InvFactorial(ll n)
{
	inv.resize(n+1);
	inv[0]=1;
	for(ll i=1;i<=n;i++)	inv[i]=modInv(fact[i]);
}
ll ncr(ll n,ll r)
{
	if(n<r||n<0||r<0)	return 0;
	ll b=inv[n-r];
	ll c=inv[r];
	ll a=fact[n]*b;
	if(a>=mod)	a%=mod;
	a*=c;
	if(a>=mod)	a%=mod;
	return a;
}
void remove_duplicates(vpll &v)
{
	sort(v.begin(),v.end());
	ll _size=unique(v.begin(),v.end())-v.begin();
	v.resize(_size);
}
unsigned ll gcd(unsigned ll u, unsigned ll v)
{
    if(u==0||v==0) return max(u,v);
    unsigned ll shift=__builtin_ctz(u|v);
	u>>=__builtin_ctz(u);
    do{
    	v>>=__builtin_ctz(v);
    	if(u>v)	swap(u,v);
    	v-=u;
    }while(v!=0);
    return u<<shift;
}
void sieve(ll n)
{
    prime.assign(n+1,1);
	prime[1]=false;
    for(ll p=2;p*p<=n;p++)
	{
		if(prime[p])
		{
			for(ll i=p*p;i<=n;i+=p)	prime[i]=false;
		}
	}	
    for(ll i=2;i<n+1;i++)
	{
		if(prime[i]) primes.push_back(i);
	} 
}
void prime_sieve(ll n)
{
	pf.assign(n+1,0);
	rep(i,n+1) pf[i]=i;
	for(ll i=2;i<=n;i++)
	{
		if (pf[i]==i)
		{
			for(ll j=i;j<=n;j+=i) pf[j]=i;
		}
	}
}
//-------------------------------------------------------------------------------------------------------------------------------------------------
// Always remember: if (condition) if (condition) statement; This doesn't work !!
// Always increase boundaries for global or frequency questions
// pow((ll)10,i) doesn't work sometimes. It is better to use multiple of 10 in arrays. Always remember this.
// delete values when defining global if there are multiple testcases
// don't try to be smart and make stupid mistakes
void solve()
{
	ll n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	map<ll,set<ll>> mp;
	rep(i,n) 
	{
		if (s[i]=='+') s[i]=1;
		else s[i]=-1;
		if (i%2)
		{
			if (s[i]==1) s[i]=-1;
			else s[i]=1;
		}
	}
	vll psum(n,0);
	rep(i,n) 
	{
		if (!i) psum[i]=s[i];
		else psum[i]=s[i]+psum[i-1];
	}
	rep(i,n-1)
	{
		mp[psum[i]+psum[i+1]].insert(i);
	}
	while(k--)
	{
		ll x,y;
		cin>>x>>y;
		x--;y--;
		if (x==y)
		{
			cout<<1<<endl;
			continue;
		}
		if (y-x==1)
		{
			if (s[y]!=s[x]) cout<<0<<endl;
			else cout<<2<<endl;
			continue;
		}
		ll p=psum[y];
		ll q=0;
		if (x) q=psum[x-1];
		if (p==q)
		{
			cout<<0<<endl;
			continue;
		}
		if ((y-x+1)%2==0)
		{
			cout<<2<<endl;
			continue;
		}
		ll r=p+q;
		auto i1=mp[r].lb(x);
		if (i1==mp[r].end() || *i1>=y) cout<<2<<endl;
		else cout<<1<<endl; 
	}
}
int main()
{
	fast();
	ll T=1;
	cin>>T;
	for(ll z=1;z<=T;z++) solve();
}
