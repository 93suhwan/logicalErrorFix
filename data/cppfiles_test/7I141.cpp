#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  while (b) swap(b, a %= b);
  return a;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<long long> d(n - 1);
    for (int i = 0; i < n - 1; ++i) d[i] = abs(a[i + 1] - a[i]);
    if (n == 1) {
      cout << "1\n";
      continue;
    }
    int x = 0, y = 0;
    long long v = d[x];
    int ans = 2;
    while (x < n - 1) {
      for (;;) {
        ++y;
        if (y == n - 1) break;
        v = gcd(v, d[y]);
        if (v == 1)
          break;
        else
          ans = max(ans, y - x + 2);
      }
      if (y == n - 1) break;
      x = y;
      v = d[x];
      for (;;) {
        v = gcd(v, d[--x]);
        if (v == 1)
          break;
        else
          ans = max(ans, y - x + 2);
      }
    }
    cout << ans << '\n';
  }
}
