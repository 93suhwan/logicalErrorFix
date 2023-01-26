#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b, c, m;
  cin >> a >> b >> c >> m;
  int maxl = max(a - 1, 0) + max(b - 1, 0) + max(c - 1, 0);
  int maxv = max(a, max(b, c));
  int rest = a + b + c - maxv;
  int minl = max(0, maxv - rest - 1);
  if (maxl >= m and m >= minl) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) solve();
}
