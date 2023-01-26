#include <bits/stdc++.h>
using namespace std;
mt19937 gen(time(0));
const int N = 1e6 + 100;
const int M = 18;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
vector<int> g[N], ord;
vector<pair<int, int> > edge;
int u[N], a[N], used[N], ed[2000][2000];
set<pair<int, int> > st, e;
bool comp(int a, int b) {
  return (int32_t(g[a].size()) < int32_t(g[b].size()));
}
bool good(vector<int> a) {
  int kol = 0;
  for (int i = 0; i < 5; i++)
    for (int j = i + 1; j < 5; j++)
      kol += e.count({min(a[i], a[j]), max(a[i], a[j])});
  if (kol && kol != 10) return 0;
  return 1;
}
void out(vector<int> a) {
  int kol = 0;
  for (int i = 0; i < 5; i++)
    for (int j = i + 1; j < 5; j++)
      kol += e.count({min(a[i], a[j]), max(a[i], a[j])});
  if (kol && kol != 10)
    while (1)
      ;
  for (auto to : a) cout << to + 1 << " ";
  exit(0);
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
    vector<int> ve;
    for (int i = 0; i < 5; i++) ve.push_back(ans[i]);
    out(ve);
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
    vector<int> ve;
    for (int i = 0; i < 5; i++) ve.push_back(ans[i]);
    out(ve);
  }
}
void solve(int n) {
  for (int i = 0; i < int32_t(edge.size()); i++) {
    int x = edge[i].first, y = edge[i].second;
    for (int j = i + 1; j < int32_t(edge.size()); j++) {
      int a = edge[j].first, b = edge[j].second;
      if (x == a || x == b || y == a || y == b) continue;
      for (int z = 0; z < n; z++) {
        if (x == z || y == z || a == z || b == z) continue;
        vector<int> ve;
        ve.push_back(x);
        ve.push_back(y);
        ve.push_back(a);
        ve.push_back(b);
        ve.push_back(z);
        if (good(ve)) out(ve);
      }
    }
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
    e.insert({min(x, y), max(x, y)});
    g[x].push_back(y);
    g[y].push_back(x);
  }
  try_set(n);
  for (int i = 0; i < n; i++) ord.push_back(i);
  sort(ord.rbegin(), ord.rend(), comp);
  int T = 100;
  while (T--) {
    try_click(n, 0);
    random_shuffle(ord.begin(), ord.end());
  }
  if (1ll * n * n <= 1e6) {
    e.clear();
    for (int i = 0; i < n; i++) {
      for (auto to : g[i]) ed[i][to] = 1;
      ed[i][i] = 1;
      g[i].clear();
    }
    vector<pair<int, int> > edge;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (!ed[i][j]) {
          g[i].push_back(j);
          if (i < j) e.insert({i, j});
          edge.push_back({i, j});
        }
      }
    }
    try_set(n);
    solve(n);
  }
  cout << -1;
}
