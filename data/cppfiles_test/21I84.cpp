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
      n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1))),
      mem = dp;
  function<int(int, int, int)> rec = [&](int N, int M, int K) -> int {
    if (mem[N][M][K]) return dp[N][M][K];
    mem[N][M][K] = 1;
    if (M == 0 && K == 0) {
      if (N == 0)
        dp[N][M][K] = 1;
      else
        dp[N][M][K] = (1ll * N * rec(N - 1, M, K)) % p;
      return dp[N][M][K];
    }
    if (M == 0) {
      return dp[N][M][K] = K == 0;
    }
    if (N == 0) {
      if (K > 0) return 0;
      return dp[N][M][K] = 1;
    }
    if (M > N || K > N) return 0;
    for (int i = 0; i < N; i++) {
      int L = i;
      int R = N - 1 - L;
      int good = M == 1;
      for (int Kl = 0; Kl + good <= K; Kl++) {
        int Kr = K - Kl - good;
        int r1 = rec(L, M - 1, Kl);
        int r2 = rec(R, M - 1, Kr);
        int coef = C[L + R][L];
        coef = (1ll * coef * r1) % p;
        coef = (1ll * coef * r2) % p;
        dp[N][M][K] = (dp[N][M][K] + coef) % p;
      }
    }
    return dp[N][M][K];
  };
  return rec(n, m, k);
}
void work() {
  int n, m, k, p;
  cin >> n >> m >> k >> p;
  int res = fast(n, m, k, p);
  cout << res << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  work();
  return 0;
}
