/*---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

// #define kyoa_a
#define rep(i, a, b)	for(int i = a; i < (b); ++i)
#define rrep(a, b, c)	for(int a = (b); a > c; --a)
#define each(a, b)	for(auto& a : b)

#define sz(x)       (int)(x).size()
#define all(a)      (a).begin(),(a).end()
#define rall(a)     (a).rbegin(), (a).rend()

#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define vt vector
#define ar array
#define pii pair<int, int>
#define vi vector<int>
#define pll pair<ll, ll>
#define pct(x) __builtin_popcount(x)
#define fbo(x) find_by_order(x)
#define ook(x) order_of_key(x)
#define rsz resize
#define bk back()

constexpr int log2(int x) { return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x))
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T> bool umin(T& a, const T& b){return b<a?a=b, 1:0;}
template <class T> bool umax(T& a, const T& b){return a<b?a=b, 1:0;}

using ll = long long;
using ld = long double;
using str = string;

const int inf = (int)1e9 + 5;
const ll infl = (ll)1e18 + 5;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;

const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef LOCAL
#define dbg(x...) cerr <<" [" << #x << "] = ["; _print(x);
#else
#define dbg(x...)
#endif

/*---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---*/

ll myrand(){
	ll a = rng();
	ll b = rng();
	return a*(RAND_MAX) + b;
}



void solve(){
	srand(time(NULL));
	vi a(6), b(9);
	each(x, a) x = myrand()%100;
	each(x, b) x = myrand()%100;

	sort(all(a)); sort(all(b));
	dbg(a);
	dbg(b);
	

}


int main(){
	#ifdef kyoa_a
		auto begin = std::chrono::high_resolution_clock::now();
	#endif

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		solve();

	#ifdef kyoa_a
		auto end = std::chrono::high_resolution_clock::now();
		cout << setprecision(3) << fixed;
		cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}