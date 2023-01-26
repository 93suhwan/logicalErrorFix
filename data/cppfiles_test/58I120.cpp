// Problem: A. Computer Game
// Contest: Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1598/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long int ll;
#define mod 1000000007 //998244353
#include<string.h>
#define inf 1000000000000000000
#define maxn 200002
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
#define endl '\n'
#define mapint_iterator map<int,int> :: iterator
#define mapll_iterator map<ll,ll> :: iterator
#define setint_iterator set<int> :: iterator
#define setll_iterator set<ll> :: iterator
#define setpint_iterator set<pint> :: iterator
#define setpll_iterator set<pll> :: iterator
#define trace(x) cout<<#x<<": "<<x<<" "<<endl
#define trace2(x,y) cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x,y,z) cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a,b,c,d) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define cout1(a) cout<<a<<endl
#define cout2(a,b) cout<<a<<" "<<b<<endl
#define cout3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define cout4(a,b,c,d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl
#define vcout(v,i) cout<<v[i].fi<<" "<<v[i].se<<endl
#define set_bits(n) __builtin_popcountll(n)
typedef priority_queue<ll,vector<ll>,greater<ll> > pqset;
typedef priority_queue<pint,vector<pint>,greater<pint> > pqset_ll;
#define pb push_back
#define fi first
#define vi vector<ll>
#define vv vector<vector<ll> > 
#define vb vector<bool> 
#define vp vector<pll>
#define se second
#define mp make_pair
#define acc (ios::sync_with_stdio(false),cin.tie(0))
#define rep(i,n) for(ll i=0;i<n;i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define per1(i,n) for(ll i=n;i>0;i--)
#define repeat(i,start,n) for(ll i=start;i<n;i++)
#define print(a,n) for(ll i=0;i<n;i++){ cout<<a[i]<<" ";}
#define all(v) v.begin(),v.end()
ll ll_max(ll a,ll b,ll c){return max(a,max(b,c));}
int int_max(int a,int b,int c){return max(a,max(b,c));}
ll ll_min(ll a,ll b,ll c){return min(a,min(b,c));}
int int_min(int a,int b,int c){return min(a,min(b,c));}
ll max(int a,ll b){ return max((ll)a,b);}
ll min(int a,ll b){ return min((ll)a,b);}
ll min(ll a,int b){ return min(a,(ll)b);}
ll max(ll a,int b){ return max(a,(ll)b);}
ll dx[]={0,0,1,-1};
ll dy[]={1,-1,0,0};
#define see(args...)                       \
{                                            \
    cerr<<"LINE "<<__LINE__;                 \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    err(_it, args);                          \
    cerr<<endl;                              \
}
void err(istream_iterator<string> it){}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
  cerr<<' '<< *it << " = " << a ;
  err(++it, args...);
} 
template <typename T, typename U>inline void min_self(T &x, U y){if (y < x)x = y;}
template <typename T, typename U>inline void max_self(T &x, U y){if (x < y)x = y;}
template<class T1, class T2>ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}
template<class T> ostream& operator<<(ostream& out, vector<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
template<class T> ostream& operator<<(ostream& out, set<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
template<class L, class R> ostream& operator<<(ostream& out, map<L, R> vec) { out<<"("; for (auto& v: vec) out<<"["<<v.first<<", "<<v.second<<"]"; return out<<")"; }
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
 
void solve()
{
	ll n;
	cin>>n;
	vector<string> v(2);
	cin>>v;
	bool poss=true;
	ll prev=0;
	rep(i,n)
	{
		if(v[0][i]=='1' && v[1][i]=='1')
		{
			prev++;
		}
		else prev=0;
		if(prev>=2) poss=false;
	}
	if(poss) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return;
}
int main()
{
	acc;
    ll t;
	cin>>t;
	while(t--)
	{
    	solve();
    }
}
 