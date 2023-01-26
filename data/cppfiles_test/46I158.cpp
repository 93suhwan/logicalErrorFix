#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
  long long ans = 0;
  for (long long i = 0; i < n; i += 2) {
    long long cd = 0;
    long long lmin = 1;
    for (long long j = i + 1; j < n; j += 2) {
      long long l = max((long long)0, v[i] - lmin + 1);
      long long r = v[j] - max((long long)0, cd);
      long long temp = min(l, r);
      ans += temp;
      cd = cd - v[j];
      lmin = max(lmin, -cd);
      if (cd + v[i] < 0) break;
      if (j + 1 < n) cd += v[j + 1];
    }
  }
  cout << ans << endl;
}
signed main() {
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
