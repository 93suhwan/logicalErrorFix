#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  long long n;
  cin >> n;
  long long ans = cbrt(n);
  ans += sqrt(n);
  for (long long i = 1; i * i * i * i * i * i <= n; i++) ans--;
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) solve();
}
