#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 10;
const long long mod = 1e9 + 7;
const long long m2 = 1e9 + 7;
const long long INF64 = long long(1e18);
const long long max2 = 1e3 + 10;
const long long N = 1000001;
const long long MAXN = 2e5 + 10;
const long long MOD = 1e9 + 7;
const long long MaxN = 1040;
const long long ALPHABET_SIZE = 2;
long long m = 1000000007;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
long long mat[1001][1001];
long long dp[1001][1001][2];
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  long long n, m, q, i, j;
  cin >> n >> m >> q;
  memset(mat, 0, sizeof(mat));
  memset(dp, 0, sizeof(dp));
  long long sum = 0;
  for (i = n - 1; i >= 0; --i) {
    for (j = m - 1; j >= 0; --j) {
      if (i + 1 < n) {
        if (mat[i + 1][j] == 0) dp[i][j][1] = dp[i + 1][j][0];
      }
      if (j + 1 < m) {
        if (mat[i][j + 1] == 0) dp[i][j][0] = dp[i][j + 1][1];
      }
      dp[i][j][0] += 1;
      dp[i][j][1] += 1;
      sum += dp[i][j][0];
      sum += dp[i][j][1];
    }
  }
  long long cnt = n * m;
  while (q--) {
    long long a, b, ans = 0;
    cin >> a >> b;
    --a, --b;
    mat[a][b] = !mat[a][b];
    if (mat[a][b] == 0) {
      ++cnt;
      if (a + 1 < n) {
        if (mat[a + 1][b] == 0) dp[a][b][1] = dp[a + 1][b][0];
      }
      if (b + 1 < m) {
        if (mat[a][b + 1] == 0) dp[a][b][0] = dp[a][b + 1][1];
      }
      dp[a][b][0] += 1;
      dp[a][b][1] += 1;
      sum += dp[a][b][0];
      sum += dp[a][b][1];
      long long a1 = dp[a][b][0], b1 = dp[a][b][1];
      if (a - 1 >= 0) {
        if (mat[a - 1][b] == 0) {
          dp[a - 1][b][1] += a1;
          sum += a1;
        }
      }
      if (b - 1 >= 0) {
        if (mat[a][b - 1] == 0) {
          dp[a][b - 1][0] += b1;
          sum += b1;
        }
      }
      a1 += 1;
      b1 += 1;
      i = a - 1, j = b - 1;
      while (i >= 0 && j >= 0) {
        if (mat[i][j] == 1) break;
        long long a1 = dp[i][j][0], b1 = dp[i][j][1];
        {
          sum -= dp[i][j][0];
          sum -= dp[i][j][1];
          if (i + 1 < n) {
            if (mat[i + 1][j] == 0) dp[i][j][1] = dp[i + 1][j][0];
          }
          if (j + 1 < m) {
            if (mat[i][j + 1] == 0) dp[i][j][0] = dp[i][j + 1][1];
          }
          dp[i][j][0] += 1;
          dp[i][j][1] += 1;
          sum += dp[i][j][0];
          sum += dp[i][j][1];
        }
        a1 = dp[i][j][0] - a1;
        b1 = dp[i][j][1] - b1;
        if (i - 1 >= 0) {
          if (mat[i - 1][j] == 0) {
            dp[i - 1][j][1] += a1;
            sum += a1;
          }
        }
        if (j - 1 >= 0) {
          if (mat[i][j - 1] == 0) {
            dp[i][j - 1][0] += b1;
            sum += b1;
          }
        }
        a1 += 2;
        b1 += 2;
        --i, --j;
      }
    } else {
      --cnt;
      sum -= dp[a][b][0];
      sum -= dp[a][b][1];
      long long a1 = dp[a][b][0], b1 = dp[a][b][1];
      dp[a][b][0] = dp[a][b][1] = 0;
      if (a - 1 >= 0) {
        if (mat[a - 1][b] == 0) {
          dp[a - 1][b][1] -= a1;
          sum -= a1;
        }
      }
      if (b - 1 >= 0) {
        if (mat[a][b - 1] == 0) {
          dp[a][b - 1][0] -= b1;
          sum -= b1;
        }
      }
      a1 += 1;
      b1 += 1;
      i = a - 1, j = b - 1;
      while (i >= 0 && j >= 0) {
        if (mat[i][j] == 1) break;
        long long a1 = dp[i][j][0], b1 = dp[i][j][1];
        {
          sum -= dp[i][j][0];
          sum -= dp[i][j][1];
          dp[i][j][0] = 0;
          dp[i][j][1] = 0;
          if (i + 1 < n) {
            if (mat[i + 1][j] == 0) dp[i][j][1] = dp[i + 1][j][0];
          }
          if (j + 1 < m) {
            if (mat[i][j + 1] == 0) dp[i][j][0] = dp[i][j + 1][1];
          }
          dp[i][j][0] += 1;
          dp[i][j][1] += 1;
          sum += dp[i][j][0];
          sum += dp[i][j][1];
        }
        a1 = dp[i][j][0] - a1;
        b1 = dp[i][j][1] - b1;
        if (i - 1 >= 0) {
          if (mat[i - 1][j] == 0) {
            dp[i - 1][j][1] += a1;
            sum += a1;
          }
        }
        if (j - 1 >= 0) {
          if (mat[i][j - 1] == 0) {
            dp[i][j - 1][0] += b1;
            sum += b1;
          }
        }
        a1 += 2;
        b1 += 2;
        --i, --j;
      }
    }
    cout << sum - cnt << "\n";
  }
  return (0);
}
