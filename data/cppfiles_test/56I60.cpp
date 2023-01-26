#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define req(i,a,b) for(int i=(a);i>=(b);--i)
#define rep_(i,a,b) for(int i=(a);i<(b).size();++i)
#define F(a) rep(a,1,n)
#define M(a,b) memset(a,b,sizeof a)
#define DC int T;cin>>T;while(T--)
#define ll long long
#define Z(a,b) sort(a+1,a+b+1)
using namespace std;
const int _mod=998244353;
const int mod=1e9+7;
const ll infi=0x3f3f3f3f3f3f3f3fll;
const int inf=0x3f3f3f3f;
template <typename T> void rd(T &x){x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch==45)f=-1;ch=getchar();}while(isdigit(ch))x=x*10+ch-48,ch=getchar();x*=f;}
ll ksm(ll x,ll y=mod-2,ll m=mod){ll ret=1;while(y){if(y&1)ret=ret*x%m;y>>=1;x=x*x%m;}return ret;}
ll qpow(ll x,ll y=2){ll ret=1;while(y){if(y&1)ret=ret*x;y>>=1;x=x*x;}return ret;}
/*
	[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
	[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
	[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
*/
ll n,k,ans;
unordered_map<ll,ll> mp,f[7],v[7];
unordered_map<char,ll> wzak;
int work(ll x){req(i,60,0) if (x>>i&1) return i;}
ll work3(ll k){if (!k) return 1;return ksm(4,(ksm(2,k,mod-1)+mod-3)%(mod-1));}
inline bool chk(ll x,ll y){return x!=y&&x+y!=7;}
ll work2(ll x,ll y)
{
	if (v[y][x]) return f[y][x];
	ll ret=0,q=mp[x];
	if (!q) return work3(k-work(x));
	if (q==7&&k-work(x)==1) return 1;
	if (q!=7)
	{
		if (q!=y) return 0;
		if (k-work(x)==1) return 1;
	}
	rep(_,1,6) if (chk(_,y)) rep(__,1,6) if (chk(__,y)) (ret+=work2(x*2,_)*work2(x*2+1,__))%=mod;
	v[y][x]=1;
	return f[y][x]=ret;
}
void Insert(ll x,ll c)
{
	if (!x) return;
	ll q=mp[x];
	if (q!=7&&q&&q!=c&&c!=7) puts("0"),exit(0);
	if (!q||q==7) q=c;
	Insert(x/2,7);
}
int main()
{
	wzak['w']=1,wzak['r']=2,wzak['g']=3,wzak['b']=4,wzak['o']=5,wzak['y']=6;
	cin>>k;
	DC
	{
		ll x;
		rd(x);
		char s[15];
		cin>>s+1;
		Insert(x,wzak[s[1]]);
	}
	rep(i,1,6) (ans+=work2(1,i))%=mod;
	cout<<ans<<'\n';
	return 0;
}