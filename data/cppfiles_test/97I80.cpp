#include <bits/stdc++.h>
using namespace std;
int n;
const int maxN = 2e5 + 10;
vector<int> g[maxN];
const int BUBEN = 300;
int q;
long long ans[maxN];
vector<int> st[BUBEN + 2];
int k[maxN], vv[maxN];
long long dp[maxN];
vector<int> ord;
vector<int> edge[maxN];
int par[maxN];
bool is_inter[maxN];
int tin[maxN];
int timer = 0;
int tout[maxN];
int h[maxN];
void dfs(int v, int p) {
  tin[v] = timer++;
  for (int to : g[v]) {
    if (to == p) continue;
    par[to] = v;
    edge[v].emplace_back(to);
    h[to] = h[v] + 1;
    dfs(to, v);
  }
  ord.emplace_back(v);
  tout[v] = timer++;
}
int bigPar[maxN];
vector<pair<int, int>> big_edge[maxN];
bool byTin(int a, int b) { return tin[a] < tin[b]; }
int lca(int x, int y) {
  while (h[x] > h[y]) {
    x = par[x];
  }
  while (h[x] < h[y]) {
    y = par[y];
  }
  while (x != y) {
    x = par[x];
    y = par[y];
  }
  return x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }
  dfs(1, -1);
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> vv[i] >> k[i];
    if (k[i] <= BUBEN) {
      st[k[i]].emplace_back(i);
    }
  }
  for (int i = 0; i <= BUBEN; i++) {
    if (!st[i].empty()) {
      for (int vert : ord) {
        dp[vert] = 0;
        for (int x : edge[vert]) {
          dp[vert] += max(1LL, dp[x] - i);
        }
      }
      for (int id : st[i]) {
        ans[id] = dp[vv[id]];
      }
    }
  }
  vector<int> inter;
  for (int z : ord) {
    if ((int)edge[z].size() > BUBEN || z == 1) {
      inter.emplace_back(z);
      is_inter[z] = true;
    }
  }
  sort(inter.begin(), inter.end(), byTin);
  int m = inter.size();
  for (int i = 0; i + 1 < m; i++) {
    inter.emplace_back(lca(inter[i], inter[i + 1]));
  }
  sort(inter.begin(), inter.end(), byTin);
  inter.erase(unique(inter.begin(), inter.end()), inter.end());
  vector<int> st;
  st.push_back(inter[0]);
  for (int i = 1; i < inter.size(); i++) {
    int x = inter[i];
    while (tout[st.back()] < tin[x]) st.pop_back();
    int y = st.back();
    big_edge[y].emplace_back(make_pair(x, -h[y] + h[x]));
    bigPar[x] = y;
    st.push_back(x);
  }
  reverse(inter.begin(), inter.end());
  for (int i = 1; i <= q; i++) {
    if (k[i] > BUBEN) {
      int who = vv[i];
      vector<int> without_par;
      bool hs = false;
      for (int u : inter) {
        if (u == who) hs = true;
        if (tin[who] <= tin[u] && tout[u] <= tout[who]) {
          if (u == 1 ||
              !(tin[who] <= tin[bigPar[u]] && tout[bigPar[u]] <= tout[who])) {
            without_par.emplace_back(u);
          }
          dp[u] = 0;
          for (auto& it : big_edge[u]) {
            dp[u] += max(1LL, dp[it.first] - 1LL * it.second * k[i]);
          }
        }
      }
      if (hs) {
        cout << dp[who] << '\n';
      } else {
        dp[who] = 0;
        for (int z : without_par) {
          dp[who] += max(1LL, dp[z] - k[i]);
        }
        dp[who] += edge[who].size() - without_par.size();
        cout << dp[who] << '\n';
      }
    } else {
      cout << ans[i] << '\n';
    }
  }
  return 0;
}
