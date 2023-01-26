#include <bits/stdc++.h>
using namespace std;
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
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
long long mod1 = 1000000007;
const long long INF = 1e18;
const long double pi = 3.14159265358979323846;
long long n, m, k, q, l, r, x, y, z;
const long long template_array_size = 200005;
long long a[template_array_size];
long long b[template_array_size];
long long c[template_array_size];
string s, t;
long long ans = 0;
template <class T>
bool ckmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
int solve() {
  cin >> n;
  for (int i = 0; i < (int)(n); ++i) cin >> b[i];
  for (int i = 0; i < min(n, 1000LL); i++) {
    bool ok = true;
    for (int j = 2; j <= min(1000, i + 2); j++) {
      if (b[i] % j != 0) ok = false;
    }
    if (ok) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  q = 1;
  cin >> q;
  while (q--) {
    solve();
  }
  return 0;
}
