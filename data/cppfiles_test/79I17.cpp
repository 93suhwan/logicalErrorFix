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
	vector<ll> a(n),b(n);
	for(ll &i:a)
		cin>>i;
	for(ll &i:b)
		cin>>i;
	vector<pair<ll,ll>> v(n,{-2,-2});
	forn(i,0,n)
		v[i+b[i]]=max(v[i+b[i]],{i,i+b[i]});
	auto v2=v;
	v.pop_back();
	sort(all(v));
	queue<ll> q;
	vector<ll> path(n,-1);
	path[n-1]=n-1;
	q.push(n-1);
	bool chk=false;
	vector<ll> ans={-1};
	while(!q.empty())
	{
		ll cur=q.front();
		q.pop();
		ll jmp=cur-a[cur];
		if(jmp==-1)
		{
			ll frm=cur;
			do
			{
				ll slip_frm=v2[frm].ff;
				ans.push_back(slip_frm);
				frm=path[slip_frm];
			}
			while(frm!=n-1);
			reverse(all(ans));
			chk=true;
			break;
		}
		while(!v.empty())
		{
			auto [req,ind]=v.back();
			if(jmp<=req)
			{
				path[req]=cur;
				q.push(ind);
				v.pop_back();
			}
			else
				break;
		}
	}
	if(!chk)
		cout<<"-1\n";
	else
	{
		cout<<(ll)ans.size()<<"\n";
		for(ll i:ans)
			cout<<i+1<<" ";
		nl;
	}
	cerr<<"\nTime elapsed: "<<1000*clock()/CLOCKS_PER_SEC<<"ms\n";
	return 0;
}
