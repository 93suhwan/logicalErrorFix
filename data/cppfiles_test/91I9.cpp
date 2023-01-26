#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define forn(i, j, k) for(auto i=j;i<k;i++)
#define Forn(i, j, k) for(auto i=j;i>k;i--)
#ifdef XYL_DEBUG
#define debug(x) cerr<<(#x)<<" : "<<(x)<<' '
#define debugArr(x, i, n) cerr<<(#x)<<" : ";forn(_,i,n)cerr<<x[_]<<' '
#else
#define debug(x) 0
#define debugArr(x,i,n) 0
#endif
#define numb (ch^'0')
#define mk make_pair
#define pb push_back
#define read(v, i) forn(_,0,i)rd(v[_])
#define opt(x) (x<0?putchar('-'),output(-x):output(x))
typedef long long ll;

template<class T>
void rd(T &x) {
    char ch;
    x = 0;
    bool fl = false;
    while (!isdigit(ch = getchar()))(ch == '-') && (fl = true);
    for (x = numb; isdigit(ch = getchar()); x = x * 10 + numb);
    (fl == true) && (x = -x);
}

template<class T>
void output(T x) {
    if (x / 10)output(x / 10);
    putchar(x % 10 + '0');
}

template<class T>
void ot(T x, int n) {
    forn(i, 0, n)i ? putchar('\n') : 0, opt(x[i]);
}

namespace Modulo {
    using type = int;

    const type mod = 998244353;

    type ad(type x, type y) { return x + y >= mod ? x + y - mod : x + y; }

    type sub(type x, type y) { return ad(x, mod - y); }

    type mul(type x, type y) { return 1LL * x * y % mod; }

    void inc(type &x, type y) { x = ad(x, y); }

    void inc2(type &x, type y) { x = mul(x, y); }

    type qm(type x, type y = mod - 2) {
        type ret = 1;
        while (y) {
            if (y & 1) ret = mul(x, ret);
            x = mul(x, x);
            y >>= 1;
        }
        return ret;
    }

    type div(type x, type y) { return mul(x, qm(y)); }

    template<class ...Args>
    type ad(type a, type b, Args ...args) { return ad(ad(a, b), args...); }

    template<class ...Args>
    type mul(type a, type b, Args ...args) { return mul(mul(a, b), args...); }
}

ll gcd(ll i, ll j) {
    return !j ? i : gcd(j, i % j);
}

ll lcm(ll i, ll j) {
    return i / gcd(i, j) * j;
}

using namespace Modulo;
gp_hash_table<int, int> mpp[100007];
int arr[100007];
int n;

int dfs(int i, int j) {
    if (i < 0)return 0;
    if (mpp[i][j]!=0)return mpp[i][j];
    if (arr[i] % j == 0)return mpp[i][j] = ad(dfs(i - 1, j), mul(arr[i] / j - 1, i + 1));
    int tm = arr[i] / j + 1;
    return mpp[i][j] = ad(dfs(i - 1, arr[i] / tm), mul(tm - 1, i + 1));
}
gp_hash_table<int, int>tmp;
void solve() {
    rd(n);
    read(arr, n);
    int ans = 0;
    Forn(i, n - 1, -1)ans = ad(ans, dfs(i, arr[i])),tmp = move(mpp[i]);
    opt(ans);
    putchar('\n');
}

signed main() {
    int t = 1;
    rd(t);
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}