#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#pragma GCC optimize ("-O3")
#define int long long
#define ld long double
#define endl "\n"

#define rep(i,begin,end) for (__typeof(end) i=begin-(begin>end); i!=(end)-(begin>end); i+=1-2*(begin>end))
#define umap unordered_map
#define pq priority_queue 
#define pb push_back
#define mp make_pair
#define fs first
#define sec second
#define lb lower_bound
#define ub upper_bound
#define mii map<int,int>
#define pii pair<int,int>
#define vc vector
#define vi vc<int>
#define vvi vc<vi>
#define all(v) v.begin(),v.end()
#define tol(s) transform(s.begin(),s.end(),s.begin(),::tolower);
#define tou(s) transform(s.begin(),s.end(),s.begin(),::toupper);
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define w(t) int t; cin>>t; rep(tc,0,t)
#define clr(a,x) memset(a,x,sizeof a)
#define chkbit(x,i) ((x)&(1LL<<(i)))
#define setbit(x,i) ((x)|(1LL<<(i)))
#define setbits(x)  __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define ps(x,y) fixed<<setprecision(y)<<x
#define print(a, n) rep(i,0,n) cout<<a[i]<<" "; cout<<endl;
#define printclock cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const int mod = 1e9+7;
const int mod2 = 998244353;
const long long inf = 1e18;
const long double PI = 3.141592653589793;

template<typename... T>
void in(T&... args) {((cin>>args), ...);}

template<typename... T>
void out(T&&... args) {((cout<<args<<" "), ...);}

template<typename... T>
void outln(T&&... args) {((cout<<args<<" "), ...); cout<<endl;}

int nxt(){int x;cin>>x;return x;}

int add(int a,int b,int mod=mod){int res=(a+b)%mod;return (res<0)?res+mod:res;}

int mul(int a,int b,int mod=mod){int res=(a*1LL*b)%mod;return (res<0)?res+mod:res;}

struct customCompare {
    bool operator () (int x, int y) {
        return x>y;
    }
};

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

const int N = 2e5;
int codejam = 0, testcases = 1;

int ModExp(int x, int y, int m){
    int res = 1;
    while (y > 0) {
        if (y & 1) res = (res*x) % m;
        y = y>>1;
        x = (x*x) % m;
    }
    return res;
}

void solve() {
    int n = nxt();
    int k = nxt();
    int ans = 0;

    if (n % 2 == 0) {
        ans = 1;
        for (int i = k-1; i >= 0; i--) {
            int x = ModExp(2, i, mod);
            x = ModExp(x, n, mod);
            ans = add(ans, x);
        }
    }
    else {
        int x = (ModExp(2, n-1, mod) + 1) % mod;
        ans = ModExp(x, k, mod);
    }

    cout << ans << endl;
}

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

int32_t main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    assert(freopen("input.txt", "r", stdin));
    // assert(freopen("output.txt", "w", stdout));
    #endif

    int t = 1; 
    if (testcases) 
        cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        if (codejam)
            cout << "Case #" << tc << ": ";
        solve();
    }

    // printclock;
    return 0;
}