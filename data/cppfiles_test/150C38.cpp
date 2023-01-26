#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int maxu = 200005;
void google(int t) { cout << "Case #" << t << ": "; }
int gcd(int a, int b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
int fun(int a, int b) {
  if (b == 0)
    return 1;
  else if (a == 1)
    return 1;
  int temp = fun(a, b / 2) % 1000000007;
  temp = (temp * temp) % 1000000007;
  if (b % 2 == 1) temp = (temp * a) % 1000000007;
  return temp % 1000000007;
}
int inv(int a, int b) { return (a * fun(b, 1000000007 - 2)) % 1000000007; }
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int i, j, k = 0, n, m, l = 0;
  int t = 1;
  int T = 1;
  cin >> T;
  for (t = 1; t <= T; t++) {
    cin >> n;
    int a[n];
    int maxi = 0;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      maxi = max(maxi, a[i]);
    }
    int c3max = (maxi / 3) + 3;
    int ans = inf;
    for (int c1 = 0; c1 <= 4; c1++) {
      for (int c2 = 0; c2 <= 4; c2++) {
        for (int c3 = max(0, c3max - 6); c3 <= c3max; c3++) {
          int cnt = c1 + c2 + c3;
          if (cnt >= ans) continue;
          int can = 1;
          for (i = 0; i < n; i++) {
            int can2 = 0;
            for (j = 0; j <= c1; j++) {
              for (k = 0; k <= c2; k++) {
                int x = a[i] - j - k * 2;
                if (x == 0) {
                  can2 = 1;
                  break;
                }
                if (x < 0) continue;
                if ((x % 3 == 0) && (x <= 3 * c3)) {
                  can2 = 1;
                  break;
                }
              }
              if (can2 == 1) break;
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
