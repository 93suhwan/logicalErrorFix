#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/priority_queue.hpp>
using namespace std;
typedef long long LL;
// typedef __int128 LL;
typedef unsigned long long ULL;
// #define int long long
#define pi acos(-1)
#define endl '\n'
#define mem(a, b) memset(a, b, sizeof(a))
#define all(_v) _v.begin(), _v.end()

LL mo = 1e9 + 7;
inline LL msub(LL x, LL y, LL mo = mo) { return (x -= y) < 0 ? x + mo : x; }

template <class T>
void print(T x)
{
    if (x < 0)
    {
        x = -x;
        putchar('-');
        // *O++ = '-';
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
    // *O++ = x%10 + '0'
}
// fwrite(obuf,O-obuf,1,stdout);

template <class T>
inline void qr(T &n)
{
    n = 0;
    char c = getchar();
    LL sgn = 1;

    while (c > '9' || c < '0')
    {
        if (c == '-')
            sgn = -1;
        c = getchar();
    }

    while (c <= '9' && c >= '0')
    {
        n = (n << 3) + (n << 1) + (c ^ 0x30);
        c = getchar();
    }

    n *= sgn;
}

inline char qrc()
{
    char c = getchar();
    while (c != '+' and c != '-')
        c = getchar();
    return c;
}
struct range
{
    struct _iterator
    {
        LL _start;
        LL _step;
        _iterator(LL from, LL step) : _start(from), _step(step) {}
        _iterator(LL from) : _start(from), _step(1) {}
        inline bool sign(LL x) { return x < 0; }
        bool operator!=(_iterator &b) { return _start != b._start and sign(b._start - _start) == sign(_step); }
        LL operator*() { return _start; }
        _iterator &operator++()
        {
            _start += _step;
            return *this;
        }
    };
    _iterator _finish;
    _iterator _begin;
    range(LL to) : _begin(0), _finish(to) {}
    range(LL from, LL to) : _begin(from), _finish(to) {}
    range(LL from, LL to, LL step) : _begin(from, step), _finish(to, step) {}
    _iterator &begin() { return _begin; }
    _iterator &end() { return _finish; }
};

inline void exgcd(LL a, LL b, LL &x, LL &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}

inline LL inv(LL a, LL mo)
{
    LL x, y;
    exgcd(a, mo, x, y);
    return x >= 0 ? x : x + mo;
}

LL n, m, T, tot, q, s, t, k, L, R;

// __gnu_pbds::tree<int, __gnu_pbds::null_type, std::less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> TTT;
inline LL modadd(LL &x, LL y) { return (x += y) >= mo ? x -= mo : x; }
inline LL madd(LL x, LL y) { return (x += y) >= mo ? x - mo : x; }
inline LL modsub(LL &x, LL y) { return (x -= y) < 0 ? x += mo : x; }
inline LL msub(LL x, LL y) { return (x -= y) < 0 ? x + mo : x; }

int clz(int N)
{
    return 32 - __builtin_clz(N);
}

struct node
{
};

template <LL MOD>
struct Mod
{
    LL x;
    Mod(LL x = 0) : x(x) {}
    Mod operator+(Mod b)
    {
        LL y = x + b.x;
        return y < MOD ? y : y - MOD;
    }
    Mod operator-(Mod b) { return x - b.x + (x < b.x ? MOD : 0); }
    Mod operator*(Mod b) { return x * b.x % MOD; }
    void operator+=(Mod b)
    {
        x += b.x;
        x < MOD ?: x -= MOD;
    }
    void operator*=(Mod b) { (x *= b.x) %= MOD; }
    void operator-=(Mod b)
    {
        x -= b.x;
        -x < 0 ?: x += MOD;
    }
};

void solve()
{
    int n, q;
    qr(n);
    qr(q);
    vector<int> V(n + 1, 0);
    vector<int> P(n + 1, 0);
    unordered_map<int, vector<int>> M;
    // STMax<LL> T(n);
    for (auto i : range(n))
    {
        char c = qrc();
        if (c == '+')
        {
            V[i + 1] = 1 * ((i & 1) ? -1 : 1);
        }
        else
            V[i + 1] = -1 * ((i & 1) ? -1 : 1);
        P[i + 1] = P[i + 1 - 1] + V[i + 1];
        M[P[i + 1]].emplace_back(i + 1);
    }

    // T.generate_max();
    for (auto qi : range(q))
    {
        int l, r;
        qr(l);
        qr(r);

        int res = P[r] - P[l - 1];
        if (res == 0)
            cout << 0 << endl;
        else if (res & 1)
        {
            cout << 1 << endl;
            // res += P[l - 1];
            int px = *lower_bound(all(M[((res > 0 ? res + 1 : res - 1)) / 2 + P[l - 1]]), l);
            cout << px << endl;
        }
        else
        {
            cout << 2 << endl;
            // res += P[l - 1];
            int px = *lower_bound(all(M[res / 2 + P[l - 1]]), l);
            int py = r;
            // upper_bound(P.begin(), P.end(), res + P[l - 1]);
            cout << px << ' ';
            cout << py << endl;

            // cout << 2 << endl;
        }
    }
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cerr << Vector2::SignedAngle(Vector2(1, 0), Vector2(-1, -1)) << endl;
    // cin >> T;
    int T;
    // T = 1;
    qr(T);
    for (auto i : range(T))
    {
        // cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}
/*
5
1 5
0 1
1 0
4 0
6 3

*/