//HEADER FILES AND NAMESPACES

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp>   
// #include <sys/resource.h>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; 

// PRAGMAS (do these even work?)
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

// DEFINE STATEMENTS
const long long infty = 1e18;
#define num1 1000000007
#define num2 998244353
#define REP(i,a,n) for(ll i=a;i<n;i++)
#define REPd(i,a,n) for(ll i=a; i>=n; i--)
#define pb push_back
#define pob pop_back
#define f first
#define s second
#define fix(f,n) std::fixed<<std::setprecision(n)<<f
#define all(x) x.begin(), x.end()
#define M_PI 3.14159265358979323846
#define epsilon (double)(0.000000001)
#define popcount __builtin_popcountll
#define fileio(x) freopen("input.txt", "r", stdin); freopen(x, "w", stdout);
#define out(x) cout << ((x) ? "Yes\n" : "No\n")
#define sz(x) x.size()
#define start_clock() auto start_time = std::chrono::high_resolution_clock::now();
#define measure() auto end_time = std::chrono::high_resolution_clock::now(); cerr << (end_time - start_time)/std::chrono::milliseconds(1) << "ms" << endl;


typedef long long ll;
typedef long double ld;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<int> vii;

// DEBUG FUNCTIONS 
#ifdef LOCALY

template<typename T>
void __p(T a) {
	cout<<a;
}
template<typename T, typename F>
void __p(pair<T, F> a) {
	cout<<"{";
	__p(a.first);
	cout<<",";
	__p(a.second);
	cout<<"}";
}
template<typename T>
void __p(std::vector<T> a) {
	cout<<"{";
	for(auto it=a.begin(); it<a.end(); it++)
		__p(*it),cout<<",}"[it+1==a.end()];
}
template<typename T>
void __p(std::set<T> a) {
	cout<<"{";
	for(auto it=a.begin(); it!=a.end();){
		__p(*it); 
		cout<<",}"[++it==a.end()];
	}

}
template<typename T>
void __p(std::multiset<T> a) {
	cout<<"{";
	for(auto it=a.begin(); it!=a.end();){
		__p(*it); 
		cout<<",}"[++it==a.end()];
	}
}
template<typename T, typename F>
void __p(std::map<T,F> a) {
	cout<<"{\n";
	for(auto it=a.begin(); it!=a.end();++it)
	{
		__p(it->first);
		cout << ": ";
		__p(it->second);
		cout<<"\n";
	}
	cout << "}\n";
}

template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) {
	__p(a1);
	__p(a...);
}
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
	cout<<name<<" : ";
	__p(arg1);
	cout<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
	int bracket=0,i=0;
	for(;; i++)
		if(names[i]==','&&bracket==0)
			break;
		else if(names[i]=='(')
			bracket++;
		else if(names[i]==')')
			bracket--;
	const char *comma=names+i;
	cout.write(names,comma-names)<<" : ";
	__p(arg1);
	cout<<" | ";
	__f(comma+1,args...);
}
#define trace(...) cout<<"Line:"<<__LINE__<<" ", __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...)
#define error(...)
#endif

// DEBUG FUNCTIONS END 

// CUSTOM HASH TO SPEED UP UNORDERED MAP AND TO AVOID FORCED CLASHES
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());  // FOR RANDOM NUMBER GENERATION

ll mod_exp(ll a, ll b, ll c)
{
	ll res=1;   a=a%c;
	while(b>0)
	{
		if(b%2==1)
			res=(res*a)%c;
		b/=2;
		a=(a*a)%c;
	}
	return res;
}
ll mymod(ll a,ll b)
{
	return (((a = a%b) < 0) ? a + b : a);
}
ll gcdExtended(ll,ll,ll *,ll *);
ll modInverse(ll a, ll m) 
{ 
		ll x, y; 
		ll g = gcdExtended(a, m, &x, &y); 
		g++;   //this line was added just to remove compiler warning
		ll res = (x%m + m) % m;
		return res;
} 
ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
		if (a == 0) 
		{ 
				*x = 0, *y = 1; 
				return b; 
		} 
		ll x1, y1; 
		ll gcd = gcdExtended(b%a, a, &x1, &y1);
		*x = y1 - (b/a) * x1; 
		*y = x1; 
		return gcd; 
}


set<pll> dists;
struct Graph
{
	vector<vector<int>> adj;
	vector<int> dist;
	vector<bool> done;
	vector<int> pars;
	Graph(int n)
	{
		adj.resize(n+1);
		dist.resize(n+1);
		done.resize(n+1);
		pars.resize(n+1);
	}	
	void add_edge(int a, int b, bool directed = false)
	{
		adj[a].pb(b);
		if(!directed) adj[b].pb(a);
	}
	void dfs(int x, int par = -1)
	{
		pars[x] = par;
		for(auto &p: adj[x])
		{
			if(p != par)
			{
				dist[p] = dist[x] + 1;
				dists.insert({dist[p], p});
				dfs(p, x);
			}
		}
	}
	void dfs2(int x)
	{
		for(auto &p: adj[x])
		{
			if(p != pars[x])
			{
				dists.erase({dist[p], p});
				dist[p] = dist[x] + 1;
				dists.insert({dist[p], p});
				dfs2(p);
			}
		}
	}

};


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, k;
	cin >> n >> k;
	Graph G(n);
	REP(i, 1, n)
	{
		ll a, b;
		cin >> a >> b;
		G.add_edge(a, b);
	}

	G.dist[1] = 1;
	dists.insert({1, 1});
	G.dfs(1);
	ll cnt = 0;
	ll curr = 0;
	REP(i, 0, k)
	{
		if(cnt == n) break;
		pll p = *dists.rbegin();
		ll x = p.second;
		vll v;
		while(x != -1 && !G.done[x])
		{
			if(x != p.second) v.pb(x);
			++cnt;
			dists.erase({G.dist[x], x});
			G.dist[x] = 0;
			G.done[x] = true;
			x = G.pars[x];
		}

		for(auto &p: v)
		{
			if(p != 1)
			{
				G.dfs2(p);
			}
		}

		curr = i+1;
	}

	// trace(cnt);
	ll r = curr;
	if(r < k) r = min(k, n/2);
	ll b = min(n - cnt, n/2);
	ll w = n - r - b;

	cout << w*(r-b) << "\n";
	return 0;
}

/*
1. Check borderline constraints. Can a variable you are dividing by be 0?
2. Use ll while using bitshifts
3. Do not erase from set while iterating it
4. Initialise everything
5. Read the task carefully, is something unique, sorted, adjacent, guaranteed??
6. DO NOT use if(!mp[x]) if you want to iterate the map later
7. Are you using i in all loops? Are the i's conflicting?
*/ 



