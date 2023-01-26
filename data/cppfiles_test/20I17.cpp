//done by varunmaddipati / 123thuderbuddie / maverick_729 / DarkLucifer321
//template credits : kal013 (https://codeforces.com/contest/1569/submission/128296960)
//comment optimisations for interactive problems (use endl)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;
using namespace std;

template<class T> 
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
 
template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
 
template<class T>
using min_heap = priority_queue<T,vector<T>,greater<T> >; 

/*/--------------------------------IO(Debugging)-----------------------------/*/
template<class T> istream& operator >> (istream &is, vector<T>& V) {
    for(auto &e : V)                                                          
        is >> e;
    return is;
}
template<class T, size_t N> istream& operator >> (istream &is, array<T, N>& V) {
    for(auto &e : V)
        is >> e;
    return is;
}
#ifdef __SIZEOF_INT128__
ostream& operator << (ostream &os, __int128 const& value){
    static char buffer[64];
    int index = 0;
    __uint128_t T = (value < 0) ? (-(value + 1)) + __uint128_t(1) : value;
    if (value < 0) 
        os << '-';
    else if (T == 0)
        return os << '0';
    for(; T > 0; ++index){
        buffer[index] = static_cast<char>('0' + (T % 10));
        T /= 10;
    }    
    while(index > 0)
        os << buffer[--index];
    return os;
}
istream& operator >> (istream& is, __int128& T){
    static char buffer[64];
    is >> buffer;
    size_t len = strlen(buffer), index = 0;
    T = 0; int mul = 1;
    if (buffer[index] == '-')
        ++index, mul *= -1;
    for(; index < len; ++index)
        T = T * 10 + static_cast<int>(buffer[index] - '0');
    T *= mul;    
    return is;
}
#endif
template<typename CharT, typename Traits, typename T>
ostream& _containerprint(std::basic_ostream<CharT, Traits> &out, T const &val) {
    return (out << val << " ");
}
template<typename CharT, typename Traits, typename T1, typename T2>
ostream& _containerprint(std::basic_ostream<CharT, Traits> &out, pair<T1, T2> const &val) {
    return (out << "(" << val.first << "," << val.second << ") ");
}
template<typename CharT, typename Traits, template<typename, typename...> class TT, typename... Args>
ostream& operator << (std::basic_ostream<CharT, Traits> &out, TT<Args...> const &cont) {
    out << "[ ";
    for(auto&& elem : cont) _containerprint(out, elem);
    return (out << "]");
}
template<class L, class R> ostream& operator << (ostream& out, pair<L, R> const &val){
    return (out << "(" << val.first << "," << val.second << ") ");
}
template<typename L, size_t N> ostream& operator << (ostream& out, array<L, N> const &cont){
    out << "[ ";
    for(auto&& elem : cont) _containerprint(out, elem);
    return (out << "]");    
}
template<class T> ostream& operator<<(ostream &out, ordered_set<T> const& S){
    out << "{ ";
    for(const auto& s:S) out << s << " ";
    return (out << "}");
}
template<class L, class R, class chash = std::hash<L> > ostream& operator << (ostream &out, gp_hash_table<L, R, chash> const& M) {
    out << "{ ";
    for(const auto& m: M) out << "(" << m.first << ":" << m.second << ") ";
    return (out << "}");
}
template<class P, class Q = vector<P>, class R = less<P> > ostream& operator << (ostream& out, priority_queue<P, Q, R> const& M){
    static priority_queue<P, Q, R> U;
    U = M;
    out << "{ ";
    while(!U.empty())
        out << U.top() << " ", U.pop();
    return (out << "}");
}
template<class P> ostream& operator << (ostream& out, queue<P> const& M){
    static queue<P> U;
    U = M;
    out << "{ ";
    while(!U.empty())
        out << U.front() << " ", U.pop();
    return (out << "}");
}
#define TRACE
#ifdef TRACE
    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " : " << arg1<<" | ";
        __f(comma+1, args...);
    }
#else
    #define trace(...) 1
#endif

