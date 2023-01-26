#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000000 + 1;
constexpr LL mod = 998244353;
void no() {
  cout << "0";
  exit(0);
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> G(k + 1), H(k + 1);
  for (int i = 0; i < n; i += 1) {
    int c;
    cin >> c;
    vector<int> A(c);
    for (int& x : A) cin >> x;
    for (int j = 1; j < c; j += 1) {
      if (G[A[j - 1]] and G[A[j - 1]] != A[j]) no();
      G[A[j - 1]] = A[j];
      if (H[A[j]] and H[A[j]] != A[j - 1]) no();
      H[A[j]] = A[j - 1];
    }
  }
  int sum = 0;
  map<int, int> mp;
  for (int i = 1; i <= k; i += 1)
    if (not H[i]) {
      int x = 0;
      for (int j = i; j; j = G[j]) x += 1;
      mp[x] += 1;
      sum += x;
    }
  if (sum != k) no();
  vector<LL> dp(m + 1);
  dp[0] = 1;
  for (int i = 1; i <= m; i += 1)
    for (auto [x, y] : mp)
      if (i >= x) dp[i] = (dp[i] + dp[i - x] * y) % mod;
  cout << dp[m];
  return 0;
}
