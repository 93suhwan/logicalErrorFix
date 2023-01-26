#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
#define lli long long int
#define double long double
#define all(x) x.begin(),x.end()
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define siz(x) x.size()
#define prs(x,y) x.find(y)!=x.end()
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define forn(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
typedef long long ll;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res;}
inline int level(int n){int ans=0;while(n%2==0){n/=2;ans++;}return ans;}
#define gog(T,x) cout<<"Case #"<<T<<": "<<x<<"\n";
#define pii pair<lli,lli>
vector<lli> gr[100005];
lli tin[100005],tout[100005];
lli p[21][100005];
lli T=0;
lli dfs(lli node, lli pr)
{
	//cout<<node<<" "<<pr<<"\n";
	p[0][node]=pr;
	tin[node]=T++;
	for(auto x: gr[node])
	{
		if(x==pr)
			continue;
		dfs(x, node);
	}
	tout[node]=T;
	return 0;
}
bool is_ancestor(lli a,lli b)
{
	if(tin[a]<tin[b] && tout[a]>=tout[b])
		return true;
	return false;
}
lli lca(lli a,lli b)
{
	if(is_ancestor(a,b))
		return a;
	if(is_ancestor(b,a))
		return b;
	for(lli i=20;i>=0;i--)
	{
		if(!is_ancestor(p[i][a],b))
			a=p[i][a];
	}
	return p[0][a];
}
lli precalc(lli n)
{
	for(lli i=1;i<=20;i++)
	{
		for(lli j=1;j<=n;j++)
		{
			p[i][j]=p[i-1][p[i-1][j]];
		}
	}
	return 0;
}
//
class SegTree
{
public:
lli n;   //array size
vector<lli> t;
SegTree(lli w)
{
	n=w;
	t=vector<lli>(2*n);
}
void modify(lli l, lli r, lli value) {
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) t[l++] += value;
    if (r&1) t[--r] += value;
  }
}

lli query(lli p) {
  lli res = 0;
  for (p += n; p > 0; p >>= 1) res += t[p];
  return res;
}
};
lli a[100005];
lli solve()
{
	lli n,q;
	cin>>n>>q;
	forn(i, n)
		cin>>a[i+1];
	forn(i,n-1)
	{
		lli x,y;
		cin>>x>>y;
		gr[x].push_back(y);
		gr[y].push_back(x);
 
	}
	dfs(1,1);
	precalc(n);
	SegTree st(T+3);
	for(lli i=1;i<=n;i++)
	{
		st.modify(tin[i], tout[i], abs(2*a[i]));
	}
	forn(i, q)
	{
		lli op;
		cin>>op;
		if(op==1)
		{
			lli u,c;
			cin>>u>>c;

		st.modify(tin[u], tout[u], -abs(2*a[u]));
		a[u]=c;
		st.modify(tin[u], tout[u], abs(2*a[u]));
		}
		else if(op==2)
		{
			lli u,v;
			cin>>u>>v;
			if(u==v)
			{
				cout<<0;
			}
			else if(is_ancestor(u, v))
			{
				cout<<st.query(tin[v])-st.query(tin[u])-abs(a[v])+abs(a[u]);
			}
			else if(is_ancestor(v, u))
			{
				swap(u, v);
				cout<<st.query(tin[v])-st.query(tin[u])-abs(a[v])+abs(a[u]);
			}
			else
			{
				lli xd = lca(u, v);
				cout<<st.query(tin[u])+st.query(tin[v])-2*st.query(xd)-abs(a[v])-abs(a[u])+2*abs(a[xd]);
			}
			cout<<"\n";
		}
	}
	return 0;
}
int main()
{
	fast_io //REMOVE FOR interactive problems
	{
		solve();
	}
 
}
