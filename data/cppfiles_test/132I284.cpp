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
  long long cnt = 1;
  if (a[0] == a[1]) cnt++;
  for (long long i = 0; i < (7); i++) {
    if (i == 0)
      cout << a[i] << ' ';
    else if (i == 1)
      cout << a[i] << ' ';
    else if (a[i] != a[1] + a[0]) {
      cout << a[i] << '\n';
      return;
    } else if (a[i] == a[1] + a[0] && cnt)
      cnt--;
    else if (!cnt) {
      cout << a[i] << '\n';
      return;
    }
  }
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
