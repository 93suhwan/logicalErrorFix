#include <bits/stdc++.h>
using namespace std;
int t;
int n;
long long a[200010], b[200010];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n == 1) {
      cout << a[1] << "\n";
      continue;
    }
    sort(a + 1, a + n + 1);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      ans = max(ans, a[i] - a[i - 1]);
    }
    cout << ans << "\n";
  }
  return 0;
}
