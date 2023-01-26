#include <bits/stdc++.h>

//#include <atcoder/all>
//using namespace atcoder;

//#include <ext/rope>
//#include <ext/pb_ds/assoc_container.hpp>

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC target("avx,avx2")

using namespace std;
//using namespace __gnu_cxx;
//using namespace __gnu_pbds;

template<class T>
using V = vector<T>;
template<class T>
using VV = V<V<T>>;

using ld = long double;
#define ll long long
using ull = unsigned ll;
using PLL = pair<ll, ll>;
using PII = pair<int, int>;
using VI = V<int>;
using VLL = V<ll>;
using VVI = VV<int>;
using VVLL = VV<ll>;
using Gr = VVLL;
using MLL = map<ll, ll>;
#define UMLL unordered_map<ll, ll, custom_hash>

#define fast ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);

#define R &
#define CR const R

#define FORI(i, a, b) for(ll i = a, max##i = b; i < max##i; ++i)
#define FOR(i, n) FORI(i, 0, n)
#define RFORI(i, a, b) for(ll i = a, min##i = b; i >= min##i; --i)
#define RFOR(i, n) RFORI(i, n, 0)
#define FORA(i, a) for(auto i : a)
#define FORAR(i, a) for(auto R i : a)
#define FORACR(i, a) for(auto CR i : a)
#define ALL(obj) begin(obj), end(obj)
#define Count(q) while(q--)

#ifdef LOCAL
#define OK cerr << "OK" << endl;
#else
#define OK
#endif

#define pb push_back

template<class T>
T sqr(T x)
{
    return x * x;
}

template<class T>
void cmin(T& a, T const& b)
{
    a = min(a, b);
}

template<class T>
void cmax(T& a, T const& b)
{
    a = max(a, b);
}

#ifdef LOCAL
template<class T>
void print_raw(V<T> CR t)
{
    cerr << "{";

    for(auto i : t)
        print_raw(i);
    if(!t.empty())
        cerr << "\b";

    cerr << "} ";
}

template<class T>
void print_raw(T CR t)
{
    cerr << t << " ";
}

template<class T, class... Ts>
void print_raw(T CR t, Ts CR ...vals)
{
    print_raw(t);
    print_raw(vals...);
}

template<class... Ts>
void print(Ts CR ...vals)
{
    print_raw(vals...);
    cerr << "\n";
}

template<class... Ts>
void interval(ll l, ll r, Ts CR ...vals)
{
    cerr << "[" << l << ", " << r << "]: ";
    print(vals...);
}
#else
template<class... Ts>
void print_raw(Ts CR ...vals) {}
template<class... Ts>
inline void print(Ts CR ...vals) {}
template<class... Ts>
void interval(ll l, ll r, Ts CR ...vals) {}
#endif

void YES(bool g, ostream R os, bool upper = true)
{
    if(g)
        if(upper)
            os << "YES";
        else
            os << "Yes";
    else
        if(upper)
            os << "NO";
        else
            os << "No";

    os << "\n";
}

template<class T>
void show(T CR t, ostream R os = cerr)
{
    FORACR(i, t)
        os << i << " ";
    os << "\n";
}

template<class T>
void show2d(T CR t, ostream R os = cerr)
{
    FORACR(i, t)
        show(i, os);
    os << "\n";
}

constexpr ll MOD = 998244353; //1e9 + 7;
constexpr ll len = 2e7 + 10;

constexpr ll INF = 1e9, MINF = -INF;

constexpr ld PI = atanl(1.0L) * 4;
constexpr ld eps = 1e-9, EPS = 1e-9;

//https://codeforces.com/blog/entry/62393
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator() (uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

//arr
ll qpow(ll a, ll b, ll mod = MOD)
{
    ll res = 1;
    while(b)
    {
        if(b & 1LL)
            res = res * a % mod;

        b >>= 1LL;
        a = sqr(a) % mod;
    }

    return res;
}

ll inv(ll a, ll mod = MOD)
{
    return qpow(a, mod - 2, mod);
}

template<class T>
void addfix(T R x, ll mod = MOD)
{
    if(x >= mod)
        x -= mod;
}

template<class T>
void subfix(T R x, ll mod = MOD)
{
    if(x < 0)
        x += mod;
}

template<class T>
void afix(T R x, ll mod = MOD)
{
    if(x < 0)
        x += mod;
    else if(x >= mod)
        x -= mod;
}

template<class T>
void fix(T R x, ll mod = MOD)
{
    x %= mod;
    subfix(x, mod);
}

void init() {}

struct T
{
    int k, b; //k = +-1

    int apply(int x) const
    {
        int r = k * x + b;
        subfix(r);
        return r;
    }

    void apply(T x)
    {
        //Kx * (K * x + b) + Bx = Kx * K * x + (Kx * b + Bx)
        k *= x.k;
        b = x.k * b + x.b;
        subfix(b);
    }
};

struct Vertex
{
    Vertex *plv = nullptr, *prv = nullptr;
    int l, r, sum = 0;
    T p{1, 0};

    Vertex(int l_, int r_) : l(l_), r(r_) {}

    Vertex* lv()
    {
        if(!plv)
            plv = new Vertex(l, midpoint(l, r));
        return plv;
    }

    Vertex* rv()
    {
        if(!prv)
            prv = new Vertex(midpoint(l, r) + 1, r);
        return prv;
    }

    void push()
    {
        sum = p.k * sum + p.b * (r - l + 1);
        fix(sum);

        if(l != r)
        {
            lv()->p.apply(p);
            rv()->p.apply(p);
        }

        p = {1, 0};
    }

    void apply(int lb, int rb, T t)
    {
        //print(lb, rb, "->", l, r);
        if(r < lb || l > rb)
            return;

        if(lb <= l && r <= rb)
        {
            p.apply(t);
            push();
            return;
        }

        push();
        lv()->apply(lb, rb, t);
        rv()->apply(lb, rb, t);

        sum = lv()->sum + rv()->sum;
        addfix(sum);
    }

    int add(int lb, int rb)
    {
        if(r < lb || l > rb)
            return 0;

        //push();
        if(lb <= l && r <= rb)
            return sum;

        sum = lv()->add(lb, rb) + rv()->add(lb, rb);
        addfix(sum);
        return sum;
    }
};

void solve(istream R is, ostream R os)
{
    int n;
    is >> n;

    VI a(n);
    FORAR(i, a)
        is >> i;

    constexpr int N = 1e9;
    Vertex* tree = new Vertex(1, N);
    FOR(i, n)
    {
        int sum = i ? tree->add(1, N) : 1;
        tree->apply(1, a[i], {-1, sum});
        tree->apply(a[i] + 1, N, {0, 0});
    }

    os << tree->add(1, N) << "\n";
}

void tester(istream R is, ostream R os)
{
    cerr << "MOD: " << MOD << "\n";
    auto seed = time(nullptr);
    //cerr << "seed: " << seed << "\n";
    srand(seed);
    fast
    init();
    ll q = 1;
    //is >> q;

    os << setprecision(999);
    Count(q)
        solve(is, os);
}

void tester(string CR name = "")
{
    if(name == "")
        tester(cin, cout);
    else
    {
        ifstream in(name + ".in");
        ofstream out(name + ".out");

        tester(in, out);
    }
}

int main()
{
    tester("");
}
