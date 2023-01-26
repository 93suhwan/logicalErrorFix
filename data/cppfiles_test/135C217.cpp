#include <bits/stdc++.h>
const char nl = '\n';
using namespace std;
const long long INF = 1e18;
const int MM = 1e9 + 1;
const long long MOD = 1e9 + 7;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int l = 0, r = n - 1;
  int cnt = 0;
  long long ans = 0;
  for (int i = 0; i < k; i++) {
    ans += a[n - 2 * k + i] / a[n - k + i];
  }
  for (int i = 0; i < n - 2 * k; i++) {
    ans += a[i];
  }
  cout << ans << nl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
