#include <bits/stdc++.h>
using namespace std;
long long n;
long long v[1010];
long long w[1010];
long long cnt;
int32_t main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> v[i];
  }
  long long ans = 0;
  for (long long i = 1; i < n; i += 2) {
    ans = ans + min(v[i], v[i + 1]);
  }
  for (long long i = 1; i < n; i += 2) {
    long long valmin = min(v[i], v[i + 1]);
    v[i] -= valmin;
    v[i + 1] -= valmin;
    if (v[i] != v[i + 1]) {
      w[++cnt] = v[i];
      w[++cnt] = v[i + 1];
    } else {
      w[++cnt] = 0;
    }
  }
  if (n % 2) w[++cnt] = v[n];
  long long sum = 0;
  for (long long i = 1; i <= cnt; i++) {
    sum += w[i];
  }
  if (sum == 0) {
    ans = ans + cnt * (cnt - 1) / 2;
    cout << ans << '\n';
    return 0;
  } else {
    for (long long i = 1; i < cnt; i++) {
      if (w[i]) {
        long long lg = i - 1;
        ans = ans + lg * (lg - 1) / 2;
        break;
      }
    }
    for (long long i = cnt; i >= 1; i--) {
      if (w[i]) {
        long long lg = cnt - i;
        ans = ans + lg * (lg - 1) / 2;
        break;
      }
    }
    for (long long i = 1; i < cnt; i++) {
      if (w[i] && i % 2 == 1) {
        for (long long j = i + 1; j <= cnt; j++) {
          if (w[j] && j % 2 == 0 && w[i]) {
            long long zero = j - i - 1;
            ans += zero * (zero - 1) / 2;
            long long valmin = min(w[i], w[j]);
            w[i] -= valmin;
            w[j] -= valmin;
            ans += valmin;
          }
        }
      }
    }
    cout << ans << '\n';
    return 0;
  }
}
