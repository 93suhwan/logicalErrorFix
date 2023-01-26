#include <bits/stdc++.h>
using namespace std;
const int N = 510;
const int mood = 998244353;
long long dp[N][N];
long long zu[N][N];
long long qpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = a * res % mood;
    b >>= 1;
    a = a * a % mood;
  }
  return res;
}
long long dfs(int n, int x) {
  if (dp[n][x]) return dp[n][x];
  dp[n][x] = qpow(min(x, n - 1), n);
  if (x <= n - 1) return dp[n][x];
  for (int i = 0; i <= n - 2; i++) {
    long long t = qpow(n - 1, i) * dfs(n - i, x - n + 1) % mood;
    dp[n][x] = (dp[n][x] + t) % mood;
    dp[n][x] = dp[n][x] * zu[n][i] % mood;
  }
  return dp[n][x];
}
int main() {
  int n, x;
  cin >> n >> x;
  for (int i = 0; i <= 500; i++) {
    for (int j = 0; j <= i; j++) {
      if (i == 0 || j == 0)
        zu[i][j] = 1;
      else
        zu[i][j] = (zu[i - 1][j] + zu[i - 1][j - 1]) % mood;
    }
  }
  cout << dfs(n, x) << endl;
  return 0;
}
