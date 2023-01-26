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
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		vector<vector<ll>> a(n,vector<ll>(m));
		forn(i,0,n)
			forn(j,0,m)
				cin>>a[i][j];
		vector<vector<ll>> minl(n,vector<ll>(m));
		vector<vector<ll>> minr(n,vector<ll>(m));
		vector<vector<ll>> maxl(n,vector<ll>(m));
		vector<vector<ll>> maxr(n,vector<ll>(m));
		forn(i,0,n)
		{
			minl[i][0]=a[i][0];
			maxl[i][0]=a[i][0];
			forn(j,1,m)
			{
				minl[i][j]=min(minl[i][j-1],a[i][j]);
				maxl[i][j]=max(maxl[i][j-1],a[i][j]);
			}
			minr[i][m-1]=a[i][m-1];
			maxr[i][m-1]=a[i][m-1];
			forb(j,m-2,0)
			{
				minr[i][j]=min(minr[i][j+1],a[i][j]);
				maxr[i][j]=max(maxr[i][j+1],a[i][j]);
			}
		}
		string ans(n,'R');
		ll cut=-1;
		forn(j,0,m-1)
		{
			using tp=tuple<ll,ll,ll>;
			vector<tp> lft(n),rht(n);
			forn(i,0,n)
			{
				lft[i]={minl[i][j],maxl[i][j],i};
				rht[i]={minr[i][j+1],maxr[i][j+1],i};
			}
			sort(all(lft));
			sort(all(rht),greater<tp>());
			for(auto [p1,p2,p3]:rht)
				dbg(p1,p2,p3);
			vector<ll> min_lft(n+1,inf);
			vector<ll> max_rht(n+1);
			forb(i,n-1,0)
			{
				auto [mil,mal,il]=lft[i];
				min_lft[i]=min(min_lft[i+1],mil);
				auto [mir,mar,ir]=rht[i];
				max_rht[i]=max(max_rht[i+1],mar);
			}
			dbg(min_lft);
			dbg(max_rht);
			set<ll> reql,reqr,ind;
			forn(i,0,n-1)
			{
				auto [mil,mal,il]=lft[i];
				auto [mir,mar,ir]=rht[i];
				if(reql.count(il))
					reql.erase(il);
				else
					reqr.insert(il);
				if(reqr.count(ir))
					reqr.erase(ir);
				else
					reql.insert(ir);
				ind.insert(il);
				ind.insert(ir);
				dbg(reql);
				dbg(reqr);
				dbg(ind);
				dbg(mil, min_lft[i+1], mar, max_rht[i+1]);
				if(reql.empty() and mal<min_lft[i+1] and mir>max_rht[i+1])
				{
					for(ll i:ind)
						ans[i]='B';
					cut=j;
					break;
				}
				l++;
				r--;
			}
			dbg("---");
			if(cut!=-1)
				break;
		}
		dbg("here");
		if(cut==-1)
			cout<<"NO\n";
		else
		{
			cout<<"YES\n";
			cout<<ans<<" "<<cut+1<<"\n";
		}
	}
	cerr<<"\nTime elapsed: "<<1000*clock()/CLOCKS_PER_SEC<<"ms\n";
	return 0;
}
