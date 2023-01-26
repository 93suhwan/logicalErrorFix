#include <bits/stdc++.h>
using namespace std;
template <typename X>
inline X abs(const X& a) {
  return a < 0 ? -a : a;
}
template <typename X>
inline X sqr(const X& a) {
  return a * a;
}
using namespace std;
const long long INF = 1000 * 1000 * 1000;
const long long EPS = 1e-9;
const long long PI = acos(-1.0);
inline void solve() {
  string s;
  cin >> s;
  long long t1 = 0, t2 = 0;
  long long n = s.length();
  for (long long i = (0); i < (n); i++) {
    if (i % 2 == 0) {
      if (s[i] == '1') {
        ++t1;
      } else if (s[i] == '?') {
        if (t1 >= t2) {
          ++t1;
        }
      }
      if (t1 > t2) {
        if ((n - i) / 2 + t2 < t1) {
          cout << i + 1 << '\n';
          return;
        }
      } else if (t1 < t2) {
        if ((n - i - 1) / 2 + t1 < t2) {
          cout << i + 1 << '\n';
          return;
        }
      }
    } else {
      if (s[i] == '1') {
        ++t2;
      } else if (s[i] == '?') {
        if (t2 >= t1) {
          ++t2;
        }
      }
      if (t1 > t2) {
        if ((n - i) / 2 + t2 < t1) {
          cout << i + 1 << '\n';
          return;
        }
      } else if (t1 < t2) {
        if ((n - i) / 2 + t1 < t2) {
          cout << i + 1 << '\n';
          return;
        }
      }
    }
  }
  cout << 10 << '\n';
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cerr << setprecision(10) << fixed;
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
