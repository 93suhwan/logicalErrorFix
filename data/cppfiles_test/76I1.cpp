#include <bits/stdc++.h>
using namespace std;
mt19937 gen(time(0));
const int N = 1e6 + 100;
const int M = 18;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
vector<int> g[N], ord;
int u[N], a[N], used[N], ed[1001][1001];
set<pair<int, int> > st;
bool comp(int a, int b) {
  return (int32_t(g[a].size()) < int32_t(g[b].size()));
}
void del(int v) {
  if (used[v]) return;
  used[v] = 1;
  st.erase({a[v], v});
  for (auto to : g[v]) {
    if (used[to]) continue;
    pair<int, int> p = {a[to], to};
    st.erase(p);
    a[to]--;
    p.first--;
    st.insert(p);
  }
}
void try_set(int n) {
  st.clear();
  for (int i = 0; i < n; i++) {
    a[i] = int32_t(g[i].size());
    used[i] = 0;
    st.insert({a[i], i});
  }
  vector<int> ans;
  while (ans.size() < 5 && int32_t(st.size())) {
    pair<int, int> p = *st.begin();
    st.erase(st.begin());
    int v = p.second;
    used[v] = 1;
    for (auto to : g[v]) {
      del(to);
    }
    ans.push_back(v);
  }
  if (int32_t(ans.size()) >= 5) {
    for (int i = 0; i < 5; i++) cout << ans[i] + 1 << " ";
    exit(0);
  }
}
void try_click(int n, int st) {
  for (int i = 0; i < n; i++) u[i] = 0;
  vector<int> ans;
  int kol = 0;
  for (int i = st; i < n; i++) {
    int v = ord[i];
    if (u[v] != kol) continue;
    ans.push_back(v);
    u[v]++;
    kol++;
    for (auto to : g[v]) u[to]++;
  }
  if (int32_t(ans.size()) >= 5) {
    for (int i = 0; i < 5; i++) cout << ans[i] + 1 << " ";
    exit(0);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  srand(time(0));
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  try_set(n);
  for (int i = 0; i < n; i++) ord.push_back(i);
  sort(ord.rbegin(), ord.rend(), comp);
  if (1ll * n * n <= 1e6) {
    for (int i = 0; i < n; i++) {
      for (auto to : g[i]) ed[i][to] = 1;
      ed[i][i] = 1;
      g[i].clear();
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (!ed[i][j]) g[i].push_back(j);
      }
    }
    try_set(n);
  }
  cout << -1;
}
