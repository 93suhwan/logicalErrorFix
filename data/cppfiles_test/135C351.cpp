#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long a[n];
    long long d = k;
    long long f = k;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    long long score = 0, score1 = 0;
    long long i = 0;
    while (k--) {
      score += a[i] / a[n - i - 1];
      i++;
    }
    if (i > 0) i--;
    for (long long j = d; j < n - d; j++) {
      score += a[j];
    }
    long long l = 0;
    while (d--) {
      score1 += a[n - f - l - 1] / a[n - l - 1];
      l++;
    }
    for (long long j = 0; j < n - 2 * f; j++) {
      score1 += a[j];
    }
    cout << score1 << endl;
  }
}
