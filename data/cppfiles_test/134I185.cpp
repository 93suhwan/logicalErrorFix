//bis.mi‿l.laː.hi‿r.raħ.maː.ni‿r.ra.ħiː.mi//
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define trav(a, x) for (auto& a : x)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define sp ' '
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5 + 10;
const int inf = 2e9 + 10;
const long long INF = 2e18 + 10;
const int mod = 1e9 + 7;
const char nl = '\n';

int findGCD(vl ar, int n) {
    int result = ar[0];
    for (int i = 1; i < n; i++) {
        result = gcd(ar[i], result);
        if(result == 1) {
           return 1;
        }
    }
    return result;
}

void solve() {
    int n; cin >> n;
    vl A, B;
    F0R(i, n) {
        ll inp; cin >> inp;
        if(i&1) B.pb(inp);
        else A.pb(inp);
    }
    ll gcdA = findGCD(A, sz(A));
    ll gcdB = findGCD(B, sz(B));
    bool ca = true, cb = true;
    trav(itm, B) {if (itm%gcdA == 0) ca = false;}
    trav(itm, A) {if (itm%gcdB == 0) cb = false;}
    if (ca) cout << gcdA << nl;
    else if (cb) cout << gcdB << nl;
    else cout << 0 << nl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}