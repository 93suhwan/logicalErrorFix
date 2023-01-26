#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

#define ff              first
#define ss              second
#define ll              int64_t
#define ld              long double
#define nl              cout<<"\n"
#define all(v)          v.begin(),v.end()
#define mset(a,v)       memset((a),(v),sizeof(a))
#define forn(i,a,b)     for(int64_t i=int64_t(a);i<int64_t(b);++i)
#define forb(i,a,b)     for(int64_t i=int64_t(a);i>=int64_t(b);--i)
#define fastio()        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define mod         1'000'000'007
#define mod2        998'244'353 
#define inf         1'000'000'000'000'007
#define pi          3.14159265358979323846

template<class key,class cmp=std::less<key>>
using ordered_set=tree<key,null_type,cmp,rb_tree_tag,tree_order_statistics_node_update>;

template<class L,class R> ostream& operator<<(ostream& out,pair<L,R> &p)        {return out<<"("<<p.ff<<", "<<p.ss<<")";}
template<class T> ostream& operator<<(ostream& out,vector<T> &v)                {out<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())out<<", ";out<<*it;}return out<<"]";}
template<class T> ostream& operator<<(ostream& out,deque<T> &v)                 {out<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())out<<", ";out<<*it;}return out<<"]";}
template<class T> ostream& operator<<(ostream& out,set<T> &s)                   {out<<"{";for(auto it=s.begin();it!=s.end();++it){if(it!=s.begin())out<<", ";out<<*it;}return out<<"}";}
template<class L,class R> ostream& operator<<(ostream& out,map<L,R> &m)         {out<<"{";for(auto it=m.begin();it!=m.end();++it){if(it!=m.begin())out<<", ";out<<*it;}return out<<"}";}

void dbg_out() {cerr<<"]\n";}
template<typename Head,typename... Tail> 
void dbg_out(Head H,Tail... T) {cerr<<H;if(sizeof...(Tail))cerr<<", ";dbg_out(T...);}
#ifdef LOCAL
	#define dbg(...) cerr<<"["<<#__VA_ARGS__<<"] = [",dbg_out(__VA_ARGS__)
#else
	#define dbg(...)
#endif

//---------------------------------mars4---------------------------------

int main()
{
	fastio();
	ll z,n,m,t,k,i,j,l,d,h,r;
	cin>>n;
	vector<string> a(n);
	for(auto &i:a)
		cin>>i;
	vector<vector<ll>> cnt(1ll<<n,vector<ll>(26,inf));
	vector<ll> ind(1ll<<n);
	vector<ll> val(1ll<<n);
	vector<ll> ex(1ll<<n,1);
	forn(i,1,1ll<<n)
	{
		forn(j,0,n)
		{
			if(i&(1ll<<j))
			{
				ind[i]+=j+1;
				vector<ll> cnt2(26);
				for(char ch:a[j])
				{
					cnt2[ch-'a']++;
				}
				forn(k,0,26)
				{
					cnt[i][k]=min(cnt[i][k],cnt2[k]);
				}
			}
		}
		forn(k,0,26)
		{
			ex[i]=ex[i]*(cnt[i][k]+1)%mod2;
		}
		if(__builtin_popcountll(i)&1)
		{
			val[i]=(val[i]+ex[i])%mod2;
		}
		else
		{
			val[i]=(val[i]-ex[i]+mod2)%mod2;
		}
	}
	forn(j,0,n)
	{
		forn(i,0,1ll<<n)
		{
			if(i&(1ll<<j))
			{
				val[i]=(val[i]+val[i^(1ll<<j)])%mod2;
			}
		}
	}
	ll ans=0;
	forn(i,0,1ll<<n)
	{
		ans^=val[i]*ind[i]*__builtin_popcountll(i)%mod2;
	}
	cout<<ans<<"\n";
	cerr<<"\nTime elapsed: "<<1000*clock()/CLOCKS_PER_SEC<<"ms\n";
	return 0;
}
