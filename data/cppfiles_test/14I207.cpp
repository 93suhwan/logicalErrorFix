#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds; using namespace std;
// containers
typedef long long ll;typedef double db; typedef long double ld;
typedef pair<int,int> pii;typedef pair<ll,ll> pll;typedef pair<db,db> pdb;
typedef vector<int>vi;typedef vector<ll>vll;typedef vector<pii>vpi;typedef vector<pll>vpl; typedef vector<db>vdb;
typedef vector<vi>vvi;typedef vector<vll>vvl;typedef vector<vpi>vvpi;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
#define tcT template<class T
#define tcTU tcT, class U
tcT>using vec=vector<T>;
tcT>using pq=priority_queue<T>;
tcT>using uset=unordered_set<T>;
tcTU>using umap=unordered_map<T,U>;
tcT,size_t SZ>using ar=array<T,SZ>;
// macros
#define siz(x) (int)x.size()
#define af(x) x.begin(), x.end()
#define ms(x, y) memset(x, y, sizeof x)
#define fil(x, y) fill(af(x), y)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ft front()
#define bk back()
#define f first
#define s second	
// function
#define fvoid function<void
#define fint function<int
#define fll function<ll
// rng
mt19937 g1;
void seed1(){g1.seed(time_t(0));}
void seed2(){g1.seed(chrono::steady_clock::now().time_since_epoch().count());}
ll randint(ll a,ll b){return uniform_int_distribution<ll>(a,b)(g1);}
// io
#define watch(x) cerr << (#x) << ": " << (x) << endl;

tcT> void rem_dup(vector<T> &v){sort(af(v));v.resize(unique(af(v))-v.begin());}
tcT> bool ckmin(T &a,const T &b){return b<a?a=b,1:0;}
tcT> bool ckmax(T &a,const T &b){return b>a?a=b,1:0;}
int pcnt(ll x){return __builtin_popcountll(x);}
int lg2(ll x){return 63 - __builtin_clzll(x);}
#define MOD1 1e9+7;
#define MOD2 998244353;
const int mod=MOD1;
ll fpow(ll a,ll b,ll m=mod){ll ret=1;while(b){if(b&1)ret=ret*a%m;a=a*a%m,b>>=1;}return ret;}
ll inv(ll x){return x?fpow(x,mod-2):1;}
const int MM = 1e5 + 5;

void solve(){
    int n, k;
    cin >> n >> k;
    vi a(n + 1), need(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        need[i] = i -a[i];
    }
    vvi dp(n + 1, vi(n +1));
    int ans  = 1e9;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            ckmax(dp[i][j], dp[i - 1][j]);
        }
        if (need[i] < 0) continue;
        if (i > 1){
            for (int j = 0; j < need[i]; j++)
                ckmax(dp[i][need[i]], dp[i - 2][j] + 1);
        }
        ckmax(dp[i][need[i]], dp[i - 1][need[i]] + 1);
        for (int j = 0; j <= n; j++){
            if (dp[i][j] >= k) ckmin(ans, j);
        }
    }
    if (ans == 1e9) cout << -1 << '\n';
    else cout << ans << '\n';
}
/*
 * edge case[1?, 2?]
 * do i rlly need to check everything???
 * i rlly need to check for long long sometimes.
 * guessforces
 */	
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	seed2();
	int tests = 1;
	cin >> tests;
	for (int i = 1; i <= tests; i++){
		//cout << "Case #" << i << ": ";
		solve();
	}
}
