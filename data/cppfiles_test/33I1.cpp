#include <bits/stdc++.h>
using namespace std;
int t, k;
long long solve() {
  long long n;
  cin >> n;
  vector<long long> a(n + 1);
  for (long long i = 1; i < 1 + n; i++) cin >> a[i];
  vector<long long> ans(1001, n + 1);
  long long c = 0;
  ans[0] = 0;
  for (long long i = 1; i < 1 + n; i++) {
    for (long long j = 0; j < 1001; j++) {
      if (ans[j] > n) continue;
      if (a[ans[j]] < a[i]) {
        long long k = j ^ a[i];
        ans[k] = min(i, ans[k]);
      }
    }
  }
  for (long long i = 0; i < 1001; i++) c += (ans[i] <= n);
  cout << c << endl;
  for (long long i = 0; i < 1001; i++) {
    if (ans[i] <= n) cout << i << " ";
  }
  return 1;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  t = 1;
  for (; t--; cout << endl) {
    solve();
  }
  return 0;
}