/*/------------------------------------RNG-----------------------------------/*/
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int64_t random_long(long long l = LLONG_MIN,long long r = LLONG_MAX){
    uniform_int_distribution<int64_t> generator(l,r);
    return generator(rng);
}
struct custom_hash { // Credits: https://codeforces.com/blog/entry/62393
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    template<typename L, typename R>
    size_t operator()(pair<L,R> const& Y) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31ull + Y.second + FIXED_RANDOM);
    }
};

/*/------------------------------------Defines-------------------------------/*/
#define ll long long
#define ull unsigned long long
#define ld long double
// #define int long long
#define all(x) x.begin(), x.end()
#define getline_clear int waste; scanf("%d\n", &waste)
#define merge_arrays(a,b,c) merge(all(a),all(b),back_inserter(c))
#define sz(x) ((int)(x).size())
#define uid(a, b) uniform_int_distribution<int>(a, b)
#define pb push_back
#define F first
#define S second

/*/---------------------Global Constants and Functions-----------------------/*/
const ll mod = 1e9 + 7, nax = 1e5 + 5;
vector<int> primes, lf(nax);
bool ok = true;

ll mpow(ll base, ll exp, ll MOD);
vector<int> randon_perm(int n);
void sieve(void);

/*/-----------------------------Code begins----------------------------------/*/
void pre_process(){
	return;
}

void test_case() {
	ll n,m; cin>>n>>m;
	vector<string> s(n); cin>>s;
	if(!ok) {
		cout<<n<<" "<<m<<endl;
		return;
	}
	ll zeros[n][m+1], ones[n][m+1];
	memset(zeros, 0, sizeof(zeros));
	memset(ones, 0, sizeof(ones));
	//trace(s);
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			zeros[i][j+1] = zeros[i][j] + (s[i][j]=='0');
			ones[i][j+1] = ones[i][j] + (s[i][j]=='1');    
		}
	}
	//cin>>s;
	ll ans = INT_MAX;
	for(int j=0; j<m-3; j++) {
		for(int k=j+3; k<m; k++) {
			//trace(j,k);
			vector<ll> fir(n,0);
			for(int i=0; i<n; i++) {
				fir[i] = zeros[i][k] - zeros[i][j+1]; 
			}
			//trace(fir);
			vector<ll> req(n, 0);
			for(int i=1; i<n; i++) {
				req[i] = (s[i-1][j]!='1') + (s[i-1][k]!='1') 
							+ ones[i-1][k] - ones[i-1][j+1] + req[i-1];
			}
			//trace(req);
			ll nin = INT_MAX;
			for(int i=n-5; i>=0; i--) {
				nin = min(nin, fir[i+4] + req[i+4]);
				ll temp_ans = fir[i] + nin - req[i+1];
				ans = min(ans, temp_ans);
			}
		}
	}
	cout<<ans<<"\n";
	ok=false;
}

signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);

//#ifndef ONLINE_JUDGE
	//freopen("../inp", "r", stdin);
	//freopen("../outp", "w", stdout);
	//freopen("../err", "w", stderr);
//#endif
	
	pre_process();

	int T = 1; cin >> T;
	for (int t = 1; t <= T; t++) {
		//cout << "Case #" << t << ": ";
		test_case();
	}
}

ll mpow(ll base, ll exp, ll MOD) {
	base %= MOD;
	ll result = 1;
	while (exp > 0) {
		if (exp & 1) result = (result * base) % MOD;
		base = (base * base) % MOD;
		exp >>= 1;
	}
	return result;
}

vector<int> randon_perm(int n) {
	vector<int> v(n); iota(all(v), 1);
	for (int i = n - 1; i >= 0; i--) {
		int ind = rng() % (i + 1);
		swap(v[ind], v[i]);
	}
	return v;
}

void sieve(void) {
	iota(all(lf), 0);
	for (ll i = 2; i < nax; i++) {
		if (lf[i] == i) primes.pb(i);
		for (ll j = 0; j < (ll)primes.size() && i * primes[j] < nax; j++) {
			lf[i * primes[j]] = primes[j];
			if (i % primes[j] == 0) break;
		}
	}
}
