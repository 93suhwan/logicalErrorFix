#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e6 + 10;
int n, mod, dp[maxn], s[maxn];
inline int add(int x, int y) {
  x += y;
  return x >= mod ? x - mod : x;
}
inline int sub(int x, int y) {
  x -= y;
  return x < 0 ? x + mod : x;
}
inline int mul(int x, int y) { return (long long)x * y % mod; }
void solve2() {
  cin >> n >> mod;
  dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i] = add(dp[i], add(dp[i - 1], dp[i - 1]));
    if (i != 2) dp[i] = add(dp[i], 1);
    for (int j = i + i; j <= n; j += i)
      dp[j] = add(dp[j], sub(dp[i], dp[i - 1]));
  }
  cout << dp[n] << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve2();
  return 0;
}
