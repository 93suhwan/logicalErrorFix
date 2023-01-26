#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& a) {
  in >> a.fr >> a.sc;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> a) {
  out << a.fr << " " << a.sc;
  return out;
}
template <typename T, typename T1>
T amax(T& a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T& a, T1 b) {
  if (b < a) a = b;
  return a;
}
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
const long long N = 1e9 + 7;
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long x = (n * (n - 1)) / 2;
  if (n == 1) {
    if (k <= 1 || m > 0) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  } else if (n == 2) {
    if (m == 0) {
      cout << "NO\n";
    } else if (k <= 2 || m > 1) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  } else if (m < n - 1 || m > x) {
    cout << "NO\n";
  } else {
    if (m >= n - 1 && m < x) {
      if (k - 1 > 2) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    } else {
      if (k - 1 > 1) {
        cout << "YES\n";
      } else {
        cout << " NO\n";
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
