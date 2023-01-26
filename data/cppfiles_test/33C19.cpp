#include <bits/stdc++.h>
using namespace std;
int t, k;
long long solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  vector<long long> ans(1002, 502);
  ans[0] = -1;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < 1002; j++) {
      if (ans[j] < a[i]) {
        long long k = j ^ a[i];
        ans[k] = min(ans[k], a[i]);
      }
    }
  }
  long long c = 0;
  for (long long j = 0; j < 1002; j++) c += (ans[j] < 501);
  cout << c << endl;
  for (long long j = 0; j < 1002; j++) {
    if ((ans[j] < 501)) cout << j << " ";
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
