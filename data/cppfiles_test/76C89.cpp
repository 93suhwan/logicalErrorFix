#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e6 + 10;
inline int read() {
  int x = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return x;
}
long long dp[maxn];
int main() {
  long long n, m;
  cin >> n >> m;
  dp[1] = 1;
  dp[2] = (-1 + m) % m;
  for (int i = 1; i <= n; i++) {
    dp[i] += dp[i - 1];
    dp[i] %= m;
    dp[i + 1] += dp[i];
    dp[i + 1] %= m;
    for (int j = 2; j * i <= n; j++) {
      dp[j * i] += dp[i];
      dp[j * i] %= m;
      if (j * i + j <= n) {
        dp[j * i + j] -= dp[i];
        dp[j * i + j] %= m;
        dp[j * i + j] += m;
        dp[j * i + j] %= m;
      }
    }
  }
  cout << dp[n] << endl;
  return 0;
}
