#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = n - 2; i >= 0; i--) {
      a[i] += a[i + 1];
    }
    vector<long long> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      if (i > 0) {
        b[i] += b[i - 1];
      }
    }
    if (n == 1) {
      cout << 0 << '\n';
      continue;
    }
    long long ans = min(a[1], b[n - 2]);
    for (int i = 1; i + 1 < n; i++) {
      ans = min(ans, max(a[i + 1], b[i - 1]));
    }
    cout << ans << '\n';
  }
  return 0;
}
