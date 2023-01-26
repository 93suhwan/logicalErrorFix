#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 2100;
long long dp_left[N][2 * N + 1];
long long dp_right[N][2 * N + 1];
void add_mod(long long &a, long long b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    for (long long i = 0; i < n; i += 2) {
      if (a[i] == '0') {
        a[i] = '1';
      } else if (a[i] == '1') {
        a[i] = '0';
      }
      if (b[i] == '0') {
        b[i] = '1';
      } else if (b[i] == '1') {
        b[i] = '0';
      }
    }
    for (long long i = 0; i <= n; i++) {
      for (long long j = 0; j <= 2 * n; j++) {
        dp_left[i][j] = dp_right[i][j] = 0;
      }
    }
    dp_left[0][n] = 1;
    dp_right[n][n] = 1;
    for (long long i = 1; i <= n; i++) {
      for (long long first = 0; first < 2; first++) {
        if (a[i - 1] != '?' && a[i - 1] - '0' != first) {
          continue;
        }
        for (long long second = 0; second < 2; second++) {
          if (b[i - 1] != '?' && b[i - 1] - '0' != second) {
            continue;
          }
          long long add = first - second;
          for (long long bal = 0; bal <= 2 * n; bal++) {
            if (bal + add < 0 || bal + add > 2 * n) {
              continue;
            }
            add_mod(dp_left[i][bal + add], dp_left[i - 1][bal]);
          }
        }
      }
    }
    for (long long i = n - 1; i >= 0; i--) {
      for (long long first = 0; first < 2; first++) {
        if (a[i] != '?' && a[i] - '0' != first) {
          continue;
        }
        for (long long second = 0; second < 2; second++) {
          if (b[i] != '?' && b[i] - '0' != second) {
            continue;
          }
          long long add = first - second;
          for (long long bal = 0; bal <= 2 * n; bal++) {
            if (bal + add < 0 || bal + add > 2 * n) {
              continue;
            }
            add_mod(dp_right[i][bal + add], dp_right[i + 1][bal]);
          }
        }
      }
    }
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j <= 2 * n; j++) {
        add_mod(ans, 1LL * abs(j - n) * dp_left[i][j] % mod *
                         dp_right[i][2 * n - j] % mod);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
