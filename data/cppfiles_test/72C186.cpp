#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
int digit[maxn];
int dp[10][2][1 << 10];
int n, k;
int g[1 << 10];
int dfs(int len, bool lim, int s) {
  if (len == 0) return g[s] <= k;
  int &x = dp[len][lim][s];
  if (~x) return x;
  int low = lim ? digit[len] : 0;
  int ans = false;
  for (int i = low; i <= 9; i++) {
    ans |= dfs(len - 1, lim && i == low, s | (1 << i));
    if (ans) break;
  }
  return x = ans;
}
long long ksm(long long a, long long b) {
  long long ans = 1, base = a;
  while (b) {
    if (b & 1) ans = ans * base % mod;
    b >>= 1;
    base = base * base % mod;
  }
  return ans;
}
long long getans(int len, int lim, int s) {
  if (len == 0) return 0;
  int low = lim ? digit[len] : 0;
  for (int i = low; i <= 9; i++) {
    bool ok = dfs(len - 1, lim && i == low, s | (1 << i));
    if (ok) {
      return i * ksm(10, len - 1) +
             getans(len - 1, lim && i == low, s | (1 << i));
    }
  }
  return -1;
}
long long solve() {
  int k = 0;
  while (n) {
    digit[++k] = n % 10;
    n /= 10;
  }
  memset(dp, -1, sizeof dp);
  dfs(k, true, 0);
  return getans(k, true, 0);
}
int main() {
  ios::sync_with_stdio(false);
  g[0] = 0;
  for (int i = 1; i < 1 << 10; i++) {
    g[i] = g[i >> 1] + (i & 1);
  }
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    cout << solve() << endl;
  }
  return 0;
}
