// Problem: E. Frequency Queries
// Contest: Codeforces - Codeforces Round #759 (Div. 2, based on Technocup 2022 Elimination Round 3)
// URL: https://codeforces.com/contest/1591/problem/E
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// Author: abhidot

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
// #define int long long
#define ll long long
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define mod 1000000007
#define mod2 998244353
#define lld long double
#define pii pair<int, int>
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define rep(i,x,y) for(int i=x; i<y; i++)
#define fill(a,b) memset(a, b, sizeof(a))
#define vi vector<int>
#define V vector
#define setbits(x) __builtin_popcountll(x)
#define w(x)  int x; cin>>x; while(x--)
using namespace std;
using namespace __gnu_pbds; 
template <typename num_t> using ordered_set = tree<num_t, null_type, less<num_t>, rb_tree_tag, tree_order_statistics_node_update>;
const long long N=200005, INF=2000000000000000000, inf = 2e9+5;

int power(int a, int b, int p){
	if(a==0)
	return 0;
	int res=1;
	a%=p;
	while(b>0)
	{
		if(b&1)
		res=(res*a)%p;
		b>>=1;
		a=(a*a)%p;
	}
	return res;
}


void print(bool n){
    if(n){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}

int n, qq;
vector<int> a, ans;
vector<vector<int>> g;
vector<vector<pair<int,pii>>> q;

map<int,int> mp;
ordered_set<pii> os;

int get(int lim){
	if((*os.begin()).ff>=lim) return 0;
	int l=0, r = os.size();
	while(r>l+1){
		int m = l + (r-l)/2;
		if((*os.find_by_order(m)).ff<lim) l=m;
		else r=m;
	}
	
	return r;
}

int query(pii p){
	auto it = get(p.ff);
	if(it==os.size()) return -1;
	
	if(it+p.ss>os.size()) return -1;
	
	return (*os.find_by_order(it+p.ss-1)).ss;
}

int dfs(int u){
	if(mp[a[u]]>0) os.erase({mp[a[u]], a[u]});
	mp[a[u]]++;
	os.insert({mp[a[u]], a[u]});
	
	// Handle queries of this node
	for(auto st:q[u]){
		int id = st.ff;
		pii qu = st.ss;
		ans[id] = query(qu);
	}
	
	for(auto v:g[u]) dfs(v);
	
	os.erase({mp[a[u]], a[u]});
	mp[a[u]]--;
	if(mp[a[u]]>0) os.insert({mp[a[u]], a[u]});
}


int32_t main()
{
    IOS;
    w(T){
    	cin>>n>>qq;
    	a.clear();
    	a.resize(n+1);
    	for(int i=1;i<=n;i++) cin>>a[i];
    	
    	
    	g.clear();
    	g.resize(n+1);
    	for(int i=2;i<=n;i++){
    		int p;
    		cin>>p;
    		g[p].pb(i);
    	}
    	
    	q.clear();
    	q.resize(n+1);
    	
    	ans.clear();
    	ans.resize(qq+1);
    	
    	for(int i=1;i<=qq;i++){
    		int v, l, k;
    		cin>>v>>l>>k;
    		q[v].pb({i, {l,k}});
    	}
    	
    	mp.clear();
    	while(!os.empty()) os.erase(os.begin());
    	
    	dfs(1);
    	
    	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    	cout<<"\n";
    }
}