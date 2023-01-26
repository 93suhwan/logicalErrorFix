#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 5;
void solve(long long t) {
  long long n, k;
  cin >> n >> k;
  vector<long long> v(n + 1);
  for (long long i = 1; i <= n; i++) cin >> v[i];
  long long ans = INT_MIN;
  for (long long i = max(1LL, (n - 2 * k)); i <= n; i++) {
    for (long long j = i + 1; j <= n; j++) {
      ans = max(ans, i * j - k * (v[i] | v[j]));
    }
  }
  cout << ans << endl;
}
signed main() {
  long long T = 1;
  cin >> T;
  for (long long t = 1; t <= T; t++) {
    solve(t);
  }
  return 0;
}
