// #pragma comment(linker, "/stack:200000000000")
#pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#include <bits/stdc++.h> 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
using i128 = __int128_t;
using u128 = __uint128_t;
using u64 = uint64_t;
 
//define
// #define int long long
#define ll int
#define trav(i,v)   for(auto i: v)
#define rep(i,n)    for(int i=0;i<n;i++)
#define repu(i,k,n) for(int i=k;i<=n;i++)
#define repd(i,k,n) for(int i=k;i>=n;i--)
#define se second
#define fi first
#define pb push_back
#define mp make_pair
#define all(v)  v.begin(), v.end()
#define itn int 
#define sz(x) (int)x.size()
// #define endl "\n"
	
//typedef
typedef unsigned long long ull;
typedef long double ld;
typedef std::pair<int, int> pii;
typedef std::vector<int> vi;
typedef std::vector< pii > vii;
typedef std::vector< std::vector<int> > vvi;
typedef std::vector< std::pair < pii, int > > vpp;
 
template<class T> 
using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
/* less<T> --> set , less_equal<T> --> multiset for increasing order */
/* greater<T> --> set , greater_equal<T> --> multiset for decreasing order */
#define fbo find_by_order 
#define ook order_of_key
/* find_by_order(x) - iterator to xth element (0 indexed) if exists else returns end() */
/* increasing order: order_of_key(x) - number of items strictly lesser than x */
/* decreasing order: order_of_key(x) - number of items strictly greater than x */
 
// const long long MOD = 1000000007;
const long long MOD = 998244353;
const long double PI = 3.141592653589793238;
const long long pi = 31415926;
// const long long inf = 2000000000000000000;
const int inf = 1000000000;
const long long small_inf = INT_MAX;
const int N = 300000;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int a, int b){ return a + rng() % (b - a + 1); }
int modpow(int x, int n = MOD-2, int mod = MOD){ int res=1; while(n>0){ if(n&1) res=res*x%mod; x=x*x%mod; n>>=1;} return res;}
int power(int x, int n){ int res=1; while(n>0){ if(n&1) res=res*x; x=x*x; n>>=1; } return res;}
int add(int x, int y){ return (x+y)%MOD; }
int mult(int x, int y){ return (x*y)%MOD; }
void mod(int &x){ x%=MOD; x+=MOD; x%=MOD; }


// vi fact(N+1,1), inv(N+1,1);
// int ncr(int x, int y){
// 	if(x<y || y<0 || x<0)
// 		return 0;
// 	return (((fact[x]*inv[y])%MOD)*inv[x-y])%MOD;
// }

void init(){
	// repu(i,2,N){
	// 	fact[i] = (fact[i-1]*i)%MOD;
	// }
	// repu(i,2,N){
	// 	inv[i] = (inv[i-1]*modpow(i,MOD-2))%MOD;
	// }
}

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void solve()
{
	int n, m;
	cin>>n>>m;
	string s, t;
	cin>>s>>t;
	n = s.length();
	m = t.length();
	if(m==1){
		int cnt1=0, cnt0=0;
		int x = t[0]-'0';
		rep(i,n){
			if(s[i]=='0')
				cnt0++;
			else
				cnt1++;
		}
		repu(i,0,n-m+1){
			if(x==1){
				cout<<abs(x-cnt1)<<" ";
			}
			else{
				cout<<abs(x-cnt0)<<" ";
			}
		}
		return;
	}
	vi pre = prefix_function(t);
	vvi pree(m+1,vi(2,0));
	rep(i,m-1){
		rep(j,2){
			if(t[i+1]==j+'0'){
				pree[i][j] = i+2;
				continue;
			}
			int x = pre[i];
			while(x && t[x]!=j+'0')
				x = pre[x-1];
			if(x || t[0]==j+'0')
				pree[i][j] = x+1;
		}
	}
	s = '+'+s;
	vvi dp(n-m+2,vi(m+1,inf));
	dp[0][0] = 0;
	repu(i,0,n-1){
		vvi dp1(n-m+2,vi(m+1,inf));
		repu(k,0,n-m+1){
			repu(j,0,m-1){
				if(dp[k][j]==inf)
					continue;
				if(s[i+1]==t[j]){
					if(j==m-1)
						dp1[k+1][pre[j]] = min(dp1[k+1][pre[j]], dp[k][j]);
					else
						dp1[k][j+1] = min(dp1[k][j+1], dp[k][j]);
					if(j!=0)
						dp1[k][pree[j-1][((s[i+1]-'0')^1)]] = min(dp1[k][pree[j-1][((s[i+1]-'0')^1)]], dp[k][j]+1);
					else if(t[0]!=s[i+1])
						dp1[k][1] = min(dp1[k][1], dp[k][j]+1);
					else{
						dp1[k][0] = min(dp1[k][0], dp[k][j]+1);
					}
				}
				else{
					if(j==m-1)
						dp1[k+1][pre[j]] = min(dp1[k+1][pre[j]], dp[k][j]+1);
					else
						dp1[k][j+1] = min(dp1[k][j+1], dp[k][j]+1);
					if(j!=0)
						dp1[k][pree[j-1][((s[i+1]-'0'))]] = min(dp1[k][pree[j-1][((s[i+1]-'0'))]], dp[k][j]);
					else if(t[0]!=s[i+1])
						dp1[k][1] = min(dp1[k][1], dp[k][j]);
					else
						dp1[k][0] = min(dp1[k][0], dp[k][j]);
				}
			}
		}
		dp = dp1;
	}
	repu(k,0,n-m+1){
		int ans = inf;
		repu(j,0,m-1){
			ans = min(ans, dp[k][j]);
		}
		cout<<(ans==inf?-1:ans)<<" ";
	}
	cout<<endl;
}

void clear_global(){
}
 
signed main(){
	// #ifndef ONLINE_JUDGE
	//    freopen("./input.txt", "r", stdin);
	//    freopen("./output.txt", "w", stdout);
	// #endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int t23 = 1, tt23 = 1; 
	// cin>>t23;
	init();
	while(tt23<=t23)
	{
		// cout<<"Case #"<<tt23<<": ";
		solve();
		tt23++;
		clear_global();
	}
	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}