#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m;
  cin >> n >> m;
  long long a[n][2];
  long long s1 = 0, s2 = 0;
  long long sl = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1];
    s1 += a[i][0], s2 += a[i][1];
  }
  long long low = 0, high = 0;
  long long dp[n][2];
  for (long long i = 0; i < n; i++) {
    long long f = a[i][0], s = a[i][1];
    long long l = min(m, s);
    low += m - l;
    high += min(m, f);
    sl += m - l;
  }
  long long low1 = 0, high1 = 0;
  for (long long i = n - 1; i >= 0; i--) {
    long long f = a[i][0], s = a[i][1];
    long long l = min(m, s);
    low1 += m - l;
    high1 += min(m, f);
    dp[i][0] = low1, dp[i][1] = high1;
  }
  long long x = s1 - s2 + m * n;
  if (x <= 0) {
    x = low;
  } else {
    x /= 2;
    if (x < low)
      x = low;
    else if (x > high)
      x = high;
  }
  cout << abs(s1 - s2 - 2 * x + m * n) << "\n";
  x = x - sl;
  for (long long i = 0; i < n; i++) {
    long long x1 = min(a[i][1], m);
    x1 = m - x1;
    long long x2 = min(m, a[i][0]);
    long long j = x2 - x1;
    if (j >= x) {
      cout << x1 + x << " " << m - x1 - x << "\n";
      x = 0;
    } else {
      cout << x1 + j << " " << m - x1 - j << "\n";
      x -= j;
    }
  }
  cout << "\n";
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
