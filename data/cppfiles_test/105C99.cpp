#include <bits/stdc++.h>
using namespace std;
long long mod = (1 ? 1e9 + 7 : 998244353);
const int N = 3e3 + 5;
const int M = 20 * N;
int a[N], dp[N][N], was[N][N];
vector<int> pos[N];
int Dp(int l, int r) {
  if (l > r) return -1;
  if (l == r) return 0;
  if (was[l][r]) return dp[l][r];
  was[l][r] = 1;
  dp[l][r] = 1 + Dp(l + 1, r);
  for (auto u : pos[a[l]]) {
    if (l <= u && u <= r) {
      dp[l][r] = min(dp[l][r], Dp(l + 1, u - 1) + 1 + Dp(u, r));
    }
  }
  return dp[l][r];
}
void Evlos() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      was[i][j] = 0;
      dp[i][j] = 0;
    }
    pos[i].clear();
    a[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pos[a[i]].push_back(i);
  }
  cout << Dp(1, n) << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  int tt = 1;
  cin >> tt;
  while (tt--) Evlos();
  return 0;
}
