#include <bits/stdc++.h>
using namespace std;
const int N = 2010, K = 110, mod = 998244353;
int n, k, a[N], l[N], r[N];
long long dp[N][N], nxt[N][N], C[N][N];
void add(long long &a, long long b) {
  a += b;
  if (a >= mod) a -= mod;
}
long long mult(long long a, long long b) { return a * b % mod; }
void solve() {
  for (int i = 0; i < N; i++) C[0][i] = 1;
  for (int i = 1; i < N; i++)
    for (int j = 1; j <= i; j++)
      C[j][i] = (C[j][i - 1] + C[j - 1][i - 1]) % mod;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    l[i] = max(l[i - 1], a[i] - k);
    r[i] = min(i, a[i] + k);
    if (l[i] > r[i]) {
      printf("0\n");
      return;
    }
    cerr << l[i] << " " << r[i] << endl;
  }
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j >= 0; j--)
      for (int q = l[i]; q <= r[i]; q++) nxt[j][q] = 0;
    for (int j = i; j >= 0; j--) {
      for (int q = l[i]; q <= r[i]; q++) {
        add(nxt[j][q], mult(dp[j][q], j + q));
        add(nxt[j + 1][q], dp[j][q]);
      }
    }
    for (int j = i; j > 0; j--) {
      for (int q = l[i - 1]; q <= r[i] - 1; q++) {
        add(dp[j - 1][q + 1], mult(dp[j][q], j));
      }
    }
    for (int j = i; j >= 0; j--) {
      for (int q = max(1, l[i]); q <= r[i]; q++) {
        add(nxt[j][q], dp[j][q - 1]);
      }
    }
    for (int j = i; j >= 0; j--) {
      for (int q = l[i]; q <= r[i]; q++) {
        dp[j][q] = nxt[j][q];
      }
    }
  }
  long long ans = 0;
  long long first = 1;
  for (int j = n; j >= 0; j--) {
    for (int q = l[n]; q <= r[n]; q++) add(ans, mult(dp[j][q], C[j][n - q]));
    if (j) ans = mult(ans, j);
  }
  printf("%lld\n", ans);
}
int main() {
  int t = 1;
  while (t--) solve();
}
