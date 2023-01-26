#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  long long ans = LONG_MAX;
  for (int i = 0; i < n; i++) {
    ans = min(ans, (a[i] & ans));
  }
  cout << ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
