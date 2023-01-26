#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long inf = 1e18 + 7;
const long long N = 3e5 + 5;
vector<long long> g[N];
void setIO(string second) {
  freopen((second + ".in").c_str(), "r", stdin);
  freopen((second + ".out").c_str(), "w", stdout);
}
struct mi {
  long long v;
  explicit operator long long() const { return v; }
  mi() { v = 0; }
  mi(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
mi &operator+=(mi &a, mi b) {
  if ((a.v += b.v) >= MOD) a.v -= MOD;
  return a;
}
mi &operator-=(mi &a, mi b) {
  if ((a.v -= b.v) < 0) a.v += MOD;
  return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long)a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }
mi pow(mi a, long long p) {
  assert(p >= 0);
  return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) {
  assert(a.v != 0);
  return pow(a, MOD - 2);
}
mi operator/(mi a, mi b) { return a * inv(b); }
template <typename T_vector>
void output_vector(const T_vector &v, bool add_one = false,
                   long long start = -1, long long end = -1) {
  if (start < 0) start = 0;
  if (end < 0) end = v.size();
  for (long long i = start; i < end; i++)
    cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}
void yes() {
  cout << "YES"
       << "\n";
  ;
}
void no() {
  cout << "NO"
       << "\n";
  ;
}
mi fact[N];
void pre() {
  fact[1] = (mi)1;
  fact[2] = (mi)1;
  for (long long i = 3; i < N; i++) {
    fact[i] = (fact[i - 1] * i);
  }
}
void solve_test_case() {
  long long n;
  cin >> n;
  cout << (long long)fact[2 * n] << "\n";
  ;
}
signed main() {
  long long t;
  cin >> t;
  pre();
  for (long long i = 1; i < t + 1; i++) {
    solve_test_case();
  }
  return 0;
}
