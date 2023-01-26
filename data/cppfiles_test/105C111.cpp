#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int N = 3e3 + 5;
int t, n, a[N], memo[N][N], vis[N][N], tc;
vector<int> g[N];
int solve(int l, int r) {
  if (l >= r) return l == r;
  int &ans = memo[l][r];
  if (vis[l][r] == tc) return ans;
  vis[l][r] = tc;
  ans = solve(l + 1, r) + 1;
  for (auto &i : g[a[l]]) {
    if (i <= l) continue;
    if (i > r) break;
    ans = min(ans, solve(l, i - 1) + solve(i + 1, r));
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      g[a[i]].push_back(i);
    }
    tc++;
    cout << solve(1, n) - 1 << '\n';
    for (int i = 1; i <= n; i++) g[i].clear();
  }
  return 0;
}
