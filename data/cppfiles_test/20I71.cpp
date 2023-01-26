#include <bits/stdc++.h>
using namespace std;
const long long N = 4e2 + 9;
const long long mod = 1000000007;
long long n, m, sum[N][N];
long long boxSum(long long l, long long r, long long u, long long d) {
  return sum[d][r] - sum[u - 1][r] - sum[d][l - 1] + sum[u - 1][l - 1];
}
long long boxSum0(long long l, long long r, long long u, long long d) {
  long long tot = (r - l + 1) * (d - u + 1);
  return tot - boxSum(l, r, u, d);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      string s;
      cin >> s;
      s.insert(s.begin(), 'a');
      for (int j = 1; j <= m; j++) {
        sum[i][j] =
            sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (s[j] - '0');
      }
    }
    long long preCost = (1LL << 61);
    long long ans = (1LL << 61);
    for (int l = 1; l <= m; l++) {
      for (int r = l + 3; r <= m; r++) {
        long long u = 1, d = 5;
        for (; d <= n; d++) {
          long long cost5 = boxSum(l + 1, r - 1, d - 4 + 1, d - 1);
          cost5 += boxSum0(l + 1, r - 1, d - 4, d - 4);
          cost5 += boxSum0(l + 1, r - 1, d, d);
          cost5 += boxSum0(l, l, d - 4 + 1, d - 1);
          cost5 += boxSum0(r, r, d - 4 + 1, d - 1);
          long long cost =
              preCost - boxSum0(l + 1, r - 1, d - 1, d - 1) +
              boxSum(l + 1, r - 1, d - 1, d - 1) + boxSum0(l, l, d - 1, d - 1) +
              boxSum0(r, r, d - 1, d - 1) + boxSum0(l + 1, r - 1, d, d);
          long long costNow = min(cost, cost5);
          ans = min(ans, costNow);
          preCost = costNow;
        }
      }
    }
    cout << ans << "\n";
  }
}
