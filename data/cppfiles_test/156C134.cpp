#include <bits/stdc++.h>
using namespace std;
void testcase() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n), b(n + 1);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  for (long long i = 1; i <= n; i++) {
    b[i] += b[i - 1];
    b[i] += a[i - 1];
  }
  long long ans = a[0] + n - 1;
  for (long long i = 0; i <= n - 1; i++) {
    long long sum = b[n - i] + a[0] * i;
    long long cnt = i;
    if (sum > k) {
      long long diff = sum - k;
      cnt += (diff + i) / (i + 1);
    }
    ans = min(ans, cnt);
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
