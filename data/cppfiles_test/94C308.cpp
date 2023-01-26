#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
istream& operator>>(istream& in, pair<T, U>& a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T, typename U>
ostream& operator<<(ostream& out, pair<T, U> a) {
  out << '(' << a.first << ", " << a.second << ')';
  return out;
}
template <typename T>
ostream& operator<<(ostream& cout, vector<T> const& v) {
  cout << "[";
  for (long long i = 0; i < (long long)((v).size()); i++) {
    if (i) cout << ", ";
    cout << v[i];
  }
  return cout << "]";
}
template <typename T, typename U>
static inline void amin(T& x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static inline void amax(T& x, U y) {
  if (x < y) x = y;
}
const long double pi = 3.14159265358979323846;
const char nl = '\n';
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
const long long N = 1e6 + 5;
long long n, m, q, k, l, r, x, y, z, a[N], b[N], c[N];
string second, t;
void solve() {
  cin >> n >> k;
  vector<long long> pw(20);
  pw[0] = 1;
  for (long long i = 1; i < 20; i++) pw[i] = pw[i - 1] * 10;
  vector<long long> a(20), r(20);
  for (long long i = 0; i < n; i++) {
    cin >> x;
    a[x] = 1;
  }
  vector<long long> c(20);
  for (long long i = 0; i < 20; i++) {
    if (i) r[i] = r[i - 1];
    if (a[i]) r[i] = i;
    c[i] = pw[i - r[i]];
    if (i) c[i] += c[i - 1];
  }
  for (long long i = 0; i < 20; i++) {
    if (9 * c[i] <= k) continue;
    long long num = 0, cost = 0;
    for (long long j = i; j >= 0; j--) {
      for (long long h = 0; h < 10; h++) {
        if (cost + h * pw[j - r[j]] + (j ? c[j - 1] * 9 : 0) > k) {
          num += h * pw[j];
          cost += h * pw[j - r[j]];
          break;
        }
      }
    }
    cout << num << nl;
    return;
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
