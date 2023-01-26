#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == i + 1) {
    } else {
      long long x = i + 1;
      if (a[i] - x > 0 && (a[i]) % (a[i] - x) == i + 1) {
        ans++;
      } else {
        cout << -1 << endl;
        return;
      }
    }
  }
  cout << ans << endl;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
