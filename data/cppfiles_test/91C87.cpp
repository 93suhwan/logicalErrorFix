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
int dp[2][N];
vector<int> v[2];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long res = 0;
  for (int i = n; i; i--) {
    int k = i & 1;
    dp[k][a[i]] = 1;
    v[k].push_back(a[i]);
    int last = a[i];
    for (auto &x : v[k ^ 1]) {
      int y = dp[k ^ 1][x];
      int split = (a[i] + x - 1) / x;
      int minv = a[i] / split;
      dp[k][minv] += y;
      res += (long long)i * (split - 1) % mod * y % mod;
      res %= mod;
      if (last != minv) {
        last = minv, v[k].push_back(minv);
      }
    }
    for (auto &x : v[k ^ 1]) dp[k ^ 1][x] = 0;
    v[k ^ 1].clear();
  }
  cout << res << endl;
  for (auto &x : v[0]) dp[0][x] = 0;
  for (auto &x : v[1]) dp[1][x] = 0;
  v[0].clear();
  v[1].clear();
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
