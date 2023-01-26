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

template<class L,class R> ostream& operator<<(ostream& out,pair<L,R> &p)        {return out<<"("<<p.ff<<", "<<p.ss<<")";} template<class T> ostream& operator<<(ostream& out,vector<T> &v)                {out<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())out<<", ";out<<*it;}return out<<"]";}
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

class LCA
{
	ll N;
	ll logN;

	void dfs(const vector<vector<ll>> &v,ll cur,ll prev)
	{
		dp[cur][0]=prev;
		forn(i,1,logN)
			dp[cur][i]=dp[dp[cur][i-1]][i-1];
		for(ll i:v[cur])
			if(i^prev)
			{
				level[i]=level[cur]+1;
				dfs(v,i,cur);
			}
	}

	public:
	vector<vector<ll>> dp;
	vector<ll> level;

	LCA(const vector<vector<ll>> &v,ll root=0)
	{
		N=(ll)v.size();
		logN=65-__builtin_clzll(N);
		dp=vector<vector<ll>>(N,vector<ll>(logN));
		level=vector<ll>(N);
		dfs(v,root,root);
	}

	ll lca(ll u,ll v)
	{
		if(level[u]<level[v])
			swap(u,v);
		ll diff=level[u]-level[v];
		forb(i,logN-1,0)
			if(diff&(1ll<<i))
				u=dp[u][i];
		if(u==v)
			return u;
		forb(i,logN-1,0)
			if(dp[u][i]^dp[v][i])
			{
				u=dp[u][i];
				v=dp[v][i];
			}
		return dp[u][0];
	}

	ll kth_ancestor(ll u,ll k)
	{
		forb(i,logN-1,0)
			if(k&(1ll<<i))
				u=dp[u][i];
		return u;
	}

	ll dist(ll u,ll v)
	{
		return level[u]+level[v]-2*level[lca(u,v)];
	}
};

class SegtreeSum
{
	ll N;
	vector<ll> segtree;
	vector<ll> lazy;

	ll _build(vector<ll> &a,ll st,ll ed,ll i=1)
	{
		if(st==ed)
			return segtree[i]=a[st];
		ll mid=(st+ed)>>1;
		return segtree[i]=_build(a,st,mid,i<<1)+_build(a,mid+1,ed,i<<1|1);
	}

	void _push(ll st,ll ed,ll val,ll i)
	{
		if(st^ed)
		{
			lazy[i<<1]+=val;
			lazy[i<<1|1]+=val;
		}
	}

	void _update(ll st,ll ed,ll l,ll h,ll val,ll i=1)
	{
		if(lazy[i])
		{
			segtree[i]+=lazy[i]*(ed-st+1);
			_push(st,ed,lazy[i],i);
			lazy[i]=0;
		}
		if(st>ed or st>h or ed<l)
			return;
		if(st>=l and ed<=h)
		{
			segtree[i]+=val*(ed-st+1);
			_push(st,ed,val,i);
			return;
		}
		ll mid=(st+ed)>>1;
		_update(st,mid,l,h,val,i<<1);
		_update(mid+1,ed,l,h,val,i<<1|1);
		segtree[i]=segtree[i<<1]+segtree[i<<1|1];
	}

	ll _query(ll st,ll ed,ll l,ll r,ll i=1)
	{
		if(lazy[i])
		{
			segtree[i]+=lazy[i]*(ed-st+1);
			_push(st,ed,lazy[i],i);
			lazy[i]=0;
		}
		if(st>ed or st>r or ed<l)
			return 0;
		if(st>=l and ed<=r)
			return segtree[i];
		ll mid=(st+ed)>>1;
		return _query(st,mid,l,r,i<<1)+_query(mid+1,ed,l,r,i<<1|1);
	}

	// for prefix sum
	ll _first_element_atleast_x(ll st,ll ed,ll l,ll r,ll val,ll i=1)
	{
		if(lazy[i])
		{
			segtree[i]+=lazy[i]*(ed-st+1);
			_push(st,ed,lazy[i],i);
			lazy[i]=0;
		}
		if(st>ed or st>r or ed<l or segtree[i]<val)
			return -1;
		if(st==ed)
			return st;
		ll mid=(st+ed)>>1;
		ll ind=_first_element_atleast_x(st,mid,l,r,val,i<<1);
		if(ind==-1)
			ind=_first_element_atleast_x(mid+1,ed,l,r,val-segtree[i<<1],i<<1|1);
		return ind;
	}

	public:
	SegtreeSum(ll n,ll val=0)
	{
		N=n;
		segtree=vector<ll>(N<<2,val);
		lazy=vector<ll>(N<<2);
	}

	void build(vector<ll> &a)
	{
		_build(a,0,N-1);
	}

	void update(ll l,ll r,ll val)
	{
		_update(0,N-1,l,r,val);
	}

	ll query(ll l,ll r)
	{
		return _query(0,N-1,l,r);
	}

	ll first_element_atleast_x(ll l,ll r,ll val)
	{
		return _first_element_atleast_x(0,N-1,l,r,val);
	}

	void clear()
	{
		segtree=vector<ll>(N<<2);
		lazy=vector<ll>(N<<2);
	}
};

vector<vector<ll>> v;
vector<ll> a;
vector<ll> st;
vector<ll> ed;
ll timer=0;

void dfs(ll cur,ll prev,SegtreeSum &s)
{
	st[cur]=timer++;
	for(ll i:v[cur])
		if(i!=prev)
			dfs(i,cur,s);
	ed[cur]=timer;
	s.update(st[cur],ed[cur],a[cur]);
}

ll get_dist(ll u,SegtreeSum &s)
{
	return 2*s.query(st[u],st[u])-a[0]-a[u];
}

int main()
{
	fastio();
	ll z,n,m,t,k,i,j,l,d,h,r;
	cin>>n>>m;
	a=vector<ll>(n);
	st=ed=vector<ll>(n);
	v=vector<vector<ll>>(n);
	for(ll &i:a)
	{
		cin>>i;
		i=abs(i);
	}
	forn(i,0,n-1)
	{
		cin>>l>>r;
		l--,r--;
		v[l].push_back(r);
		v[r].push_back(l);
	}
	LCA lca(v);
	SegtreeSum s(n<<1);
	dfs(0,-1,s);
	forn(i,0,m)
	{
		cin>>d>>l>>r;
		if(d==1)
		{
			l--;
			r=abs(r);
			ll val=r-a[l];
			s.update(st[l],ed[l],val);
			a[l]=r;
		}
		else
		{
			l--,r--;
			ll node=lca.lca(l,r);
			ll ans=get_dist(l,s)+get_dist(r,s)-2*get_dist(node,s);
			cout<<ans<<"\n";
		}
	}
	cerr<<"\nTime elapsed: "<<1000*clock()/CLOCKS_PER_SEC<<"ms\n";
	return 0;
}
