#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int64_t sum = 0;
    vector<int> b(n);
    for (auto &x : b) cin >> x, sum += x;
    int d = n * (n + 1) / 2;
    if (sum % d) {
      cout << "NO\n";
      continue;
    }
    vector<int> a(n);
    b.emplace_back(b[0]);
    bool ok = true;
    int suma = sum / d;
    for (int i = 1; i <= n; ++i) {
      int res = suma - b[i] + b[i - 1];
      if (res <= 0 || res % n) {
        ok = false;
        break;
      }
      a[i % n] = res / n;
    }
    if (!ok) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (auto &x : a) cout << x << ' ';
    cout << '\n';
  }
}
