// #pragma GCC optimize (3)
// #pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
#define mm1(a) memset(a, -1, sizeof(a))
#define mm2(a) memset(a, 0, sizeof(a))
#define mm3(a) memset(a, inf, sizeof(a))
#define mm4(a) memset(a, INF, sizeof(a))
#define ms(a, l, r) memset(a + l, 0, (r - l + 1) * sizeof(a[0]))
#define mc(a, b, l, r) memcpy(a + l, b + l, (r - l + 1) * sizeof(a[0]))
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#ifndef ONLINE_JUDGE
#define debug(x...)                            \
    do {                                       \
        cout << "\033[33;1m " << #x << " -> "; \
        err(x);                                \
    } while (0)
void err() { cout << "\033[39;0m" << endl; }
template <template <typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) {
    for (auto v : a) cout << v << ' ';
    err(x...);
}
template <typename T, typename... A>
void err(T a, A... x) {
    cout << a << ' ';
    err(x...);
}
#else
#define debug(...)
#endif
int dir[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
ll read() {
    ll x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
void wri(ll x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        wri(x / 10);
    putchar(x % 10 + '0');
}
void write(ll x) {
    wri(x);
    puts("");
}
ll ksc(ll a, ll b, ll mod) {
    return ((a * b -
             (long long)((long long)((long double)a / mod * b + 1e-3) * mod)) %
                mod +
            mod) %
           mod;
}
ll ksm1(ll a, ll n, ll mod) {
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= mod)
        if (n & 1)
            (t *= a) %= mod;
    return t;
}
ll ksm2(ll a, ll b, ll mod) {
    ll res = 1;
    while (b) {
        if (b & 1)
            res = ksc(res, a, mod);
        b >>= 1, a = ksc(a, a, mod);
    }
    return res % mod;
}
int is2pow(ll x) { return x > 0 ? (x & (x - 1)) == 0 : 0; }
ll lowbit(ll x) { return x & -x; }
ll myrand1(ll l, ll r) {
    ll num = ((ll)rand() << 30) | ((ll)rand());
    return num % (r + 1 - l) + l;
}  // srand(time(0));
ll myrand2(ll l, ll r) {
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<ll>(l, r)(gen);
}



const int N = 1e6 + 6;
int arr[N], brr[N];
int cnt[N];



signed main() {


    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        int nn = __gcd(n, d);
        ms(arr, 0, nn);
        ms(cnt, 0, n);
        for (int i = 1; i <= n; i++) {
            int x;
            x = read();
            brr[i] = x;
            if (!x) 
                arr[(x - 1) % nn + 1] = 1;
        }
        int ans = 0;
        for (int i = 1; i <= nn; i++)
            if (arr[i])
                ans++;
        if (ans != nn) {
            cout << -1 << endl;
            continue;
        }
        ans = 0;
        for (int i = 1; i <= nn; i++) {
            int j = i;
            int geshu = 0;
            int mark = 0;
            while(1) {
                if (!mark && brr[j]) {
                    j += nn;
                    j = (j - 1) % n + 1;
                    continue;
                }
                else 
                    mark = 1;
                // debug(j);
                if (cnt[j]) {
                    ans = max(ans, geshu);
                    break;
                } 
                if (brr[j] == 1) 
                    geshu++;
                else {
                    ans = max(ans, geshu);
                    geshu = 0;
                }
                cnt[j] = 1;
                j += d;
                j = (j - 1) % n + 1;
            }
        }
        cout << ans << endl;
    }
 





    return 0;
}

