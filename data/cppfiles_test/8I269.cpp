#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef vector<int> vi;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
int MOD = 1e9 + 7;

int modpow(int x, int n, int m = MOD) {
    int res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = (res * x) % m;
        x = (x * x) % m;
        n >>= 1;
    }
    return res;
}

int binpow(int x, int n) {
    int res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * x;
        x = (x * x);
        n >>= 1;
    }
    return res;
}
// @param m should be prime
int modinv(int x, int m = MOD)
{
    return modpow(x, m - 2, m);
}

#ifndef ONLINE_JUDGE
#define debug(x)                                                               \
  cerr << #x << " ";                                                           \
  _print(x);                                                                   \
  cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }

template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(vector<T> v);
template <class T> void _print(set<T> v);
template <class T, class V> void _print(map<T, V> v);
template <class T> void _print(multiset<T> v);
template <class T, class V> void _print(pair<T, V> p) {
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}
template <class T> void _print(vector<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T> void _print(set<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T> void _print(multiset<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V> void _print(map<T, V> v) {
    cerr << "[ ";
    for (auto i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
double eps = 1e-12;
#define forn(i, e) for (int i = 0; i < e; i++)
#define forsn(i, s, e) for (int i = s; i < e; i++)
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin()                                                             \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define allrev(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
char moves[4] = {'L', 'U', 'R', 'D'};
int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
int dy[8] = { -1, 0, 1, 0, -1, 1, - 1, 1};
int add(long long a, long long b) {return ((a % MOD) + (b % MOD)) % MOD;}
int subt(long long a, long long b) {return ((a % MOD) - (b % MOD)) % MOD;}
int mult(long long a, long long b) {return ((a % MOD) * (b % MOD)) % MOD;}

// auto lambda = [](auto x, auto y) {return x + y;};

void solve() {
    int n;
    cin >> n;
    if (n % 3 == 0) {
        cout << n / 3 << " " << n / 3 << ln;
        return ;
    }
    int a = n / 3, b = n / 3;
    int last = n % 10;
    if (n < 10) {
        cout << a << " " << b + 1 << ln;
        return;
    }
    if (last % 2 == 0) {
        cout << a << " " << b + 1 << ln;
    } else {
        cout << a + 1 << " " << b  << ln;
    }
}
int32_t main() {
    fast_cin();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    int t = 1;
    cin >> t;
    for (int it = 0; it < t; it++) {
        // cout << "Case #" << it + 1 << ": ";
        solve();
    }
    return 0;
}