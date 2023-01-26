#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vint = vector<int>;
using ar3 = array<int, 3>;
using ar4 = array<int, 4>;
using va3 = vector<ar3>;
using va4 = vector<ar4>;
const int N = 4e5 + 5;
const int Inf = 1e9 + 7;
const ll inf = 1e18 + 7;
int n;
vint pos[20][N * 2];
int sb[20];
inline int get_bal(int msk) {
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if ((msk >> i) & 1) ans += sb[i];
  }
  return ans;
}
int dp[1 << 20];
void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    int bal = 0;
    int idx = 0;
    for (char c : s) {
      if (c == '(')
        ++bal;
      else
        --bal;
      pos[i][bal + N].push_back(idx);
      ++idx;
    }
    sb[i] = bal;
  }
  for (int i = 0; i < 1 << n; ++i) {
    dp[i] = -Inf;
  }
  dp[0] = 0;
  for (int i = 0; i < (1 << n); ++i) {
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) continue;
      int tmp = -get_bal(i);
      if (tmp <= 0) {
        int cnt = int((pos[j][N + tmp]).size());
        if (int((pos[j][N + tmp - 1]).size())) {
          cnt = lower_bound((pos[j][N + tmp]).begin(), (pos[j][N + tmp].end()),
                            pos[j][N + tmp - 1][0]) -
                pos[j][N + tmp].begin();
        }
        dp[i | (1 << j)] = max(dp[i | (1 << j)], dp[i] + cnt);
      }
    }
  }
  int ans = -Inf;
  for (int i = 0; i < (1 << n); ++i) {
    ans = max(ans, dp[i]);
  }
  cout << ans << '\n';
}
signed main() {
  int tt = 1;
  ios_base::sync_with_stdio(0);
  cout << setprecision(11) << fixed;
  cin.tie(NULL);
  while (tt--) {
    solve();
  }
}
