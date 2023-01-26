#include <bits/stdc++.h>
using namespace std;
long long n, v[200005], k, sum[200005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long ans = LLONG_MAX;
    cin >> n >> k;
    for (long long i = 1; i <= n; i++) {
      cin >> v[i];
      sum[i] = 0;
    }
    sort(v + 1, v + n + 1);
    long long val = min(v[1], k / n);
    long long nr_scaderi = max(0LL, v[1] - k / n);
    for (long long i = 2; i <= n; i++) sum[i] += sum[i - 1] + v[i];
    long long ok = 1;
    while (ok == 1) {
      long long left = 1, right = n;
      while (left <= right) {
        long long mijl = (left + right) / 2;
        if (sum[mijl] + val * (n - mijl + 1) <= k) {
          ans = min(ans, n - mijl + nr_scaderi);
          left = mijl + 1;
        } else
          right = mijl - 1;
      }
      if (sum[n] + nr_scaderi <= k) ans = min(ans, nr_scaderi);
      nr_scaderi++;
      val--;
      if (ans < nr_scaderi) ok = 0;
    }
    cout << ans << '\n';
  }
  return 0;
}
