#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using uint = unsigned;
using ull = unsigned ll;

constexpr ll safe_mod(ll x, ll m) { return x %= m, x < 0 ? x + m : x; }
constexpr ll pow_mod_constexpr(ll x, ll n, int m) {
    if(m == 1) return 0;
    uint _m = m; ull r = 1, _x = safe_mod(x, m);
    for(; n; n >>= 1, _x = _x * _x % _m) if(n & 1) r = r * _x % m;
    return r;
}
constexpr bool is_prime_constexpr(int n) {
    if(n <= 1) return false;
    if(n == 2 || n == 7 || n == 61) return true;
    if(n % 2 == 0) return false;
    ll d = n - 1; while(~d & 1) d /= 2;
    for(ll a : {2, 7, 61}) {
        ll t = d, y = pow_mod_constexpr(a, t, n);
        while(t != n - 1 && y != 1 && y != n - 1) y = y * y % n, t <<= 1;
        if(y != n - 1 && t % 2 == 0) return false;
    }
    return true;
}
constexpr pair<ll, ll> inv_gcd(ll a, ll b) {
    a = safe_mod(a, b);
    if(a == 0) return {b, 0};
    ll s = b, t = a, m0 = 0, m1 = 1;
    while(t) {
        ll u = s / t; s -= t * u, m0 -= m1 * u;
        ll tmp = s; s = t, t = tmp, tmp = m0, m0 = m1, m1 = tmp;
    }
    if(m0 < 0) m0 += b / s;
    return {s, m0};
}
struct barrett {
    uint m; ull im;
    barrett(uint m) :m(m), im(~0ull / m + 1) {}
    uint mul(uint a, uint b) const {
        ull z = (ull)a * b, x = (unsigned __int128)z * im >> 64; uint v = z - x * m;
        return m <= v ? v + m : v;
    }
};
template<int m> struct static_modint {
    using mint = static_modint;
  public:
    static mint raw(int v) { mint x; return x._v = v, x; }
    static_modint() :_v(0) {}
    template<class T> static_modint(T v) { ll x = v % m; _v = x < 0 ? x + m : x; }
    uint val()const { return _v; }
    mint& operator++() { if(++_v == m) _v = 0; return *this; }
    mint& operator--() { if(!_v--) _v = m - 1; return *this; }
    mint operator++(int) { mint res = *this; ++*this; return res; }
    mint operator--(int) { mint res = *this; --*this; return res; }
    mint& operator+=(const mint& rhs) { _v += rhs._v; if(_v >= m) _v -= m; return *this; }
    mint& operator-=(const mint& rhs) { _v -= rhs._v; if(_v >= m) _v += m; return *this; }
    mint& operator*=(const mint& rhs) { ull z = _v; z *= rhs._v, _v = z % m; return *this; }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }
    mint operator+()const { return *this; }
    mint operator-()const { return mint() - *this; }
    mint pow(ll n)const { assert(0 <= n); mint x = *this, r = 1; for(; n; n >>= 1, x *= x) if(n & 1) r *= x; return r; }
    mint inv() const{ if(prime) { assert(_v); return pow(m - 2); } else { auto eg = inv_gcd(_v, m); assert(eg.first == 1); return eg.second; } }
    friend mint operator+(const mint& lhs, const mint& rhs) { return mint(lhs) += rhs; }
    friend mint operator-(const mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }
    friend mint operator*(const mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }
    friend mint operator/(const mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }
    friend bool operator==(const mint& lhs, const mint& rhs) { return lhs._v == rhs._v; }
    friend bool operator!=(const mint& lhs, const mint& rhs) { return lhs._v != rhs._v; }
  private:
    uint _v;
    static constexpr bool prime = is_prime_constexpr(m);
};
template<int id> struct dynamic_modint {
    using mint = dynamic_modint;
  public:
    static void set_mod(int m) { assert(1 <= m), bt = barrett(m); }
    static mint raw(int v) { mint x; return x._v = v, x; }
    dynamic_modint() :_v(0) {}
    template<class T> dynamic_modint(T v) { ll x = v % (int)bt.m; _v = x < 0 ? x + bt.m : x; }
    uint val()const { return _v; }
    mint& operator++() { if(++_v == bt.m) _v = 0; return *this; }
    mint& operator--() { if(!_v--) _v = bt.m - 1; return *this; }
    mint operator++(int) { mint res = *this; ++*this; return res; }
    mint operator--(int) { mint res = *this; --*this; return res; }
    mint& operator+=(const mint& rhs) { _v += rhs._v; if(_v >= bt.m) _v -= bt.m; return *this; }
    mint& operator-=(const mint& rhs) { _v += bt.m - rhs._v; if(_v >= bt.m) _v -= bt.m; return *this; }
    mint& operator*=(const mint& rhs) { _v = bt.mul(_v, rhs._v); return *this; }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }
    mint operator+()const { return *this; }
    mint operator-()const { return mint() - *this; }
    mint pow(ll n)const { assert(0 <= n); mint x = *this, r = 1; for(; n; n >>= 1, x *= x) if(n & 1) r *= x; return r; }
    mint inv()const { auto eg = inv_gcd(_v, bt.m); assert(eg.first == 1); return eg.second; }
    friend mint operator+(const mint& lhs, const mint& rhs) { return mint(lhs) += rhs; }
    friend mint operator-(const mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }
    friend mint operator*(const mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }
    friend mint operator/(const mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }
    friend bool operator==(const mint& lhs, const mint& rhs) { return lhs._v == rhs._v; }
    friend bool operator!=(const mint& lhs, const mint& rhs) { return lhs._v != rhs._v; }
  private:
    uint _v;
    static barrett bt;
};
template<int id> barrett dynamic_modint<id>::bt = 998244353;
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

const int N = 2.5e5 + 5, P = 998244353;

using mint = static_modint<P>;

int n, d[N], c[N], lim = 1, bit = -1, rev[1 << 18];
mint w[1 << 18], A[1 << 18];

void NTT(mint a[]) {
    reverse(a + 1, a + lim);
    For(i, 0, lim) if(rev[i] < i) swap(a[i], a[rev[i]]);
    for(int i = 1; i < lim; i <<= 1) {
        mint wn = mint(3).pow(P / 2 / i);
        for(int j = 0; j < lim; j += i << 1) {
            mint w = 1;
            For(k, j, j + i) {
                mint &x = a[k], y = a[k + i] * w;
                a[k + i] = x - y, x += y, w *= wn;
            }
        }
    }
    mint inv = mint(lim).inv();
    For(i, 0, lim) a[i] *= inv;
}

int main() {
    cin >> n;
    int u, v, m = 0;
    rep(i, 2, n) d[i]--, scanf("%d%d", &u, &v), d[u]++, d[v]++;
    rep(i, 1, n) c[d[i]]++, m += d[i] > 0;
    while(lim <= m) lim <<= 1, bit++;
    For(i, 1, lim) rev[i] = rev[i >> 1] >> 1 | (i & 1) << bit;
    mint wn = mint(3).pow(P / lim);
    For(i, 0, lim) w[i] = i ? w[i - 1] * wn : 1, A[i] = 1;
    rep(i, 1, n) if(c[i]) For(j, 0, lim) A[j] *= (i + w[j]).pow(c[i]);
    NTT(A);
    mint ans = 0, fac = 1;
    rep(i, n - m, n) fac *= i, ans += (n - i & 1 ? -1 : 1) * fac * A[m - n + i];
    printf("%d", ans);
}