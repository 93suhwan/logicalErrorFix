#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
typedef int64_t ll;
typedef long double ld;
typedef unsigned long long ULL;
#define endl "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
void read(vector<int> &a) {for (auto &x : a)cin >> x;}
void read(vector<ll> &a) {for (auto &x : a)cin >> x;}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c> {i, j}; }
sim > auto dud(c * x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifndef ONLINE_JUDGE
    ~debug() { cerr << endl; }
    eni( != ) cerr << boolalpha << i; ris;
}
eni( == ) ris << range(begin(i), end(i));
}
sim, class b dor(pair < b, c > d) {
    ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it)
        *this << ", " + 2 * (it == d.b) << *it;
    ris << "]";
}
#else
    sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

const int MOD = 1e9 + 7;
const int INF = (int)2e9 + 7;
const ll LINF = (ll)1e18;
const ld PI = 3.1415926535897932384626433832795;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    read(v);
    ll s = 0;
    for (int i = 0; i < n; i++) {
        s += v[i];
    }
    int idx = 0;
    ll g = 1;
    for (int i = 0; i < n; i++) {
        if (s - v[i] != 0) {
            g = __gcd((s - v[i]), v[i]);
            if ((s - v[i]) / g + ((n - 1) * v[i]) / g <= 1e9) {
                idx = i;
                break;
            }
        }
    }
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        if (i == idx) {
            tot += (v[i]) * (-(s - v[i]));
            cout << -(s - v[i]) / g << ' ';
        }
        else {
            tot += (v[idx]) * (v[i]);
            cout << v[idx] / g << ' ';
        }
    }
    if (tot != 0)assert(false);
    cout << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test_cases = 1;
    cin >> test_cases;
    auto t1 = high_resolution_clock::now();
    for (int tt = 1; tt <= test_cases; tt++)
    {
        //cout << "Case #" << tt << ": ";
        solve();
    }
    auto t2 = high_resolution_clock::now();
    auto time = duration_cast<duration<double>>(t2 - t1);
    cerr << "Time elapsed = " << time.count() << endl;
}
