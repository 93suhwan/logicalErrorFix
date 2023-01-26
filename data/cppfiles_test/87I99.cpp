#include <bits/stdc++.h>
using namespace std;
long long n;
const long long N = 110;
long long a[N];
void solve() {
  cin >> n;
  long long sum = 0;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  a[0] = 0;
  long long num = 0;
  for (long long i = 1; i <= n; i++) {
    if (a[i] - a[i - 1] > 1) {
      ans += a[i] - a[i - 1] - 1;
    }
  }
  cout << ans << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
}
