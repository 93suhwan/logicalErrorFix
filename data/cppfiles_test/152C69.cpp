#include <bits/stdc++.h>
using namespace std;
template <class a, class b>
ostream& operator<<(ostream& os, const pair<a, b>& p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  if (!v.size())
    os << "]";
  else
    for (int i = 0; i < v.size(); ++i) os << v[i] << ",]"[i == v.size() - 1];
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const set<T>& s) {
  os << "{";
  if (!s.size())
    os << "}";
  else
    for (auto x : s) os << x << ",}"[x == *s.rbegin()];
  return os;
}
void printr(ostream& os) { os << '\n'; }
template <class T, class... Args>
void printr(ostream& os, const T& t, const Args&... args) {
  os << t;
  if (sizeof...(args)) os << " ";
  printr(os, args...);
}
template <class T>
void read(T& x) {
  cin >> x;
}
template <class T, class... Args>
void read(T& t, Args&... args) {
  read(t), read(args...);
}
template <class T>
void readarray(T* A, int n) {
  for (__typeof(0) i = (0), _end = (n), _step = 1 - 2 * ((0) > (n)); i != _end;
       i += _step)
    read(A[i]);
}
void dbgr(ostream& os) { os << endl; }
template <class T, class... Args>
void dbgr(ostream& os, const T& t, const Args&... args) {
  os << t;
  if (sizeof...(args)) os << ", ";
  dbgr(os, args...);
}
long long randll(long long a, long long b) {
  uniform_int_distribution<int> u(a, b);
  static mt19937 e(time(0));
  return u(e);
}
long long pw(long long a, long long k = 998244353 - 2) {
  long long ans = 1;
  for (a %= 998244353; k; k >>= 1) {
    if (k & 1) ans = ans * a % 998244353;
    a = a * a % 998244353;
  }
  return ans;
}
int n, p[1000050];
int dp[2][1000050][2];
pair<int, int> prt[2][1000050][2];
auto f = dp[0], g = dp[1];
auto pf = prt[0], pg = prt[1];
void chkmin(int& a, int b) { a = min(a, b); }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int _;
  read(_);
  while (_--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    for (int i = 1; i <= n; ++i)
      for (int c = 0; c <= 1; ++c) f[i][c] = g[i][c] = 1000050;
    f[1][0] = f[1][1] = -1000050;
    for (int i = 1; i < n; ++i)
      for (int c = 0; c <= 1; ++c) {
        int a = c ? -p[i] : p[i];
        for (int nc = 0; nc <= 1; ++nc) {
          int na = nc ? -p[i + 1] : p[i + 1];
          if (f[i][c] < na && na < a && g[i + 1][nc] > a)
            g[i + 1][nc] = a, pg[i + 1][nc] = make_pair(0, c);
          if (a < na && f[i + 1][nc] > f[i][c])
            f[i + 1][nc] = f[i][c], pf[i + 1][nc] = make_pair(0, c);
          if (a < na && na < g[i][c] && g[i + 1][nc] > g[i][c])
            g[i + 1][nc] = g[i][c], pg[i + 1][nc] = make_pair(1, c);
          if (g[i][c] < na && f[i + 1][nc] > a)
            f[i + 1][nc] = a, pf[i + 1][nc] = make_pair(1, c);
        }
      }
    int k = 0, c = 0;
    for (int x = 0; x <= 1; ++x)
      for (int y = 0; y <= 1; ++y)
        if (dp[x][n][y] <= n) k = x, c = y;
    if (dp[k][n][c] > n)
      cout << "NO" << endl;
    else {
      cout << "YES" << endl;
      function<void(int, int, int)> pr = [&](int k, int i, int c) {
        if (i > 1) pr(prt[k][i][c].first, i - 1, prt[k][i][c].second);
        cout << (c ? -p[i] : p[i]) << " \n"[i == n];
      };
      pr(k, n, c);
    }
  }
  return 0;
}
