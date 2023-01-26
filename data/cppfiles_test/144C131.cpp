#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e6 + 10;
inline void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int sz = n / m;
  int t2 = n - sz * m, t1 = m - t2;
  long long s = 0;
  while (k--) {
    for (int i = 0; i < t1 * sz; i++) {
      if (i % sz == 0) cout << sz << ' ';
      cout << (i + s) % n + 1 << ' ';
      if (i % sz == sz - 1) cout << '\n';
    }
    for (int i = t1 * sz; i < n; i++) {
      if ((i - t1 * sz) % (sz + 1) == 0) cout << sz + 1 << ' ';
      cout << (i + s) % n + 1 << ' ';
      if ((i - t1 * sz) % (sz + 1) == sz) cout << '\n';
    }
    s += t1 * sz;
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
