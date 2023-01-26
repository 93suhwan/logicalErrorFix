#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long c = 0;
  for (long long i = 0; i < n; i++) {
    long long a;
    cin >> a;
    c += a;
  }
  long long k = c / n;
  long long ans;
  if (c % n != 0) {
    ans = 1;
  } else
    ans = 0;
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
