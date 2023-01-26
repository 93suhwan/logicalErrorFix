#include <bits/stdc++.h>
using namespace std;
long long a[102];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  long long n, i, k, ans;
  while (t--) {
    cin >> n >> k;
    for (i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    ans = 0;
    for (i = 1; i <= n - 2 * k; i++) {
      ans += a[i];
    }
    for (i = n - 2 * k + 1; i < n - k + 1; i++) {
      ans = ans + (a[i] / a[i + k]);
    }
    cout << ans << "\n";
  }
  return 0;
}
