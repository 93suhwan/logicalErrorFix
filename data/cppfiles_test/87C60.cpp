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
  long long idx = 1;
  for (long long i = 1; i <= n; i++) {
    if (a[i] - idx > 0) {
      ans += a[i] - idx;
      idx = a[i] + 1;
    } else {
      idx++;
    }
  }
  cout << ans << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
}
