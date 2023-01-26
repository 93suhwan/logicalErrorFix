#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
const long long N = 2e5 + 1, mod = 1e9 + 7;
void solve() {
  long long n, k;
  cin >> n >> k;
  k++;
  vector<long long> a(n);
  for (long long i = 0; i < n; i += 1) {
    cin >> a[i];
  }
  long long sum = 0, ans = 0;
  for (long long i = 1; i < n; i += 1) {
    long long p = pow(10, a[i] - a[i - 1]) - 1;
    if (sum + p < k) {
      sum += p;
      ans += p * pow(10, a[i - 1]);
    } else {
      ans += (k - sum) * pow(10, a[i - 1]);
      cout << ans << "\n";
      return;
    }
  }
  cout << (k - sum);
  if (n > 1) cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
