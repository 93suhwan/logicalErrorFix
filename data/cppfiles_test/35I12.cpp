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

class Sieve
{
	ll MAXN;

	void sieve(ll n)        
	{
		forn(i,2,MAXN+1)
			spf[i]=i;
		for(ll i=2;i*i<=n;i++)
		{
			if(spf[i]==i)
			{
				for(ll j=i*i;j<=n;j+=i)
				{
					if(spf[j]==j)
						spf[j]=i;
				}
			}
		}
		forn(i,2,MAXN+1)
		{
			if(spf[i]==i)
				prime.push_back(i);
		}
	}

	public:
	vector<ll> spf;
	vector<ll> prime;

	void init(ll n)
	{
		MAXN=n;
		spf=vector<ll>(MAXN+5);
		sieve(MAXN);
	}
};

int main()
{
	fastio();
	ll z,n,m,t,k,i,j,l,d,h,r;
	Sieve si;
	si.init(1'000'007);
	cin>>n;
	vector<ll> a(n);
	string s;
	for(ll &i:a)
		cin>>i;
	cin>>s;
	vector<vector<pair<ll,ll>>> ind(1'000'007);
	vector<vector<ll>> v(1'000'007);
	vector<ll> mnext(n,n-1);
	forn(i,0,n)
	{
		d=a[i];
		if(s[i]=='/' and a[i]>1)
		{
			mnext[i]=i-1;
			while(d!=1)
			{
				r=si.spf[d];
				d/=r;
				if(!ind[r].empty())
				{
					auto &[pos,cnt]=ind[r].back();
					cnt--;
					if(!cnt)
					{
						if(d%r==0)
							mnext[pos]=min(mnext[pos],i-1);
						ind[r].pop_back();
					}
				}
			}
		}
		else
		{
			while(d!=1)
			{
				r=si.spf[d];
				ll cnt=0;
				while(d%r==0)
				{
					d/=r;
					cnt++;
				}
				ind[r].push_back({i,cnt});
			}
		}
	}
	forb(i,n-2,0)
		mnext[i]=min(mnext[i],mnext[i+1]);
	ll ans=0;
	forn(i,0,n)
		ans+=(mnext[i]-i+1);
	cout<<ans<<"\n";
	cerr<<"\nTime elapsed: "<<1000*clock()/CLOCKS_PER_SEC<<"ms\n";
	return 0;
}
