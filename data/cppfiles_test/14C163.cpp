#include <bits/stdc++.h>
using namespace std;
long long int dp[2003][2003];
long long int vec[2009];
long long int n;
long long int mid;
long long int call(long long int pos, long long int t) {
  if (pos == n) {
    return 0;
  }
  if (dp[pos][t] != -1) {
    return dp[pos][t];
  }
  long long int x, y, c;
  x = y = 0;
  if (t > 0) {
    x = call(pos + 1, t - 1);
  }
  c = (mid - t);
  if ((pos + 1 - c) == vec[pos]) {
    y = 1 + call(pos + 1, t);
  } else {
    y = call(pos + 1, t);
  }
  return dp[pos][t] = max(x, y);
}
int main() {
  long long int a, b, c, d, e, i, j, k, l, m, x, y, t, p, r;
  scanf("%lld", &t);
  for (p = 1; p <= t; p++) {
    scanf("%lld%lld", &n, &k);
    for (i = 0; i < n; i++) {
      scanf("%lld", &vec[i]);
    }
    l = 0;
    r = n;
    x = -1;
    while (l <= r) {
      for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
          dp[i][j] = -1;
        }
      }
      mid = (l + r) / 2;
      if (call(0, mid) >= k) {
        x = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    cout << x << endl;
  }
}
