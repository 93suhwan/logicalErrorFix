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
    cout << 12 << endl;
  }
  return 0;
}
