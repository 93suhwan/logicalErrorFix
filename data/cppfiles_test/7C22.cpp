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
struct KMP {
  string s;
  int n;
  vector<int> link;
  void build(string str) {
    s = str;
    n = int((s).size());
    link.resize(n);
    int cur = link[0] = -1;
    for (int i = 1; i < n; i++) {
      while (cur >= 0 && s[i] != s[cur + 1]) cur = link[cur];
      if (s[i] == s[cur + 1]) cur++;
      link[i] = cur;
    }
  }
  vector<int> query(char* t) {
    vector<int> res;
    int k = strlen(t);
    int cur = -1;
    for (int i = 0; i < k; i++) {
      while (cur >= 0 && t[i] != s[cur + 1]) cur = link[cur];
      if (t[i] == s[cur + 1]) cur++;
      if (cur == n - 1) {
        res.push_back(i - n + 1);
        cur = link[cur];
      }
    }
    return res;
  }
} kmp;
void chemthan() {
  int n, m;
  cin >> n >> m;
  string a, b;
  cin >> a >> b;
  kmp.build(b);
  vector<vector<int>> mem(m + 5, vector<int>(2, -2));
  auto next_state = [&](int v, int p) {
    int& res = mem[v + 1][p];
    if (res != -2) return res;
    res = v;
    while (0 <= res && b[res + 1] != '0' + p) res = kmp.link[res];
    if (b[res + 1] == '0' + p) res++;
    return res;
  };
  vector<vector<vector<int>>> dp(
      2, vector<vector<int>>(m + 5, vector<int>(n - m + 5, INF)));
  int cur = 0, prv = 1;
  for (int u = (n + 1) - 1; u >= (0); --u) {
    for (int v = (0); v < (m + 1); ++v)
      for (int c = (0); c < (n - m + 2); ++c) dp[cur][v][c] = INF;
    for (int v = (-1); v < (m - 1); ++v)
      for (int c = (0); c < (n - m + 2); ++c) {
        int& res = dp[cur][v + 1][c];
        if (u == n) {
          if (!c) {
            res = 0;
          }
          continue;
        }
        for (int i = (0); i < (2); ++i) {
          int cost = a[u] != '0' + i;
          int nv = next_state(v, i);
          int nc = c;
          if (nv == m - 1) {
            nc--;
            nv = kmp.link[nv];
          }
          if (0 <= nc) {
            chkmin(res, dp[prv][nv + 1][nc] + cost);
          }
        }
      }
    swap(cur, prv);
  }
  for (int i = (0); i < (n - m + 2); ++i) {
    int res = dp[prv][0][i];
    if (n < res) res = -1;
    cout << res << " \n"[i == n - m + 1];
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
