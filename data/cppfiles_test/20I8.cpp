#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long sum[401][401];
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long solve1(long long l1, long long r1, long long l2, long long r2) {
  return sum[l2][r2] - sum[l1 - 1][r2] - sum[l2][r1 - 1] + sum[l1 - 1][r1 - 1];
}
long long solve0(long long l1, long long r1, long long l2, long long r2) {
  return (r2 - r1 + 1) * (l2 - l1 + 1) - solve1(l1, r1, l2, r2);
}
int32_t main() {
  long long T;
  cin >> T;
  while (T--) {
    long long n, m, ans = 1e9 + 7;
    cin >> n >> m;
    for (long long i = 0; i <= 400; i++) {
      for (long long j = 0; j <= 400; j++) {
        sum[i][j] = 0;
      }
    }
    for (long long i = 1; i <= n; i++) {
      string s;
      cin >> s;
      for (long long j = 1; j <= m; j++) {
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] +
                    (s[j - 1] == '1');
      }
    }
    for (long long i = 1; i <= n; i++) {
      for (long long j = i + 4; j <= n; j++) {
        long long cur_min, prev_min;
        cur_min = prev_min = INT_MAX;
        for (long long k = 4; k <= m; k++) {
          long long last_4_cost =
              solve1(i + 1, k - 2, j - 1, k - 1) + solve0(i, k - 2, i, k - 1) +
              solve0(j, k - 2, j, k - 1) + solve0(i + 1, k - 3, j - 1, k - 3) +
              solve0(i + 1, k, j - 1, k);
          long long last_col_cost = solve0(i + 1, k, j - 1, k);
          long long prev_cost =
              prev_min + last_col_cost + solve1(i + 1, k - 1, j - 1, k - 1) -
              solve0(i + 1, k - 1, j - 1, k - 1) + solve0(i, k - 1, i, k - 1) +
              solve0(j, k - 1, j, k - 1);
          cur_min = min(last_4_cost, prev_cost);
          ans = min(ans, cur_min);
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
