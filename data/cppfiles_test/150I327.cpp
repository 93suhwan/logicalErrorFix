#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long long maxu = 200005;
void google(long long t) { cout << "Case #" << t << ": "; }
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long fun(long long a, long long b) {
  if (b == 0)
    return 1;
  else if (a == 1)
    return 1;
  long long temp = fun(a, b / 2) % 1000000007;
  temp = (temp * temp) % 1000000007;
  if (b % 2 == 1) temp = (temp * a) % 1000000007;
  return temp % 1000000007;
}
long long inv(long long a, long long b) {
  return (a * fun(b, 1000000007 - 2)) % 1000000007;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long i, j, k = 0, n, m, l = 0;
  long long t = 1;
  long long T = 1;
  cin >> T;
  for (t = 1; t <= T; t++) {
    cin >> n;
    long long a[n];
    long long maxi = 0;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      maxi = max(maxi, a[i]);
    }
    long long c3max = (maxi / 3) + 3;
    long long ans = inf;
    for (long long c1 = 0; c1 <= 4; c1++) {
      for (long long c2 = 0; c2 <= 4; c2++) {
        for (long long c3 = 0; c3 <= c3max; c3++) {
          long long cnt = c1 + c2 + c3;
          if (cnt >= ans) continue;
          long long can = 1;
          for (i = 0; i < n; i++) {
            long long can2 = 0;
            for (j = 0; j <= c1; j++) {
              for (k = 0; k <= c2; k++) {
                long long x = a[i] - j - k * 2;
                if (x == 0) {
                  can2 = 1;
                  continue;
                }
                if ((x % 3 == 0) && (x <= 3 * c3)) {
                  can2 = 1;
                }
              }
            }
            if (can2 == 0) {
              can = 0;
              break;
            }
          }
          if (can) ans = cnt;
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
