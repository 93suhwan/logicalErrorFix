#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const long long inf64 = 1e18;
int slow(int n, int m, int k, int p) {
  vector<int> perm(n);
  iota(perm.begin(), perm.end(), 0);
  int res = 0;
  do {
    int good = 0;
    for (int i = 0; i < n; i++) {
      int cnt = 1, cur;
      cur = perm[i];
      for (int j = i + 1; j < n; j++) {
        if (perm[j] > cur) {
          cur = perm[j];
          cnt++;
        }
      }
      cur = perm[i];
      for (int j = i - 1; j >= 0; j--) {
        if (perm[j] > cur) {
          cur = perm[j];
          cnt++;
        }
      }
      if (cnt == m) good++;
    }
    if (good == k) {
      res = (res + 1) % p;
    }
  } while (next_permutation(perm.begin(), perm.end()));
  return res;
}
int fast(int n, int m, int k, int p) {
  vector<vector<int>> C(n + 1, vector<int>(n + 1));
  for (int i = 0; i <= n; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % p;
    }
  }
  vector<vector<vector<int>>> dp(
      n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1)));
  for (int M = 0; M <= m; M++) {
    for (int N = 0; N <= n; N++) {
      for (int K = 0; K <= k; K++) {
        if (M == 0 && K == 0) {
          if (N == 0)
            dp[N][M][K] = 1;
          else
            dp[N][M][K] = (1ll * N * dp[N - 1][M][K]) % p;
          continue;
        }
        if (M == 0) {
          dp[N][M][K] = K == 0;
          continue;
        }
        if (N == 0) {
          if (K > 0) {
            dp[N][M][K] = 0;
            continue;
          }
          dp[N][M][K] = 1;
          continue;
        }
        int good = M == 1;
        for (int Kl = 0; Kl + good <= K; Kl++) {
          int Kr = K - Kl - good;
          for (int i = 0; i < N; i++) {
            int r1 = dp[i][M - 1][Kl];
            int r2 = dp[N - 1 - i][M - 1][Kr];
            int coef = C[N - 1][i];
            coef = (1ll * coef * r1) % p;
            coef = (1ll * coef * r2) % p;
            dp[N][M][K] = (dp[N][M][K] + coef) % p;
          }
        }
      }
    }
  }
  return dp[n][m][k];
}
void work() {
  int n, m, k, p;
  cin >> n >> m >> k >> p;
  int res = fast(n, m, k, p);
  cout << res << "\n";
}
void max_test() {
  int n = 100;
  int m = 50;
  int k = 50;
  int p = 100007;
  int res = fast(n, m, k, p);
  cout << res << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  double st = clock();
  work();
  cout << -(st - clock()) / CLOCKS_PER_SEC << "\n";
  return 0;
}
