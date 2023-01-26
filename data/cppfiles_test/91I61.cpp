#include <bits/stdc++.h>
using namespace std;
template <typename T>
T chMa(T &x, T y) {
  if (y > x) x = y;
  return x;
}
template <typename T>
T chMi(T &x, T y) {
  if (y < x) x = y;
  return x;
}
const int N = 100010, mod = 998244353;
int n, a[N];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long res = 0;
  map<int, int> dp[2];
  for (int i = n; i; i--) {
    dp[i & 1][a[i]] = 1;
    for (auto &[u, v] : dp[i + 1 & 1]) {
      int t = (a[i] + u - 1) / u;
      int p = a[i] / t;
      dp[i & 1][p] += v;
      res += i * v % mod * (t - 1);
      res %= mod;
    }
    dp[i + 1 & 1].clear();
  }
  cout << res << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  for (int turn = 1; turn <= T; turn++) {
    solve();
  }
}
