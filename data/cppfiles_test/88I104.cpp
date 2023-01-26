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
#define ordered_set     tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> 

#define mod         1'000'000'007
#define mod2        998'244'353 
#define inf         1'000'000'000'000'007
#define pi          3.14159265358979323846

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
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		vector<ll> a(n);
		for(ll &i:a)
			cin>>i;
		n+=2;
		a.push_back(-inf);
		a.push_back(inf);
		sort(all(a));
		vector<pair<ll,ll>> b(m),v;
		for(auto &p:b)
			cin>>p.ff>>p.ss;
		sort(all(b),[&](pair<ll,ll> u,pair<ll,ll> v){
			return u.ss-u.ff<v.ss-v.ff;
		});
		map<ll,ll> mp={{inf,inf}};
		forn(i,0,m)
		{
			auto [st,ed]=b[i];
			ll right_pt=*lower_bound(all(a),st);
			if(right_pt<=ed)
				continue;
			auto right_seg=*mp.lower_bound(st);
			if(right_seg.ss<=ed)
				continue;
			mp[st]=ed;
			v.push_back({st,ed});
		}
		sort(all(v),[&](pair<ll,ll> u,pair<ll,ll> v){
			if(u.ss==v.ss)
				return u.ff<v.ff;
			return u.ss<v.ss;
		});
		dbg(v);
		m=(ll)v.size();
		if(!m)
		{
			cout<<"0\n";
			continue;
		}
		// only right, only left, left and right
		vector<vector<ll>> dp(m+1,vector<ll>(3,inf));
		dp[0][0]=0;
		ll curl=prev(lower_bound(all(a),v[0].ss))-a.begin();
		ll curr=lower_bound(all(a),v[0].ss)-a.begin();
		forn(i,0,m)
		{
			ll ncurl=prev(lower_bound(all(a),v[i].ss))-a.begin();
			ll ncurr=lower_bound(all(a),v[i].ss)-a.begin();
			if(ncurl==curl and ncurr==curr)
			{
				if(i)
				{
					dp[i+1][0]=min(dp[i+1][0],dp[i][0]+max((ll)0,(v[i].ff-max(v[i-1].ff,a[curl]))));
					v[i].ff=max(v[i-1].ff,v[i].ff);
				}
				else
					dp[i+1][0]=dp[i][0]+max((ll)0,(v[i].ff-a[curl]));

				dp[i+1][1]=min(dp[i][0]+(a[curr]-v[i].ss),dp[i][1]);

				if(i)
					dp[i+1][2]=min(dp[i][0]+(a[curr]-v[i].ss),dp[i][2]+(v[i].ss-v[i-1].ss));
				else
					dp[i+1][2]=dp[i][0]+(a[curr]-v[i].ss);
			}
			else
			{
				if(curr!=ncurl)
					dp[i+1][0]=min({dp[i][0],dp[i][1],dp[i][2]})+max((ll)0,(v[i].ff-a[ncurl]));

				curr=ncurr;
				curl=ncurl;

				dp[i+1][0]=min(dp[i+1][0],dp[i][0]+max((ll)0,(v[i].ff-a[curl])));
				/* for(j=i;j<m and b[j].ss<a[curr];j++) */
				/* 	dp[j+1][0]=min(dp[j+1][0],dp[i][2]+max((ll)0,v[j].ff-v[i-1].ss)); */
				if(dp[i+1][0]>dp[i][2]+max((ll)0,v[i].ff-v[i-1].ss))
				{
					dp[i+1][0]=dp[i][2]+max((ll)0,v[i].ff-v[i-1].ss);
					/* v[i].ff=max(v[i].ff,v[i-1].ss); */
				}

				dp[i+1][1]=min({dp[i][0]+(a[curr]-v[i].ss),dp[i][1]+(a[curr]-v[i].ss),dp[i][2]+(a[curr]-v[i].ss)});

				dp[i+1][2]=min({dp[i][0]+(a[curr]-v[i].ss),dp[i][1]+(a[curr]-v[i].ss),dp[i][2]+(a[curr]-v[i].ss)});
			}
			dbg(i+1, dp[i+1]);
		}
		ll ans=min({dp[m][0],dp[m][1],dp[m][2]});
		cout<<ans<<"\n";
	}
	cerr<<"\nTime elapsed: "<<1000*clock()/CLOCKS_PER_SEC<<"ms\n";
	return 0;
}
