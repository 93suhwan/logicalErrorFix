#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m, mx = 0, pos = 0, res = 0;
  cin >> n;
  long long ar[n];
  for (long long i = 0; i < n; i++) cin >> ar[i];
  for (long long i = 0; i < n; i++) {
    long long x = 0, y = 0;
    if (i > 0) x = ar[i] * ar[i - 1];
    if (i < n - 1) y = ar[i] * ar[i + 1];
    res = max({res, x, y});
  }
  cout << res << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1, cs = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
