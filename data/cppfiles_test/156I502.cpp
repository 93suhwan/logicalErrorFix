#include <bits/stdc++.h>
using namespace std;
void testcase() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  long long sum = 0;
  for (long long i = 0; i < n; i++) cin >> a[i], sum += a[i];
  if (sum <= k) {
    cout << "0\n";
    return;
  }
  sort(a.begin(), a.end());
  vector<long long> b(n);
  b[0] = a.back();
  for (long long i = 1; i < n; i++) {
    b[i] += b[i - 1] + a[n - i - 1];
  }
  long long ans = a[0] + n - 1;
  for (long long d = 1; d <= 1e7; d++) {
    long long cur = sum - d;
    long long cnt = d;
    long long l = 0, r = n - 2;
    long long s = -1;
    while (l <= r) {
      long long m = (l + r) / 2;
      if (cur - b[m] + m * (a[0] - d) > k)
        l = m + 1;
      else
        r = m - 1, s = m + 1;
    }
    if (s != -1) ans = min(ans, cnt + s);
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) testcase();
  exit(EXIT_SUCCESS);
}
