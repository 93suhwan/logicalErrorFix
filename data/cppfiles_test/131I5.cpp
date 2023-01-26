
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;

#define int int64_t
using nat = uint64_t;
using db = double;
using ldb = long double;

#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define repr(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define repi(i,a,b) for (int i = (a); i <= (b); i++)
#define each(x,y) for (auto& x : (y))

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define tcT template<class T>
#define tcF template<class F>

tcT int sz(const T& c){ return c.size(); }

void subcases(); bool CONTINUE = true;
void solve();
void precompute();

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(17);
    subcases();
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 

#define Pb push_back
#define Eb emplace_back

#define Tuple make_tuple
#define Pair make_pair

int INF = numeric_limits<int>::max() / 4, ZERO = 0, ONE = 1;
string nl = "\n";


#ifdef LOCAL
namespace Debug {

bool _DEBUG = true;

template<int N> struct priority_tag : priority_tag<N-1> {};
template<> struct priority_tag<0> {};

struct printer {
    ostream&os;printer(ostream&os):os(os){}
    tcT printer&operator,(const T&t){p(t);os<<' ';return*this;}
    tcT void p(const T&t){p(t,priority_tag<3>());}
    template<class T,class=decltype(os<<declval<T>())>
    void p(const T&t,priority_tag<3>){os<<t;}
    tcT void p(const T&t,priority_tag<0>){
        os<<"[#"<<typeid(T).name()<<"#]";}
    template<class T,class C=typename T::value_type>
    void p(const T&t,priority_tag<2>){
        os<<'{';string sep;
        for(const C&e:t)os<<sep,p(e),sep=", ";
        os<<'}';}
    template<class T,class=decltype(get<0>(declval<T>()))>
    void p(const T&t,priority_tag<1>){
        print_tuple(t,make_index_sequence<tuple_size_v<T>>());}

    template<class Tuple, size_t...I>
    void print_tuple(const Tuple& t, index_sequence<I...>) {
        os<<'{';string sep;
        (...,(os << sep,p(get<I>(t)),sep=", "));
        os<<'}';
    }
};

#define dbg(...) \
    do if (Debug::_DEBUG) { \
        std::cerr << __LINE__ << ": " \
             << "[" << #__VA_ARGS__ \
             << "] = ["; \
        Debug::printer(std::cerr),__VA_ARGS__; \
        std::cerr << "]" << std::endl; \
    } while (0)
#define iflocal if (1)
}
#else
#define dbg(...)
#define iflocal if (0)
#endif


template<class T, class Op = multiplies<T>>
T Pow(T base, nat exp, T one = 1, Op op = Op()) {
    for (; exp; exp >>= 1) {
        if (exp&1) one = op(one, base);
        base = op(base, base);
    }
    return one;
}

int randint(int lo, int hi) { return uniform_int_distribution<int>(lo, hi)(rng); }

nat sbit(int x) { return nat(1) << x; }
int bit_countl(nat x) { return x ? __builtin_clzll(x) : 64; }
int bit_countr(nat x) { return x ? __builtin_ctzll(x) : 64; }
int bit_width(nat x) { return 64 - bit_countl(x); }
int popcount(nat x) { return __builtin_popcountll(x); }

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
tcF struct y_combinator_result {
    F f;
    tcT explicit y_combinator_result(T &&f): f(forward<T>(f)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return f(ref(*this), forward<Args>(args)...); }
};

tcF decltype(auto) yc(F &&f) {
    return y_combinator_result<decay_t<F>>(forward<F>(f)); }

tcT T identity(T&& x) { return forward<T>(x); }

// https://en.cppreference.com/w/cpp/utility/variant/visit
template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

template<class T, class... Ts> void match_with(T&& t, Ts &&...fs) {
    visit(overloaded{forward<Ts>(fs)...}, forward<T>(t)); }



tcT using vec = vector<T>;
#define vT vec<T>
using vi = vec<int>;
#define vI vec<Int>

template<class T> T read(void) { T x; cin >> x; return x; }

template<class T, class F> T bsearch_real(T lo, T hi, int N, F cond) {
    rep(i,0,N) {
        T mid = (lo + hi) / 2;
        if (cond(mid)) hi = mid;
        else lo = mid;
    }
    return (lo + hi) / 2;
}

tcF int bsearch(int lo, int hi, F cond) {
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (cond(mid)) hi = mid;
        else lo = mid+1;
    }
    return hi;
}

tcT void setmax(T& dest, T src) {
    if (dest < src) dest = src; }

tcT void setmin(T& dest, T src) {
    if (src < dest) dest = src; }



void subcases() {
	precompute();
	int T = 1;
	//cin >> T;
	for (int i = 0; i < T; i++) {
		solve();
	}
}

void precompute() { }

using pii = pair<int,int>;

void solve() {
	int n; cin >> n;
	vi a(n); rep(i,0,n) cin >> a[i];
	unordered_map<int,vi> g;
	unordered_set<int> v;
	unordered_map<int,int> o;
	rep(i,0,n) o[a[i]] = i;
	for (int x : a) {
		while (x && !v.count(x)) {
			int k = sbit(bit_width(x-1));
			assert(k >= x && x*2 > k);
			int y = k - x;
			dbg(x,k,y);
			g[x].Pb(y);
			g[y].Pb(x);
			v.insert(x);
			x = y;
		}
	}
	assert(g.count(0));
	tuple<int,int,int> best = {0, 0, 0};
	yc([&](auto rec, int i, int b) -> pii {
		pii r = {-1, 0};
		if (o.count(i)) r = {0, o[i]};
		vector<pii> c;
		for (int x : g[i]) if (x != b) {
			auto [d, v] = rec(x,i);
			if (d == -1) continue;
			c.Eb(d+1, v);
		}
		sort(all(c));
		reverse(all(c));
		if (sz(c)) {
			r = c[0];
		}
		if (sz(c) > 1) {
			best = max(best, {c[0].first + c[1].first, c[0].second, c[1].second});
		}
		return r;
	})(0, -1);
	cout << get<1>(best)+1 << " " << get<2>(best)+1 << " " << get<0>(best) << nl;
}

