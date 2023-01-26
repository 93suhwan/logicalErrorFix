#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m, a, b, c, d;
  cin >> n >> m >> a >> b >> c >> d;
  long long i, j;
  if (c == a || b == d) {
    cout << "0\n";
    return;
  }
  if (c > a) {
    i = c - a;
  } else {
    i = (n - a) * 2 + a - c;
  }
  if (d > b) {
    j = d - b;
  } else {
    j = (m - b) * 2 + b - d;
  }
  cout << min(i, j) << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
