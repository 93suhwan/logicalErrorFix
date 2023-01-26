#include <bits/stdc++.h>
using namespace std;
int n, a[22], dp[1 << 21], sum[1 << 21], ans = 0;
char s[500005];
vector<int> pos[21];
vector<vector<int>> c[21];
void solve(int x, int id) {
  if (dp[x] == -1) return;
  int p = 0;
  if (pos[id].size() > sum[x] + 1) p = pos[id][sum[x] + 1];
  if (!p) {
    int k = 0;
    if (c[id].size() > sum[x]) k = c[id][sum[x]].size();
    dp[x | (1 << id - 1)] = max(dp[x | (1 << id - 1)], dp[x] + k);
    ans = max(ans, dp[x | (1 << id - 1)]);
  } else {
    if (c[id].size() <= sum[x]) return;
    int k = upper_bound(c[id][sum[x]].begin(), c[id][sum[x]].end(), p) -
            c[id][sum[x]].begin();
    ans = max(ans, dp[x] + k);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  cin >> n;
  for (int i = 1, k = 0; i <= n; ++i, k = 0) {
    cin >> s + 1;
    int len = strlen(s + 1);
    pos[i].resize(len + 1);
    c[i].resize(len + 1);
    for (int j = 1; j <= len; ++j) {
      k += (s[j] == '(' ? 1 : -1);
      if (k <= 0) {
        if (!pos[i][-k]) pos[i][-k] = j;
        c[i][-k].push_back(j);
      }
    }
    a[i] = k;
  }
  for (int i = 1; i < (1 << n); ++i) {
    int j = __builtin_ffs(i);
    sum[i] = sum[i ^ (1 << j - 1)] + a[j];
  }
  for (int i = 1; i < (1 << n); ++i)
    for (int j = 1; j <= i; j <<= 1)
      if (i & j) solve(i ^ j, __builtin_ffs(j));
  cout << ans << '\n';
  return 0;
}
