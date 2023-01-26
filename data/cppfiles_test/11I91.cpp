#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;
const long long mod = 998244353;
const int N = 2e5 + 5;
int n, a[N], bit[N];
void ins(int i, int x) {
  while (i <= n) {
    bit[i] = max(bit[i], x);
    i += (i & -i);
  }
}
int mx(int i) {
  int ans = 0;
  while (i > 0) {
    ans = max(ans, bit[i]);
    i = (i & i - 1);
  }
  return ans;
}
void solve() {
  cin >> n;
  for (int i = (int)0; i != (int)n; i = i + 1) cin >> a[i];
  ;
  int ans = 0;
  fill(bit, bit + n + 1, 0);
  vector<int> v[n + 1];
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] <= n) v[a[i]].push_back(i + 1);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = (int)v[i].size() - 1; j >= 0; j--) {
      if (v[i][j] - i < 0) continue;
      int dp = 1;
      dp = max(dp, 1 + mx(v[i][j] + 1 - i));
      ans = max(ans, dp);
      ins(v[i][j] + 1 - i, dp);
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}
