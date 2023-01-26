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
const int MAXN = 105;
long long C[MAXN][MAXN];
long long dp[MAXN][MAXN][MAXN];
int fast(int n, int m, int k, long long p) {
  for (int i = 0; i <= n; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % p;
    }
  }
  for (int M = 0; M <= m; M++) {
    for (int N = 0; N <= n; N++) {
      if (M > 0 && N > 0) break;
      for (int K = 0; K <= k; K++) {
        if (M == 0 && K == 0) {
          if (N == 0)
            dp[M][N][K] = 1;
          else
            dp[M][N][K] = (N * dp[M][N - 1][K]) % p;
          continue;
        }
        if (M == 0) {
          dp[M][N][K] = K == 0;
          continue;
        }
        if (N == 0) {
          if (K > 0) {
            dp[M][N][K] = 0;
            continue;
          }
          dp[M][N][K] = 1;
          continue;
        }
      }
    }
  }
  for (int M = 1; M <= m; M++) {
    for (int N = 1; N <= n; N++) {
      for (int Kr = 0; Kr <= k; Kr++) {
        int good = M == 1;
        for (int i = 0; i < N; i++) {
          if (!dp[M - 1][N - 1 - i][Kr]) continue;
          for (int Kl = 0; Kl + Kr + good <= k; Kl++) {
            if (dp[M - 1][i][Kl])
              dp[M][N][Kl + Kr + good] =
                  (dp[M][N][Kl + Kr + good] + dp[M - 1][i][Kl] *
                                                  dp[M - 1][N - 1 - i][Kr] % p *
                                                  C[N - 1][i]) %
                  p;
          }
        }
      }
    }
  }
  return dp[m][n][k];
}
void work() {
  int n, m, k, p;
  cin >> n >> m >> k >> p;
  int res = fast(n, m, k, p);
  cout << res << "\n";
}
void max_test() {
  int n = 100;
  int m = 100;
  int k = 100;
  int p = 100007;
  int res = fast(n, m, k, p);
  cout << res << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  work();
  return 0;
}
