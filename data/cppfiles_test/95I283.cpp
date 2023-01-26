#include <bits/stdc++.h>
#include <ext/rope>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
using namespace __gnu_cxx;

template<class T>
using V = vector<T>;
template<class T>
using VV = V<V<T>>;

using ld = long double;
#define ll long long
using ull = unsigned ll;
using PLL = pair<ll, ll>;
using VLL = V<ll>;
using VB = V<bool>;
using VVB = VV<bool>;
using VVLL = VV<ll>;
using Gr = VVLL;
using MLL = map<ll, ll>;
#define UMLL unordered_map<ll, ll, custom_hash>

#define fast ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr); cerr.tie(nullptr);

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
#define OK cerr << "OK" << endl;

#define mp make_pair
#define pb push_back

//#define DEBUG

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
constexpr ll len = 1e4 + 10;

constexpr ll INF = 1e15, MINF = -INF;

constexpr ld PI = atanl(1.0L) * 4;
constexpr ld eps = 1e-9, EPS = 1e-9;

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
constexpr ll N = 30;
array<ll, N> r;
void init()
{
    FOR(s, N)
        for(ll i = 0; i <= min(s, 9LL); ++i)
            r[s] += s - i <= 9;
}

bool sol(string s, ll n, V<string> R res)
{
    if(n <= 0)
        return true;

    ll cnt = 0;
    FOR(i, s.size())
    {
        cnt = 10 * cnt + s[i] - '0';
        //cerr << s << " " << i << " -> " << cnt << "\n";

        string t = s.substr(i + 1);
        //cerr << t << "\n";

        bool g = n <= cnt;
        if(g || sol(t, n - cnt, res))
        {
            string f(s.size() - i, '0');
            f[0] = '1';

            while(res.size() + 1 < n)
            {
                --cnt;
                res.pb(f);
            }

            if(g)
                f = to_string(cnt) + t;
            else
                f[0] = cnt + '0';

            res.pb(f);

            return true;
        }

        res.clear();
    }

    return false;
}

void solve(istream R is, ostream R os)
{
    string s;
    is >> s;
    ll n;
    is >> n;

    V<string> res;
    assert(sol(s, n, res));

    show(res, os);
}

void tester(istream R is, ostream R os)
{
    auto seed = time(nullptr);
    //cerr << "seed: " << seed << "\n";
    srand(seed);
    fast
    init();
    ll q = 1;
    is >> q;

    os << setprecision(999);
    Count(q)
        solve(is, os);
}

int main()
{
    //ifstream in("text.in");
    //ofstream out("text.out");

    tester(cin, cout);
}
