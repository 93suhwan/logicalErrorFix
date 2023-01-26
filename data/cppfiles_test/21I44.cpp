#include <bits/stdc++.h>
using namespace std;
int n, m, k;
long long p;
vector<vector<long long>> binom;
vector<vector<vector<long long>>> dp;
long long f(int ii, int jj, int kk) {
  if (dp[ii][jj][kk] != -1) return dp[ii][jj][kk];
  long long ret = 0LL;
  for (int i = 0; i < ii; i++) {
    if (jj == m) {
      assert(jj == m);
      for (int kkk = 0; kkk <= kk - 1; kkk++) {
        if (jj + 1 <= n)
          ret = (ret + f(i, jj + 1, kkk) * f(ii - 1 - i, jj + 1, kk - 1 - kkk) %
                           p * binom[ii - 1][i]) %
                p;
      }
    } else {
      assert(jj != m);
      for (int kkk = 0; kkk <= kk; kkk++) {
        if (jj + 1 <= n)
          ret = (ret + f(i, jj + 1, kkk) * f(ii - 1 - i, jj + 1, kk - kkk) % p *
                           binom[ii - 1][i]) %
                p;
      }
    }
  }
  return dp[ii][jj][kk] = ret;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k >> p;
  binom = vector<vector<long long>>(n + 1, vector<long long>(n + 1, 0LL));
  binom[0][0] = 1LL;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      binom[i + 1][j] = (binom[i + 1][j] + binom[i][j]) % p;
      binom[i + 1][j + 1] = (binom[i + 1][j + 1] + binom[i][j]) % p;
    }
  }
  dp = vector<vector<vector<long long>>>(
      n + 1, vector<vector<long long>>(n + 1, vector<long long>(n + 1, -1)));
  for (int i = 0; i <= n; i++) dp[0][i][0] = 1LL;
  cout << f(n, 1, k) << "\n";
  return 0;
}
