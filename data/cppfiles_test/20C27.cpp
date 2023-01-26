#include <bits/stdc++.h>
using namespace std;
long long int fact[100010], fact_inv[100010];
long long int power(long long int x, long long int y, long long int m) {
  if (y == 0) return 1;
  long long int a = power(x, y / 2, m);
  if (y % 2) {
    return (a * ((a * x) % m)) % m;
  } else {
    return (a * a) % m;
  }
}
long long int mod_inverse(long long int x, long long int m) {
  return power(x, m - 2, m);
}
long long int ncr(long long int n, long long int r, long long int m) {
  if (r > n || r < 0) return 0;
  if (n < 0) return 0;
  long long int n1 = 1, d1 = 1, d2 = 1;
  n1 = fact[n];
  d1 = fact_inv[r];
  d2 = fact_inv[n - r];
  long long int ans = (d1 * d2) % m;
  ans = (ans * n1) % m;
  return ans;
}
void pre_compute() {
  int mx = 100001;
  fact[0] = 1ll;
  for (int i = 1; i <= mx; ++i) {
    fact[i] = (fact[i - 1] * ((long long int)i)) % (long long int)1000000007ll;
  }
  for (int i = 0; i <= mx; ++i) {
    fact_inv[i] = mod_inverse(fact[i], (long long int)1000000007ll);
  }
}
class solver {
 public:
  void solve() {
    int n, m;
    cin >> n >> m;
    int a[n + 2][m + 2];
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; ++i) {
      string s;
      cin >> s;
      for (int j = 1; j <= m; ++j) {
        a[i][j] = int(s[j - 1]) - int('0');
      }
    }
    int sum[n + 2][m + 2];
    memset(sum, 0, sizeof(sum));
    for (int j = 1; j <= m; ++j) {
      for (int i = 1; i <= n; ++i) {
        sum[i][j] = sum[i - 1][j] + a[i][j];
      }
    }
    int ans = 10000;
    for (int i1 = 1; i1 <= n; ++i1)
      for (int i2 = i1 + 4; i2 <= n; ++i2) {
        int sm[m + 1];
        for (int i = 1; i <= m; ++i) sm[i] = sum[i2][i] - sum[i1 - 1][i];
        int dp[m + 2], res = 10000;
        dp[m + 1] = 10000;
        for (int j = m; j > 0; --j) {
          if (j <= m - 3) {
            int tm = (i2 - i1 + 1) - sm[j];
            if (a[i1][j] == 0) tm--;
            if (a[i2][j] == 0) tm--;
            for (int t = j + 1; t <= j + 2; ++t) {
              tm += sm[t];
              if (a[i1][t] == 1)
                tm--;
              else
                tm++;
              if (a[i2][t] == 1)
                tm--;
              else
                tm++;
            }
            tm += dp[j + 3];
            res = min(res, tm);
            ans = min(ans, res);
          }
          int tm = (i2 - i1 + 1) - sm[j];
          if (a[i1][j] == 0) tm--;
          if (a[i2][j] == 0) tm--;
          dp[j] = tm;
          tm = sm[j];
          if (a[i1][j] == 1)
            tm--;
          else
            tm++;
          if (a[i2][j] == 1)
            tm--;
          else
            tm++;
          tm += dp[j + 1];
          dp[j] = min(tm, dp[j]);
        }
      }
    cout << ans << '\n';
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test = 1;
  cin >> test;
  while (test--) {
    solver o;
    o.solve();
  }
}
