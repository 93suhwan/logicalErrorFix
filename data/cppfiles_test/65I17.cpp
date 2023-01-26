#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long
#define double long double
#define ft first
#define sc second
#define pb push_back
#define booost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); cerr.tie(0);
#define all(x) (x).begin(),(x).end()
#define file(x) freopen(string(string((x)) + ".in").c_str(), "r", stdin); freopen(string(string((x)) + ".out").c_str(), "w", stdout);
#define GG cout << " OPA " << '\n';

using namespace std;
using namespace __gnu_pbds;
typedef pair <int, int> pi;
typedef tree <int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
random_device rd;
mt19937_64 gen(rd());
uniform_int_distribution <int> uid(0, 1000000000);
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5 + 5;
const int K = 21;
const int KS = 1e6 + 5;
const int P = 37;
const int INF = 1e9;
const double d_INF = 2000000000.0;
const double EPS = 1e-20;
const int MOD = 998244353;
const int MOD1 = 1e9 + 7;
const int LOG = 17;
const double PI = 3.14159265359;

int a[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a, a + n);
    string s;
    cin >> s;
    int x = 0, y = 0;
    vector <pair <int, char> > vec;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == 'L') {
            if (y + a[i] < x) {
                y += a[i];
                vec.pb({a[i], 'R'});
            }
            else {
                x += a[i];
                if (x <= y) {cout << -1; return;}
                vec.pb({a[i], 'L'});
            }
        }
        else {
            if (x + a[i] < y) {
                x += a[i];
                vec.pb({a[i], 'L'});
            }
            else {
                y += a[i];
                if (x >= y) {cout << -1; return;}
                vec.pb({a[i], 'R'});
            }
        }
    }
    for (auto it : vec) {
        cout << it.ft << ' ' << it.sc << '\n';
    }
}

main () {
    int test = 1;
    booost;
//    cin >> test;
    while (test --) {
        solve();
    }
}
