#include <bits/stdc++.h>
using namespace std;
long long n, h;
long long a[105];
int f(long long k) {
  long long dmg = 0;
  for (int i = 0; i < n - 1; i++) {
    dmg += min(k, a[i + 1] - a[i]);
  }
  dmg += k;
  if (dmg >= h) return 1;
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(8) << fixed;
  int tt = 1;
  cin >> tt;
  while (tt--) {
    cin >> n >> h;
    long long l = 1, r = h;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    while (l < r) {
      long long mid = (l + r) / 2;
      if (f(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    cout << l << "\n";
  }
}
