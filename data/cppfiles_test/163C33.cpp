#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int FFTMOD = 119 << 23 | 1;
const int INF = (int)1e9 + 23111992;
const long long LINF = (long long)1e18 + 23111992;
const long double PI = acos((long double)-1);
const long double EPS = 1e-9;
inline long long gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline long long fpow(long long n, long long k, int p = MOD) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
template <class T>
inline int chkmin(T& a, const T& val) {
  return val < a ? a = val, 1 : 0;
}
template <class T>
inline int chkmax(T& a, const T& val) {
  return a < val ? a = val, 1 : 0;
}
inline unsigned long long isqrt(unsigned long long k) {
  unsigned long long r = sqrt(k) + 1;
  while (r * r > k) r--;
  return r;
}
inline long long icbrt(long long k) {
  long long r = cbrt(k) + 1;
  while (r * r * r > k) r--;
  return r;
}
inline void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
inline void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
inline int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
inline int inv(int a, int p = MOD) { return fpow(a, p - 2, p); }
inline int sign(long double x) { return x < -EPS ? -1 : x > +EPS; }
inline int sign(long double x, long double y) { return sign(x - y); }
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int mrand() { return abs((int)mt()); }
inline int mrand(int k) { return abs((int)mt()) % k; }
template <typename X>
void debug(X x) {
  cerr << x << "] ";
}
template <typename X, typename... Y>
void debug(X x, Y... y) {
  cerr << x << " ";
  debug(y...);
}
void chemthan() {
  int test;
  cin >> test;
  while (test--) {
    int n, m, rb, cb, rd, cd, p;
    cin >> n >> m >> rb >> cb >> rd >> cd >> p;
    int ii = rb, jj = cb;
    int dr = 1, dc = 1;
    if (!(1 <= ii + dr && ii + dr <= n)) {
      dr = -dr;
    }
    if (!(1 <= jj + dc && jj + dc <= m)) {
      dc = -dc;
    }
    int rr = dr, cc = dc;
    vector<pair<int, int> > cycle;
    while (1) {
      cycle.push_back({ii, jj});
      if (!(1 <= ii + dr && ii + dr <= n)) {
        dr = -dr;
      }
      if (!(1 <= jj + dc && jj + dc <= m)) {
        dc = -dc;
      }
      ii += dr, jj += dc;
      if (!(1 <= ii + dr && ii + dr <= n)) {
        dr = -dr;
      }
      if (!(1 <= jj + dc && jj + dc <= m)) {
        dc = -dc;
      }
      if (make_pair(ii, jj) == make_pair(rb, cb) && dr == rr && dc == cc) {
        break;
      }
    }
    int x = mult(p, inv(100));
    int y = (1 - x + MOD) % MOD;
    vector<pair<int, int> > dp(int((cycle).size()));
    dp[int((cycle).size()) - 1] = make_pair(1, 0);
    for (int i = (int((cycle).size()) - 1) - 1; i >= (0); --i) {
      int u = cycle[i].first;
      int v = cycle[i].second;
      dp[i] = dp[i + 1];
      if (u == rd || v == cd) {
        dp[i].first = mult(y, dp[i].first);
        dp[i].second = mult(y, dp[i].second);
      }
      addmod(dp[i].second, 1);
    }
    int u = cycle.back().first;
    int v = cycle.back().second;
    if (u == rd || v == cd) {
      int aa = mult(dp[0].second, y);
      addmod(aa, 1);
      int bb = 1;
      submod(bb, mult(dp[0].first, y));
      int r = mult(aa, inv(bb));
      int res = mult(dp[0].first, r);
      addmod(res, dp[0].second);
      submod(res, 1);
      cout << res << "\n";
    } else {
      int aa = dp[0].second;
      addmod(aa, 1);
      int bb = 1;
      submod(bb, dp[0].first);
      int r = mult(aa, inv(bb));
      int res = mult(dp[0].first, r);
      addmod(res, dp[0].second);
      submod(res, 1);
      cout << res << "\n";
    }
  }
}
int32_t main(int32_t argc, char* argv[]) {
  ios_base::sync_with_stdio(0), cin.tie(0);
  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }
  if (argc > 2) {
    assert(freopen(argv[2], "wb", stdout));
  }
  chemthan();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
