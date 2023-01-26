#include <bits/stdc++.h>
using namespace std;
const long long N = 4e2 + 9;
const long long mod = 1000000007;
long long n, m, sum[N][N];
long long boxSum(long long l, long long r, long long u, long long d) {
  return sum[d][r] - sum[u - 1][r] - sum[d][l - 1] + sum[u - 1][l - 1];
}
int main() {
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
    vector<long long> costs;
    long long ans = (1LL << 61);
    for (int l = 1; l <= m; l++) {
      for (int r = l + 3; r <= m; r++) {
        long long u = 1, d = 5;
        for (; d <= n; d++) {
          long long cost = boxSum(l + 1, r - 1, u + 1, d - 1);
          cost += r - l - 1 - boxSum(l + 1, r - 1, u, u);
          cost += r - l - 1 - boxSum(l + 1, r - 1, d, d);
          cost += d - u - 1 - boxSum(l, l, u + 1, d - 1);
          cost += d - u - 1 - boxSum(r, r, u + 1, d - 1);
          long long cost2 = boxSum(l + 1, r - 1, u + 1 + 1, d - 1);
          cost2 += r - l - 1 - boxSum(l + 1, r - 1, u + 1, u + 1);
          cost2 += r - l - 1 - boxSum(l + 1, r - 1, d, d);
          cost2 += d - u - 1 - 1 - boxSum(l, l, u + 1 + 1, d - 1);
          cost2 += d - u - 1 - 1 - boxSum(r, r, u + 1 + 1, d - 1);
          if (cost2 < cost && d - u > 4) {
            u++;
            costs.push_back(cost2);
            ans = min(ans, cost2);
          } else
            ans = min(ans, cost);
        }
      }
    }
    cout << ans << "\n";
  }
}
