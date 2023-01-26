#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <bitset>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <algorithm>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <ctime>
#include <chrono>
#include <unordered_map>
#include <complex>

/*
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,tune=native")
*/


#ifdef LOCAL
    #define dbg(x) cout << #x << " : " << x << endl;
#else
    #define dbg(x)
#endif

#define int long long
#define pb push_back
#define ppb pop_back()
#define mp make_pair
#define fi(a, b) for (int i = a; i < b; i++)
#define fj(a, b) for (int j = a; j < b; j++)
#define fk(a, b) for (int k = a; k < b; k++)
#define fx(x, a) for (auto& x : a)
#define siz(x) (int)x.size()
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define left leftkekmda
#define right rightkekmda

using namespace std;

template<typename T1, typename T2>inline void mine(T1 &x, const T2 &y) { if (y < x) x = y; }
template<typename T1, typename T2>inline void maxe(T1 &x, const T2 &y) { if (x < y) x = y; }

template<typename T> ostream& operator << (ostream &os, const vector<T> &b) {
    for (const auto &k : b) os << k << ' ';
    return os;
}
template<typename T> istream& operator >> (istream &is, vector<T> &b) {
    for (auto &k : b) is >> k;
    return is;
}
template<typename T> ostream& operator << (ostream &os, const set<T> & b) {
    for (const auto &k : b) os << k << ' ';
    return os;
}
template<typename T1, typename T2> ostream& operator << (ostream & os, const pair<T1, T2> &b) {
    os << b.first << ' ' << b.second;
    return os;
}


typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<char> vch;
typedef vector<str> vs;
using cd = complex<long double>;




mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;
//const int N = ;
namespace md {
    ll mod(ll n) {
        if (n <= -MOD || n >= MOD) n %= MOD;
        if (n < 0) return n + MOD;
        else return n;
    }

    ll add(ll a, ll b) {
        a += b;
        if (a >= MOD) return a - MOD;
        return a;
    }

    ll sub(ll a, ll b) {
        a -= b;
        if (a < 0) return a + MOD;
        return a;
    }

    ll mult(ll a, ll b) {
        return a * b % MOD;
    }

    ll powmod(ll a, ll p) {
        if (p == 0) return 1;
        if (p & 1) return mult(a, powmod(a, p - 1));
        return powmod(mult(a, a), p / 2);
    }

    ll rev(ll a) {
        return powmod(a, MOD - 2);
    }
}

struct M {
    ll x;
    M (ll _x) { x = md::mod(_x); }
    M () { x = 0; }
    M operator + (M y) const {
        return M(md::add(x, y.x));
    }
    M operator - (M y) const {
        return M(md::sub(x, y.x));
    }
    M operator * (M y) const { return md::mult(x, y.x); }
    M operator / (M y) const { return md::mult(x, md::rev(y.x)); }
    M operator + (ll y) { return (*this) + M(y); }
    M operator - (ll y) { return (*this) - M(y); }
    M operator * (ll y) { return (*this) * M(y); }
    M operator / (ll y) { return (*this) / M(y); }
    M operator ^ (ll y) const { return M(x ^ y); }
    void operator += (M y) { *this = *this + y; }
    void operator -= (M y) { *this = *this - y; }
    void operator *= (M y) { *this = *this * y; }
    void operator /= (M y) { *this = *this / y; }
    void operator += (ll y) { *this = *this + y; }
    void operator -= (ll y) { *this = *this - y; }
    void operator *= (ll y) { *this = *this * y; }
    void operator /= (ll y) { *this = *this / y; }
    void operator ^= (ll y) { *this = *this ^ y; }
    bool operator == (M y) const { return x == y.x; }
    bool operator < (M y) const { return x < y.x; }
};

M operator * (ll x, const M &y) {return y * x;}
M operator + (ll x, const M &y) {return y + x;}
M operator - (ll x, const M &y) {return M(x) - y;}
M operator / (ll x, const M &y) {return M(x) / y;}

ostream& operator << (ostream& os, const M &a) {
    os << a.x;
    return os;
}

istream& operator >> (istream& is, M &a) {
    ll x;
    is >> x;
    a = M(x);
    return is;
}

const int LOG = 19;
const int N = 1 << LOG;
const int NN = N + 5;
const ld PI = 4 * atan(1);

int bitrev[NN];
cd w[NN];

void init() {
    fi(0, N) {
        bitrev[i] = ((i & 1) << (LOG - 1)) ^ (bitrev[i >> 1] >> 1);
        w[i] = complex(cos(2 * PI * i / N), sin(2 * PI * i / N));
    }
}


