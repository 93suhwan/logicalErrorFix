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
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> a[i];
  cin >> second;
  multiset<long long> r, b;
  for (long long i = 0; i < n; i++)
    if (second[i] == 'B')
      b.insert(a[i]);
    else
      r.insert(a[i]);
  bool ok = 1, c = 0;
  for (long long i = 1; i < n + 1; i++) {
    if (*b.begin() == i) {
      b.erase(b.begin());
      continue;
    }
    auto it = r.upper_bound(i);
    if (it != r.begin()) {
      --it;
      r.erase(it);
      continue;
    }
    it = b.lower_bound(i);
    if (it != b.end()) {
      b.erase(it);
      continue;
    }
    ok = 0;
  }
  cout << (ok ? "YES\n" : "NO\n");
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
