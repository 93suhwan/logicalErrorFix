#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define elif else if
#define SZ(x) (int)((x).size())
#define ALL(a) a.begin(), a.end()
using namespace std;
using namespace __gnu_pbds;
using LL = long long;
using LD = long double;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;
using TI = tuple<int, int, int>;
using TL = tuple<LL, LL, LL>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
int bcnt(const int64_t &a) { return __builtin_popcountll(a); }
template <class T> int blen(const T &a) { return a ? 1 + blen(a / 2) : 0; }
template <class A, class B> B conv(const A &a, B b = B()) {
    stringstream s;
    s << a, s >> b;
    return b;
}
template <class T> T inf() { return numeric_limits<T>::max() / 2; }
template <class T> T sign(const T &a) { return a == 0 ? 0 : (a < 0 ? -1 : 1); }
template <class T> T floor(const T &a, const T &b) {
    assert(b != 0);
    return sign(a) * sign(b) > 0 ? abs(a) / abs(b) : -(abs(a) + abs(b) - 1) / abs(b);
}
template <class T> T ceil(const T &a, const T &b) {
    assert(b != 0);
    return sign(a) * sign(b) > 0 ? (abs(a) + abs(b) - 1) / abs(b) : -abs(a) / abs(b);
}
template <class T> bool chmin(T &a, T b) { return b < a ? a = b, true : false; }
template <class T> bool chmax(T &a, T b) { return b > a ? a = b, true : false; }
template <class T> auto min(const T &a) { return *min_element(ALL(a)); } 
template <class T> auto max(const T &a) { return *max_element(ALL(a)); }
template <class T> auto sum(const T &a) { return accumulate(ALL(a), (typename T::value_type)0); }
template <> auto sum(const vector<int> &a) { return accumulate(ALL(a), 0LL); }
template <> auto sum(const vector<string> &a) { return accumulate(ALL(a), string()); }
template <class T> void uniq(T &a) { sort(ALL(a)); a.erase(unique(ALL(a)), a.end()); }
template <class T> auto vect(const T &v, int n) { return vector<T>(n, v); }
template <class T, class... D> auto vect(const T& v, int n, D... m) {
    return vector<decltype(vect(v, m...))>(n, vect(v, m...));
}
template <class T> void in(T &a) { cin >> a; }
template <class A, class... B> void in(A &a, B &... b) { cin >> a, in(b...); }
template <class T> void in(vector<T> &vec) { for (auto& v: vec) cin >> v; }
void ou() { cout << '\n'; }
template<class T> void ou(const T &a) { cout << a << '\n'; }
template <class A, class... B> void ou(const A &a, const B &... b) {
    cout << a << ' ', ou(b...);
}
template<class A, class B> void ou(const pair<A, B> &p) {
    cout << p.first << ' ' << p.second << '\n';
}
template<class A, class B, class C> void ou(const tuple<A, B, C> &p) {
    cout << get<0>(p) << ' ' << get<1>(p) << ' ' << get<2>(p) << '\n';
}
template <class T> void ou(const vector<T> &vec) {
    bool first = true;
    for (auto& v: vec) { cout << (first ? "" : " "); cout << v; first = 0; }
    cout << '\n';
}
template<class T> inline void YES(T condition) { 
    if(condition) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}
template<class T> inline void Yes(T condition) {
    if(condition) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}

// not a multiset
// find_by_order(k) -> iterator of k-th(0-based) element
// order_of_key(k) -> index of lower_bound(k)
// tr.join(k) -> merge two trees
template<class T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<class T> T lcm(T a, T b){
    return a / gcd(a, b) * b;
}
long long qpow(long long a, long long b, int MOD) {
    if (b == 0) return 1;
    long long res = 1;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
 
const int MOD = 1e9 + 7;
const int maxn = 2e6;
const LD eps = 1e-8;
const LD pi = acos(-1);
// const int INF = 2e9;
int fac[maxn + 5];
int invfac[maxn + 5];
void init() {
    fac[0] = 1;
    for (int i = 1; i <= maxn; i++) fac[i] = 1LL * fac[i - 1] * i % MOD;
    invfac[maxn] = (int)(qpow(fac[maxn], MOD - 2, MOD));
    for (int i = maxn - 1; i >= 0; i--) invfac[i] = 1LL * invfac[i + 1] * (i + 1) % MOD;
}
int C(int n, int k) {
    assert(0 <= k && n >= k);
    int tmp = (int)(1LL * invfac[k] * invfac[n - k] % MOD);
    return (int)(1LL * fac[n] * tmp % MOD);
}
void Add(int& x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    if (x < 0) x += MOD;
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

// #ifdef FANZHH
//     freopen("input.txt", "r", stdin);
// #endif

    int T; cin >> T;
    using AR = array<int, 4>;
    while (T--) {
        int n; cin >> n;
        vector<AR> a(n);
        for (int i = 0; i < n; i++) {
            int x, y, m; cin >> x >> y >> m;
            a[i] = {x, y, m, i};
        }
        auto score = [](AR &v) { return v[0] + v[1] - v[2]; };
        sort(ALL(a), [&](AR &v1, AR &v2) {
            if (score(v1) != score(v2)) {
                return score(v1) < score(v2);
            }
            return v1[0] < v2[0];
        });
        int ret = 0;
        vector<PII> ans(n);
        int j = 0;
        for (int i = 0; i < n; i = j + 1) {
            j = i;
            while (j + 1 < n && score(a[i]) == score(a[j + 1])) j++;
            // int mi = (a[i][1] >= a[i][2]) ? a[i][0] : ;
            int mi = a[i][0] - max(0, a[i][2] - a[i][1]);
            set<int> s;
            for (int k = i; k <= j; k++) {
                int x = a[k][0];
                int y = a[k][1];
                int m = a[k][2];
                int qi = a[k][3];
                int c1 = x - max(mi, x - m);
                int c2 = m - c1;
                ans[qi] = {c1, c2};
                s.insert(x - c1);
            }
            ret += SZ(s);
        }
        cout << ret << '\n';
        for (int i = 0; i < n; i++) {
            auto [x, y] = ans[i];
            cout << x << ' ' << y << '\n';
        }
    }

// #ifdef FANZHH
//     fclose(stdin);
// #endif

    return 0;
}
