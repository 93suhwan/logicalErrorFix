#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
int a[N], b[N];
void solve() {
  int n, m;
  cin >> n >> m;
  ll sum = 0;
  ll mi = 0, ma = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i], sum += a[i] - b[i] + m;
    ma += min(a[i], m);
    mi += max(0, m - b[i]);
  }
  if (sum <= 2 * mi) {
    cout << abs(sum - 2 * mi) << "\n";
    for (int i = 1; i <= n; i++) {
      int x = max(0, m - b[i]);
      int y = m - x;
      cout << x << " " << y << "\n";
    }
  } else if (sum >= 2 * ma) {
    cout << abs(sum - 2 * ma) << "\n";
    for (int i = 1; i <= n; i++) {
      int x = min(a[i], m);
      int y = m - x;
      cout << x << " " << y << "\n";
    }
  } else {
    if (sum & 1)
      cout << 1 << "\n";
    else
      cout << "0\n";
    ll k = sum / 2;
    k -= mi;
    vector<int> c(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      c[i] += max(0, m - b[i]);
    }
    for (int i = 1; i <= n; i++) {
      if (k <= 0) break;
      int sg = min(a[i], m) - max(0, m - b[i]);
      if (k >= sg) {
        k -= sg;
        c[i] = min(a[i], m);
      } else {
        c[i] += k;
        k = 0;
      }
    }
    for (int i = 1; i <= n; i++) {
      cout << c[i] << " " << m - c[i] << "\n";
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