void fft(vector<cd> & a, int k) {
    int L = 1 << k;
    fi(0, L) {
        int x = bitrev[i] >> (LOG - k);
        if (i > x)
            swap(a[i], a[x]);
    }
    for (int lvl = 0; lvl < k; ++lvl) {
        int len = 1 << lvl;
        for (int i = 0; i < L; i += len << 1) {
            fj(0, len) {
                cd x = a[i + j];
                cd y = a[i + j + len] * w[j << (LOG - 1 - lvl)];
                a[i + j] = x + y;
                a[i + j + len] = x - y;
            }
        }
    }
}

void invfft(vector<cd> & a, int k) {
    fft(a, k);
    int L = 1 << k;
    reverse(a.begin() + 1, a.begin() + L);
    fx(x, a) {
        x /= L;
    }
}

vector<ll> mult(vector<ll> & a,  vector<ll> & b) {
    int k = 0;
    while ((1 << k) < siz(a) + siz(b) - 1)
        ++k;
    int L = 1 << k;
    vector<cd> ac(L);
    vector<cd> bc(L);
    vector<cd> cc(L);
    fi(0, a.size())
        ac[i] = a[i];
    fi(0, b.size())
        bc[i] = b[i];
    fft(ac, k);
    fft(bc, k);
    fi(0, L)
        cc[i] = ac[i] * bc[i];
    invfft(cc, k);
    vector<ll> c(L);
    fi(0, L)
        c[i] = (long long) round(cc[i].real());
    return c;
}


using ht = unordered_map<int, int>;

void solve() {
    init();
    int n, m, k;
    cin >> n >> m >> k;
    
    auto add = [&](int& x, int y) {
        x += y;
        x %= k;
        return x;
    };
    auto sub = [&](int& x, int y) {
        x -= y;
        if (x < 0) x = (x % k + k) % k;
        return x; 
    };

    vi a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= k;
        //dbg(a[i]);
        add(sum, a[i]);
    } 
    M ans;
    if (m <= 3) {
        vi b;
        for (int i = 0; i < m; ++i) {
            b.insert(b.end(), all(a));
        }
        b.insert(b.end(), all(b));
        ht cnt;
        int ls = 0;
        int rs = 0;
        ++cnt[0];
        for (int i = 0; i < b.size(); ++i) {
            add(rs, b[i]);
            //dbg(rs);
            if (i < n * m) {
                ans += cnt[rs];
                //dbg(cnt[rs]);
                if (i != n * m - 1) ++cnt[rs];
            } else {
                --cnt[ls];
                //dbg(cnt[rs]);
                ans += cnt[rs];
                add(ls, b[i - n * m]);
            }
        } 
        if (sum * m % k == 0) {
            ans -= n * m - 1;
        }
    } else {
        { // 0 full, in one
            ht cnt;
            int sum = 0;
            M delta;
            for (int i = 0; i < n; ++i) {
                ++cnt[sum];
                add(sum, a[i]);
                delta += cnt[sum];
            }
            if (sum == 0) {
                delta -= 1;
            }
            delta *= m;
            dbg(delta);
            ans += delta;
        }

        { //0 full in two pref) + suf)
            ht cnt;
            int sum = 0;
            M delta;
            for (int i = 0; i + 1 < n; ++i) {
                add(sum, a[i]);
                ++cnt[sum];
            }
            sum = 0;
            for (int i = n - 1; i > 0; --i) {
                add(sum, a[i]);
                int need = 0;
                sub(need, sum);
                delta += cnt[need];
            }
            delta *= m;
            dbg(delta);
            ans += delta;
        }

        { // 1, ... full + pref) + suf) 
            vector<int> poly_pref(k, 0);
            {
                int sum = 0;
                for (int i = 0; i < n; ++i) {
                    ++poly_pref[sum];
                    add(sum, a[i]);
                }
            }

            vector<int> poly_suf(k, 0); 
            {
                int sum = 0;
                for (int i = n - 1; i >= 0; --i) {
                    ++poly_suf[sum];
                    add(sum, a[i]);
                }
            }

            vector<int> poly = mult(poly_pref, poly_suf);
            fx(x, poly) x %= MOD;
            for (int i = k; i < poly.size(); ++i) {
                poly[i % k] = md::add(poly[i % k], poly[i]);
            }
            M delta;
            for (int cnt = 1; cnt <= m - 2; ++cnt) {
                int need = 0;
                sub(need, cnt * sum % k);
                delta += poly[need];
            }
            delta *= m;
            dbg(delta);
            ans += delta;
        }   

        { // m - 1 full, pref + suf < n
            M delta;
            ht cnt;
            int need = 0;
            sub(need, m * sum % k);
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                ++cnt[sum];
                add(sum, a[i]);
                delta += cnt[sub(sum, need)];
            }
            delta *= m;
            dbg(delta);
            ans += delta;
        }

        M delta;
        if (sum * m % k == 0) {
            delta = 1;
        }
        dbg(delta);
        ans += delta;
    }
           
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) solve();
}
