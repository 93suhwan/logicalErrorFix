#include <bits/stdc++.h>
using namespace std;
const int N = 101;
int n, m, k, p;
int pw[N];
int c[N][N];
int f[N][N][N];
int dp(int n, int m, int k) {
  if (f[n][m][k] != -1) return f[n][m][k];
  if (n == 0) return f[n][m][k] = k == 0;
  if (m == 0) return f[n][m][k] = k == 0;
  if (m > n) return f[n][m][k] = k == 0 ? pw[n] : 0;
  if (m == 1) return f[n][m][k] = k == 1 ? pw[n] : 0;
  if (k > n) return f[n][m][k] = 0;
  f[n][m][k] = 0;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int k1 = 0; k1 <= k; k1++)
      sum = (sum + 1LL * dp(i, m - 1, k1) * dp(n - 1 - i, m - 1, k - k1)) % p;
    f[n][m][k] = (f[n][m][k] + 1LL * sum * c[n - 1][i]) % p;
  }
  return f[n][m][k];
}
int main() {
  auto begin = std::chrono::steady_clock::now();
  cin.tie(0), cout.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m >> k >> p;
  pw[0] = 1;
  for (int i = 1; i <= n; i++) pw[i] = 1LL * pw[i - 1] * i % p;
  c[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % p;
  }
  memset(f, -1, sizeof(f));
  cout << dp(n, m, k) << endl;
  auto end = std::chrono::steady_clock::now();
  cout << std::chrono::steady_clock::duration(end - begin).count() / 1000. /
              1000.
       << endl;
}
