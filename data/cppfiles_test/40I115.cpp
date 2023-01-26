#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 1000;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
long long a[2][maxn];
long long sum[2][maxn];
int main(void) {
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (long long i = 1; i <= n + 10; i++)
      a[0][i] = a[1][i] = sum[0][i] = sum[1][i] = 0;
    long long p = 0;
    for (long long i = 1; i <= n; i++) cin >> a[0][i], p += a[0][i];
    for (long long i = 1; i <= n; i++) cin >> a[1][i], p += a[1][i];
    for (long long i = n; i >= 1; i--) {
      sum[0][i] = sum[0][i + 1] + a[0][i];
    }
    for (long long i = n; i >= 1; i--) {
      sum[1][i] = sum[1][i + 1] + a[1][i];
    }
    long long ans1 = sum[0][2];
    long long ans2 = sum[1][1] - a[1][n];
    long long res = 1e18;
    for (long long i = 2; i < n; i++) {
      long long cnt1 = sum[0][i + 1];
      long long cnt2 = sum[1][1] - sum[1][i + 1];
      res = min(res, min(cnt1, cnt2));
    }
    cout << min(ans1, min(ans2, res)) << "\n";
  }
  return 0;
}
