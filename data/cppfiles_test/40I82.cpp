/* Creation Date - 17-10-2021 */ 
/* Creation Time - 18:28:01.10 */  

/*
Written By : mafailure
In the name of God 
O Allah, May you grant peace and honor on Muhammad and his family.
Allahumm-a-Sall-iAla Muhammad-in Wa Al-i Muhammad
*/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less
using namespace std;
using namespace __gnu_pbds;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define endl "\n"
/*------------------------int to long long -----------------*/
#ifdef ill
#define int long long 
#endif
/*---------------------------DEBUG HELPER--------------------------------------*/
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef AATIF_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

//#define int long long 
// int dx[]={-1,1,0,0}; int dy[]={0,0,1,-1};
// int dx[]={2,2,-2,-2,1,1,-1,-1}; int dy[]={1,-1,1,-1,2,-2,2,-2};
long long mod = 1e9 + 7;
const double eps=1e-9;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector< pair< int, int > > vii;
typedef map<int, int> mii;
typedef pair<int, ii> pip;
typedef pair<ii, int> ppi;
#define arrinp(arr,init,final,size,type) type* arr=new type[size];for(int i=init;i<final;i++)cin>>arr[i];
#define cr2d(arr,n,m,t) t**arr=new t*[n];for(int i=0;i<n;i++)arr[i]=new t[m];
#define w(t) int t;cin>>t; while(t--)
#define takeInp(n) int n;cin>>n;
#define fr(i,init,final) for(int i=init;i<final;i++)
#define frr(i,init,final) for(int i=init;i>=final;i--)
#define Fr(i,final) for(int i=0;i<final;i++)
#define Frr(i,first) for(int i=first;i>=0;i--)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define debug(x) cerr<<">value ("<<#x<<") : "<<x<<endl;
#define setb __builtin_popcount
#define lsone(n) (n&(-n))
#define rlsone(n) (n&(n-1))
#define clr(a,b) memset(a,b,sizeof(a))
const int inf= INT_MAX;
/*-----------------------------RANDOM NUMBER GENERATOR ---------------------*/
#ifdef RNG 
unsigned seed=chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 rng(seed);
#endif 
/*------------------------------UNORDERED MAP HASH --------------------------------------------*/
//To make unordered_map unhackable 
// use it as unordered_map<int,int,custom_hash> mapp;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        /* http://xorshift.di.unimi.it/splitmix64.c */
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
/*---------------------------ORDERED SET--------------------------------------*/
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>  ordered_set; 
/*----------------------------------------------------------------------------*/
vi init(string s)
{
	istringstream sin(s);
	int n;
	vi arr;
	while(sin>>n)arr.push_back(n);
	return arr;
}
int power(int x, int y)
{ 
	if(y==0)return 1;
	int u=power(x,y/2);
	u=(u*u)%mod;
	if(y%2)u=(x*u)%mod;
	return u;
    
}
int gcd(int a,int b)
{
	if(a<b)return gcd(b,a);
	return (b==0?a:(a%b?gcd(b,a%b):b));
}
int gcd_e(int a,int b,int &x,int &y)
{
	
	if(b==0){x=1; y=0; return a;}
	int x1,y1;
	int p=gcd_e(b,a%b,x1,y1);
	x=y1;
	y=x1-(a/b)*y1;
	return p;
}
/*-----------------to solve int to long long problem-----------------*/
int Min (int a,int b){return min(a,b);}
int Max(int a,int b){ return max(a,b);}

//786 121 786 121 786 121 786 121 786 121 786 121 786 121 786 121 786 121
/*========================CODE*****CODE****CODE======================*/
int n,m;        
const int N=3e5+5; 
vector<pair<int,int>> g[N]; 
vector<int> PAR(N);
vector<int> parn(N,-1); 
vector<int> depth(N);  
void dfs(int u,int p){
  PAR[u]=p;
  for(auto [v,x]:g[u])
  {
  	if(v==p)continue; 
  	depth[v]=depth[u]+1;
  	parn[v]=x;  
  	dfs(v,u); 
  }
 
}

int getparent(vi & par,int u){return par[u]==u?u:par[u]=getparent(par,par[u]) ;}


signed main()
{
	IOS
	cin>>n>>m; 
	vi par(n); 
	iota(all(par),0); 
	vector<int> edges(m); 
	for(int i=0;i<m;i++)
	{
		int u,v; 
		cin>>u>>v; 
		u--; v--; 
		int p1=getparent(par,u); 
		int p2=getparent(par,v); 
		if(p1==p2)continue; 
		g[u].push_back(mp(v,i)); 
		g[v].push_back(mp(u,i)); 
		par[p1]=p2; 
	}
	dfs(0,-1); 
	int q; 
	cin>>q;
	vector<ii> query;
  vvi path; 
	fr(i,0,q)
	{
		int u,v; 
		cin>>u>>v; 
		u--; 
		v--; 
		query.pb(mp(u,v)); 
		int a=u; 
		int b=v; 
		deque<int> dqa,dqb; 
		while(a!=b)
		{
			if(depth[a]>depth[b])
			{
				edges[parn[a]]^=1; 
				dqa.push_back(a); 
				a=PAR[a]; 
			}
			else 
			{
				edges[parn[b]]^=1; 
				dqb.push_front(b); 
				b=PAR[b]; 
			}
		}
		dqa.push_back(a);
		path.push_back({});
		for(auto it:dqa)path.back().push_back(it);
		for(auto it:dqb)path.back().push_back(it);		
	}
	int cnt=accumulate(all(edges),0); 
	if(cnt==0)
	{
		cout<<"YES\n"; 
		for(auto & ita:path)
		{
			for(auto& itb:ita)cout<<itb+1<<" "; cout<<endl; 
		}
	}else cout<<"NO\n"<<(cnt+1)/2<<endl; 
	
	
	
	
	 
	
	
}

