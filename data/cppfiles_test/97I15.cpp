#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, q, par[200005];
int dp[200005][25], best[200005][120 + 5];
vector<int> muchii[200005];
void dfs(int nod) {
  for (auto i : muchii[nod])
    if (i != par[nod]) {
      par[i] = nod;
      dfs(i);
    }
}
void solve(long long v, long long k) {
  dp[v][k] = 0;
  for (int j = 0; j < muchii[v].size(); j++) {
    int i = muchii[v][j];
    if (i != par[v]) solve(i, k);
  }
  for (int j = 0; j < muchii[v].size(); j++) {
    int i = muchii[v][j];
    if (i != par[v]) {
      long long val = max(dp[i][k] - k, 1LL);
      dp[v][k] += val;
    }
  }
}
void getbest(int nod) {
  best[nod][0] = (int)muchii[nod].size() - (nod != 1);
  for (int j = 0; j < muchii[nod].size(); j++) {
    int i = muchii[nod][j];
    if (i != par[nod]) getbest(i);
  }
  int prv[120 + 5], cur[120 + 5];
  for (int i = 0; i <= 120; i++) prv[i] = 0;
  for (int j = 0; j < muchii[nod].size(); j++) {
    int i = muchii[nod][j];
    if (i == par[nod]) continue;
    for (int elim = 0; elim <= 120; elim++) {
      cur[elim] = 0;
      for (int k = 0; k <= elim; k++) {
        int val = prv[elim - k];
        if (k == 0)
          val++;
        else
          val += best[i][k - 1];
        cur[elim] = max(cur[elim], val);
        if (elim != 0) best[nod][elim] = max(best[nod][elim], val);
      }
    }
    for (int elim = 0; elim <= 120; elim++) prv[elim] = cur[elim];
  }
}
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    muchii[a].push_back(b);
    muchii[b].push_back(a);
  }
  dfs(1);
  for (int k = 0; k <= 25; k++) solve(1, k);
  getbest(1);
  cin >> q;
  int tc = 0;
  while (q--) {
    tc++;
    long long v, k;
    cin >> v >> k;
    if (k <= 25)
      cout << dp[v][k] << '\n';
    else {
      int ans = (int)muchii[v].size() - (v != 1);
      for (int elim = 0; elim <= 120; elim++)
        ans = max(ans * 1LL, best[v][elim] - elim * k);
      if (tc == 287 && ans == 8315)
        cout << ans << " " << v << " " << k << '\n';
      else
        cout << ans << '\n';
    }
  }
  return 0;
}
