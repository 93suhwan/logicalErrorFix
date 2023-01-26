#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int a[N];
void Solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  a[n] = INT_MAX;
  long long ans = 0;
  for (int i = 0; i <= n; i++)
    if (a[i] > 0) {
      int l = i % k, r = (n - i) % k;
      for (int j = i + r; j < n;) {
        j += k;
        ans += a[j - 1] * 2;
      }
      for (int j = i - 1 - l; j >= 0; j--) {
        j -= k;
        ans -= a[j + 1] * 2;
      }
      if (l) ans -= a[i - l] * 2;
      if (r) ans += a[i + r - 1] * 2;
      break;
    }
  cout << ans - max(abs(a[0]), abs(a[n - 1])) << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) Solve();
}
