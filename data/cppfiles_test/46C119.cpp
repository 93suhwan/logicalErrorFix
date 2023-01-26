#include <bits/stdc++.h>
using namespace std;
long long max(int a, long long b) { return a > b ? a : b; }
long long max(long long a, int b) { return a > b ? a : b; }
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
  long long ans = 0;
  for (long long i = 0; i < n; i += 2) {
    long long cd = 0;
    long long md = 0;
    for (long long j = i + 1; j < n; j += 2) {
      long long l = max(1, max(md, 1 - cd));
      long long r = min(v[i], v[j] - cd);
      ans += max(0, r - l + 1);
      cd -= v[j];
      md = max(md, -cd);
      if (j + 1 < n) cd += v[j + 1];
      md = max(md, -cd);
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
