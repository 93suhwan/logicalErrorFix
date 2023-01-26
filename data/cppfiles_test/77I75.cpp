#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define tf(x) get<0>(x)
#define ts(x) get<1>(x)
#define tt(x) get<2>(x)
#define endl '\n'
#define F first
#define S second 
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define tup tuple<int,int,int>
#define ve vector <int>
#define vep vector<pii >
#define maxn 200005
#define ld long double
#define mem(x) memset(x,0,sizeof(x))
#define in insert
#define fr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) for(int i=0;i<n;i++)
#define fora(m) for(auto it:m)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL); 
#define input_array int n;cin>>n;int a[n];forn(i,n) cin>>a[i];
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 


inline int add(int a,int b,int mod) {
	int res = a+b;
	if(res>= mod) res-=mod;
	return res;
}

inline int mull(int a,int b,int mod) {
	long long res = a%mod*b%mod;
	res%=mod;
	return (int)res;
}

inline int sub(int a,int b,int mod) {
	int res = a - b;
	if(res < 0) res+=mod;
	return res;
}

int power(int x, int y, int p) 
{ 
    int res = 1;     
    x = x % p;  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; 
        x = (x*x) % p; 
    } 
    return res; 
} 
int modInverse(int n, int p) 
{ 
    return power(n, p-2, p); 
}

struct cmp {
	bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
		int lena = a.second - a.first + 1;
		int lenb = b.second - b.first + 1;
		if (lena == lenb) return a.first < b.first;
		return lena > lenb;
	}
};

//--------------------------------SIEVE---------------------------//
/*bool prime[maxn]; 
int spf[maxn];
void sieve() {
	forn(i,maxn) {
		prime[i]=true;
		spf[i]=i;
	}
	fr(i,2,maxn) {
		if(prime[i]){
			for(int j=2*i;j<maxn;j+=i) {
				prime[j]=false;
				spf[j]=i;
			}
		}
	}
}*/

//-----------------------------End---------------------------------//


//------------------------------------------------DFS------------------------//
/*bool stat[maxn];
int depth[maxn],par[maxn];
void init_graph() {
	memset(stat,false,sizeof(stat);
	memset(depth,0,sizeof(depth);
	for(int i=0;i<maxn;i++) par[i]=i;
}
void dfs(int u,int p) {
	stat[u]=true;
	depth[u]=depth[p]+1;
	par[u]=p;
	for(auto it:g[u]) {
		if(stat[it]==false)
			dfs(it,u);
	}
}*/

//-------------------------------------DFS-END--------------------------------//

//-----------------------------------nCr%p-----------------------------------//
/* 

int fac[maxn+1]; 
void pre() {

    fac[0] = 1; 
    for (int i=1 ; i<=maxn; i++) 
        fac[i] = (fac[i-1]*i)%mod; 
} 

*/

/*int nCr(int n, int r) 
{ 
   if (r==0) 
      return 1; 
  
    return (fac[n]* modInverse(fac[r], mod) % mod * 
            modInverse(fac[n-r], mod) % mod) % mod; 
} */
//---------------------------------EnD---------------------------------------//

const int N = 4000000+1;
int dp[N], pref[N],pref1[N];

void solve() {
    int n,m;
    cin>>n>>m;
    dp[1] = 1;
    pref[0] = 0;
    for(int i=1;i<=n;i++) {
        pref1[i] = add(pref1[i],pref1[i-1],m);
        dp[i] = add(dp[i],pref[i-1],m);
        dp[i] = add(dp[i],pref1[i],m);
        // cout<<pref1[i]<<endl;
        for(int j=2*i;j<=n;j+=i) {
            int val = add(0 ,mull(j/i - 1,sub(dp[i],dp[i-1],m),m),m);
            // if(i==1)cout<<mull(j/i - 1,sub(dp[i],dp[i-1],m),m)<<endl;
            pref1[j] = add(val,pref1[j],m);
            if(j+i <= n) pref1[j+i] = sub(pref1[j+i],val,m);
        }
        pref[i] = add(pref[i],add(pref[i-1],dp[i],m),m);
        // pref1[i] = add(pref1[i],pref1[i-1],m);
        // cout<<pref[i]<<endl;
    }
    cout<<dp[n];
}
signed main() {
	IOS
	int t=1;
	// cin>>t;
	while(t--) {
		solve();
	}
	return 0;
}