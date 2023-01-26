#include <bits/stdc++.h>
class game {
 private:
  long long n, k;

 public:
  long long dp[200005][5], luth[200005];
  long long res = 0;
  void in() {
    long long x, y;
    std::cin >> x >> y;
    n = x;
    k = y;
  }
  void solve() {
    luth[0] = 1;
    for (int i = 1; i <= n; i++) {
      luth[i] = luth[i - 1] * 2;
      if (luth[i] >= 1000000007) luth[i] -= 1000000007;
    }
    dp[0][0] = luth[n];
    for (int i = 1; i <= n; i++) {
      dp[i][0] = (dp[i - 1][0] * luth[n]) % 1000000007;
    }
    if (k == 0) {
      res = 1;
      return;
    }
    if (k == 1) {
      if (n % 2 == 1) {
        res = ((luth[n - 1]) + 1) % 1000000007;
      } else {
        res = (luth[n - 1]) % 1000000007;
      }
      return;
    }
    if (n % 2 == 1) {
      for (int i = 1; i < k; i++) {
        dp[i][1] = ((dp[i - 1][1] * luth[i - 1]) + 1) % 1000000007;
      }
    } else {
      for (int i = 1; i < k; i++) {
        dp[i][1] =
            ((dp[i - 1][1] * (luth[i - 1] - 1)) + dp[i - 1][0]) % 1000000007;
      }
    }
    res = dp[k - 1][1];
  }
  void out() { std::cout << res << std::endl; }
};
int main() {
  int tests;
  std::cin >> tests;
  game *obj = new game;
  for (int i = 0; i < tests; i++) {
    obj->in();
    obj->solve();
    obj->out();
  }
  return 0;
}
