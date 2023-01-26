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
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 2001;
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
    mi temp;
    temp.v = v++;
    return temp;
  }
  mi operator--(int) {
    mi temp;
    temp.v = v--;
    return temp;
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
mi cnt[MX][MX][2];
mi val[MX][MX][2];
void solve() {
  int N;
  cin >> N;
  string S, T;
  cin >> S >> T;
  for (int i = 0; i < (N + 1); i++)
    for (int j = 0; j < (N + 1); j++)
      for (int k = 0; k < (2); k++) {
        cnt[i][j][k] = 0;
        val[i][j][k] = 0;
      }
  cnt[0][0][0] = 1;
  for (int i = 0; i < (N); i++) {
    for (int t = 0; t < (2); t++) {
      for (int j = 0; j < (i + 1); j++) {
        for (int a = 0; a < (2); a++) {
          for (int b = 0; b < (2); b++) {
            if (S[i] == (1 - a) + '0') continue;
            if (T[i] == (1 - b) + '0') continue;
            if (a == b) {
              cnt[i + 1][j][t] += cnt[i][j][t];
              val[i + 1][j][t] += val[i][j][t] + j * cnt[i][j][t];
            } else {
              int ct = 0;
              if (a == i % 2) ct = 1;
              int nj, nt;
              if (j == 0) {
                nj = 1;
                nt = ct;
              } else if (ct == t) {
                nj = j + 1;
                nt = t;
              } else {
                nj = j - 1;
                nt = t;
              }
              cnt[i + 1][nj][nt] += cnt[i][j][t];
              val[i + 1][nj][nt] += val[i][j][t] + j * cnt[i][j][t];
            }
          }
        }
      }
    }
  }
  cout << val[N][0][0] + val[N][0][1] << nl;
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
