#include <bits/stdc++.h>
using namespace std;
inline void USACO(string filename) {
  freopen((filename + ".in").c_str(), "r", stdin);
  freopen((filename + ".out").c_str(), "w", stdout);
}
void debug() { cout << endl; }
template <class T, class... U>
void debug(T a, U... b) {
  cout << a << " ";
  debug(b...);
}
const long long INF = 1e9 + 7;
const double eps = 1e-7;
const long long N = 8e2 + 9;
void solve() {
  vector<long long> a(7);
  for (long long i = 0; i < (7); i++) cin >> a[i];
  cout << a[0] << ' ' << a[1] << ' ';
  if (a[0] == a[1]) {
    if (a[2] != a[0] + a[1])
      cout << a[2] << '\n';
    else if (a[3] != a[0] + a[1])
      cout << a[3] << '\n';
    else
      cout << a[4] << '\n';
  } else {
    cout << (a[2] == a[0] + a[1] ? a[3] : a[2]) << '\n';
  }
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(4);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
