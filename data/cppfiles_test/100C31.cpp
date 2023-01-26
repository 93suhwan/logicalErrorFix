#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  long long ans = a[0];
  long long change = a[0];
  for (int i = 1; i < n; ++i) {
    ans = max(ans, a[i] - change);
    change += a[i] - change;
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) solve();
  return 0;
}
