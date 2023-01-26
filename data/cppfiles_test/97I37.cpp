#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, q, par[200005];
int dp[200005][500 + 5];
vector<int> muchii[200005];
vector<pair<int, int> > query[200005];
pair<int, int> qr[200005];
int sol[200005];
void dfs(int nod) {
  for (auto i : muchii[nod])
    if (i != par[nod]) {
      par[i] = nod;
      dfs(i);
    }
}
void solve(int v) {
  for (int k = 0; k <= 500; k++) dp[v][k] = 0;
  for (int j = 0; j < muchii[v].size(); j++) {
    int i = muchii[v][j];
    if (i != par[v]) {
      solve(i);
      for (int k = 0; k <= 500; k++) {
        int val = max(dp[i][k] - k, 1);
        dp[v][k] += val;
      }
    }
  }
  for (int j = 0; j < query[v].size(); j++) {
    int k = query[v][j].first;
    int poz = query[v][j].second;
    if (k <= 500) sol[poz] = dp[v][k];
  }
}
int sub[200005];
int prv[500 + 5], cur[500 + 5];
void getbest(int nod) {
  for (int i = 0; i <= 500; i++) dp[nod][i] = 0;
  dp[nod][0] = (int)muchii[nod].size() - (nod != 1);
  for (int i = 0; i <= 500; i++) prv[i] = 0;
  for (int j = 0; j < muchii[nod].size(); j++) {
    int i = muchii[nod][j];
    if (i == par[nod]) continue;
    getbest(i);
    for (int elim = 0; elim <= min(500, sub[i] + sub[nod]); elim++) {
      cur[elim] = 0;
      for (int k = 0; k <= min(elim, sub[i]); k++) {
        int val = prv[elim - k];
        if (k == 0)
          val++;
        else
          val += dp[i][k - 1];
        cur[elim] = max(cur[elim], val);
        if (elim != 0) dp[nod][elim] = max(dp[nod][elim], val);
      }
    }
    for (int elim = 0; elim <= 500; elim++) prv[elim] = cur[elim];
    sub[nod] += sub[i];
  }
  sub[nod]++;
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
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int v, k;
    cin >> v >> k;
    query[v].push_back({k, i});
    qr[i] = {v, k};
  }
  solve(1);
  int tc = 0;
  for (int z = 1; z <= q; z++) {
    tc++;
    long long v, k;
    v = qr[tc].first;
    k = qr[tc].second;
    if (k <= 500) {
      continue;
    } else {
      int ans = (int)muchii[v].size() - (v != 1);
      sol[tc] = ans;
    }
  }
  for (int i = 1; i <= q; i++) cout << sol[i] << '\n';
  return 0;
}
