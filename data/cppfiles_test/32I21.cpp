// notice the ""
#include "bits/stdc++.h"

using namespace std;

#define log1(x) cout << #x << ": " << x << endl
#define log2(x, y) cout << #x << ": " << x << ", " << #y << ": " << y << endl

#define rep(i, x, n) for (ll i = x; i < n; i++)
#define repb(i, x, n) for (ll i = x; i >= n; i--)
#define nl "\n"
#define YES cout << "YES\n";
#define NO cout << "NO\n";
#define Yes cout << "Yes\n";
#define No cout << "No\n";

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef priority_queue<ll, vll, greater<ll>> minpq;
typedef priority_queue<ll> maxpq;

// clang-format off
template <typename T> void _log(const T &t) { cout << t << " "; }
template <typename T, typename U> void _log(const pair<T, U> &p) {_log(p.first); cout<<": "; _log(p.second);cout<<endl;}
template <typename T> void _log(const vector<T> &v) {for (const T &t : v) _log(t); cout << endl;}
template <typename T> void _log(const vector<vector<T>> &v) {for (const vector<T> &t : v) _log(t); cout << endl;}
template <typename T> void _log(const unordered_set<T> &s) {for (const T &t : s) _log(t); cout << nl;}
template <typename T> void _log(const set<T> &s) {for (const T &t : s) _log(t);cout << nl;}
template <typename T> void _log(const multiset<T> &s) {for (const T &t : s) _log(t);cout << nl;}
template <typename T, typename U> void _log(const map<T, U> &m) {for (const pair<T, U> t : m) {_log(t);}}
template <typename T, typename U> void _log(const unordered_map<T, U> &m) {for (const pair<T, U> t : m) {_log(t);}}
/* const long long MOD = 998244353; */
const long long MOD = 1e9 + 7;
const long long LINF = numeric_limits<long long>::max();
const int INF = numeric_limits<int>::max();
long long _ceiling(long long a, long long b) { return (a + b - 1) / b; } // ceil a/b
long long _MOD(long long a) { return (a + MOD) % MOD; }
long long _pow(long long a, long long b) {long long res = 1; a = _MOD(a); while (b) {if (b % 2) res = _MOD(res * a); a = _MOD(a * a); b = b / 2;}return res;}
long long _inverse(long long a) { return _pow(_MOD(a), MOD - 2); } // euler phi for primes is p - 1
long long _inversemod(long long a, long long p) { return _pow(a, p - 2); } // euler phi for primes is p - 1
long long _lcm(long long a, long long b) { return (a * b) / __gcd(a, b); }
// clang-format on

// fixed size vector? use array<int, n>
#define MAXSEG 446

void solve() {
  int n;
  cin >> n;
  vi a(n);
  for (auto &e : a)
    cin >> e;

  vector<int> pfxsum(n);
  pfxsum[0] = a[0];
  rep(i, 1, n) pfxsum[i] = pfxsum[i - 1] + a[i];

  auto rangesum = [&](int l, int r) {
    return pfxsum[r] - (l - 1 >= 0 ? pfxsum[l - 1] : 0);
  };

  vector<vector<int>> dp(n, vector<int>(MAXSEG + 1, -1));
  dp[n - 1][1] = a[n - 1];

  for (int i = n - 2; i >= 0; i--) {
    for (int j = 1; j <= MAXSEG; j++) {
      int x = dp[i + 1][j];
      int y = -1;
      if (i + j < n) {
        y = dp[i + j][j - 1];
        if (rangesum(i, i + j - 1) >= y)
          y = -1;
      }

      dp[i][j] = max(x, y);
    }
  }

  for (int i = MAXSEG; i > 0; i--) {
    if (dp[0][i] != -1) {
      cout << i << nl;
      return;
    }
  }
}

int main() {
#ifdef ichigo_runtime
  auto start = std::chrono::high_resolution_clock::now();
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

#ifdef ichigo_runtime
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration =
      chrono::duration_cast<chrono::milliseconds>(stop - start).count();
  cout << "Execution Time: " << duration << "ms" << nl;
#endif
}
