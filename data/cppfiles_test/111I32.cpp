#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ", ";
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T& x) {
  int first = 0;
  cerr << '{';
  for (auto& i : x) cerr << (first++ ? ", " : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const int MOD = 998244353;
const char nl = '\n';
const int MX = 100001;
struct mi {
  long long v;
  explicit operator long long() const { return v; }
  mi() { v = 0; }
  mi(long long _v) {
    v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
    if (v < 0) v += MOD;
  }
  friend bool operator==(const mi& a, const mi& b) { return a.v == b.v; }
  friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }
  friend bool operator<(const mi& a, const mi& b) { return a.v < b.v; }
  mi& operator+=(const mi& m) {
    if ((v += m.v) >= MOD) v -= MOD;
    return *this;
  }
  mi& operator-=(const mi& m) {
    if ((v -= m.v) < 0) v += MOD;
    return *this;
  }
  mi& operator*=(const mi& m) {
    v = v * m.v % MOD;
    return *this;
  }
  mi& operator/=(const mi& m) { return (*this) *= inv(m); }
  friend mi pow(mi a, long long p) {
    mi ans = 1;
    assert(p >= 0);
    for (; p; p /= 2, a *= a)
      if (p & 1) ans *= a;
    return ans;
  }
  friend mi inv(const mi& a) {
    assert(a.v != 0);
    return pow(a, MOD - 2);
  }
  mi operator-() const { return mi(-v); }
  mi& operator++() { return *this += 1; }
  mi& operator--() { return *this -= 1; }
  mi operator++(int) {
    v++;
    if (v == MOD) v = 0;
    return mi(v);
  }
  mi operator--(int) {
    v--;
    if (v < 0) v = MOD - 1;
    return mi(v);
  }
  friend mi operator+(mi a, const mi& b) { return a += b; }
  friend mi operator-(mi a, const mi& b) { return a -= b; }
  friend mi operator*(mi a, const mi& b) { return a *= b; }
  friend mi operator/(mi a, const mi& b) { return a /= b; }
  friend ostream& operator<<(ostream& os, const mi& m) {
    os << m.v;
    return os;
  }
  friend istream& operator>>(istream& is, mi& m) {
    long long x;
    is >> x;
    m.v = x;
    return is;
  }
};
void __print(mi X) { cout << X.v; }
mi facs[MX];
mi facInvs[MX];
mi choose(mi _a, mi _b) {
  long long a = (long long)_a, b = (long long)_b;
  if (b > a) return 0;
  if (a < 0) return 0;
  if (b < 0) return 0;
  mi cur = facs[a];
  cur = cur * facInvs[b];
  cur = cur * facInvs[a - b];
  return cur;
}
void initFacs() {
  facs[0] = 1;
  for (int i = 1; i < (MX); i++) {
    facs[i] = (facs[i - 1] * i);
  }
  facInvs[MX - 1] = inv(facs[MX - 1]);
  for (int i = (MX - 1) - 1; i >= 0; i--) {
    facInvs[i] = facInvs[i + 1] * (i + 1);
  }
}
void solve() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N + 1);
  for (int i = 1; i < (N + 1); i++) cin >> A[i];
  for (int i = 1; i < (N + 1); i++) A[i] -= K;
  A[0] = 0;
  K = 2 * K + 1;
  mi cur[N + 1][K];
  cur[0][0] = 1;
  mi nxt[N + 1][K];
  for (int i = 0; i < (N); i++) {
    for (int j = 0; j < (N + 1); j++)
      for (int k = 0; k < (K); k++) nxt[j][k] = 0;
    for (int j = 0; j < (N + 1); j++) {
      for (int k = 0; k < (K); k++) {
        int curMex = A[i] + k;
        int ni = curMex - A[i + 1] + 1;
        if (ni >= K) continue;
        mi mul = 1;
        int nj = j;
        if (ni < 0) {
          ni *= -1;
          if (j < ni) continue;
          mul = choose(j, ni) * facs[ni];
          nj -= ni;
          ni = 0;
        }
        nxt[nj][ni] += cur[j][k] * mul;
      }
    }
    for (int j = 1; j < (N + 1); j++) {
      for (int k = 0; k < (K - 1); k++) {
        nxt[j - 1][k + 1] += nxt[j][k] * j;
      }
    }
    for (int j = 0; j < (N + 1); j++) {
      for (int k = 0; k < (K); k++) {
        int curMex = A[i] + k;
        int ni = curMex - A[i + 1];
        if (ni < 0 || ni >= K) continue;
        nxt[j][ni] += cur[j][k] * (curMex + j);
        if (j < N) nxt[j + 1][ni] += cur[j][k];
      }
    }
    for (int j = 0; j < (N + 1); j++)
      for (int k = 0; k < (K); k++) cur[j][k] = nxt[j][k];
  }
  mi ans = 0;
  for (int i = 0; i < (N + 1); i++) {
    for (int j = 0; j < (K); j++) {
      int mex = A[N] + j;
      int remSlots = N - mex;
      if (i > remSlots || remSlots < 0) continue;
      ans += choose(remSlots, i) * cur[i][j] * facs[i];
    }
  }
  cout << ans << nl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  initFacs();
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
