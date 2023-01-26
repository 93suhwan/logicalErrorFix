#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m, r, c, p, q, x, y;
  cin >> n >> m >> r >> c >> p >> q;
  x = p < r ? r - p + 2 * (n - r) : p - r;
  y = q < c ? c - q + 2 * (m - c) : q - c;
  cout << min(x, y) << '\n';
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
}
