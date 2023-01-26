#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000001;
const int MOD = 1000000007;
const int N = 300009;
int a[N + 1], b[N + 1], dp[N + 1], pr[N + 1], mn[N + 1];
int main(int argc, const char* argv[]) {
  int n;
  cin >> n;
  for (int i = (1); i <= (n); ++i) scanf("%d", &a[i]);
  for (int i = (1); i <= (n); ++i) scanf("%d", &b[i]);
  vector<pair<int, int>> g;
  for (int i = (0); i <= (n); ++i) mn[i] = -1, dp[i] = inf;
  for (int i = (1); i <= (n); ++i) {
    g.push_back(make_pair(i - a[i], i));
    mn[i + b[i]] = max(mn[i + b[i]], i);
  }
  sort(g.begin(), g.end());
  int gid = 0;
  dp[0] = 0;
  set<pair<int, int>> all;
  for (int i = (1); i <= (n); ++i)
    if (a[i] >= i) {
      dp[i] = 1;
      pr[i] = 0;
      all.insert(make_pair(dp[i], i));
    }
  while (!all.empty()) {
    pair<int, int> cur = *all.begin();
    all.erase(all.begin());
    int v = cur.second;
    while (gid < (int)((g).size()) && g[gid].first <= mn[v]) {
      int pos = g[gid].second;
      if (dp[pos] > dp[v] + 1) {
        dp[pos] = dp[v] + 1;
        pr[pos] = mn[v];
        all.insert(make_pair(dp[pos], pos));
      }
      gid++;
    }
  }
  if (dp[n] >= inf)
    cout << "-1" << endl;
  else {
    int v = n;
    vector<int> ans;
    while (v != 0) {
      v = pr[v];
      ans.push_back(v);
      v += b[v];
    }
    cout << ans.size() << endl;
    for (auto x : ans) cout << x << " ";
    cout << endl;
  }
  return 0;
}
