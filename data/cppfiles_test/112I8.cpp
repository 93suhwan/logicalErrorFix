#include <bits/stdc++.h>
using namespace std;
const int logN = 18;
const int maxN = 200005;
char pch[maxN];
int n, m, q, sz;
vector<pair<int, char> > g[maxN];
pair<int, int> orange[maxN][logN];
pair<int, int> rrange[maxN][logN];
vector<array<int, 4> > queries[maxN];
int par[maxN][logN], pos[maxN], ord[maxN], ind[maxN], ans[maxN], dep[maxN],
    f[maxN];
inline void update(int i, int x) {
  while (i <= m) {
    f[i] += x;
    i += i & (-i);
  }
}
inline int query(int i) {
  int ret = 0;
  while (i) {
    ret += f[i];
    i &= (i - 1);
  }
  return ret;
}
void dfs(int v, int p) {
  par[v][0] = p;
  for (auto x : g[v]) {
    if (x.first != p) {
      dep[x.first] = dep[v] + 1;
      pch[x.first] = x.second;
      dfs(x.first, v);
    }
  }
}
void buildSuffixArray(string s) {
  int m = (int)s.size();
  {
    vector<pair<char, int> > vec;
    for (int i = 0; i < m; i++) {
      vec.emplace_back(s[i], i);
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < m; i++) {
      if (i == 0 || vec[i].first != vec[i - 1].first)
        pos[vec[i].second] = i;
      else
        pos[vec[i].second] = pos[vec[i - 1].second];
    }
  }
  for (int k = 1; k < logN; k++) {
    vector<pair<pair<int, int>, int> > vec;
    for (int i = 0; i < m; i++) {
      int j = i + (1 << (k - 1));
      if (j < m) {
        vec.push_back({{pos[i], pos[j]}, i});
      } else {
        vec.push_back({{pos[i], -1}, i});
      }
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < m; i++) {
      if (i == 0 || vec[i].first != vec[i - 1].first)
        pos[vec[i].second] = i;
      else
        pos[vec[i].second] = pos[vec[i - 1].second];
    }
    if ((1 << k) >= m) break;
  }
  for (int i = 0; i < m; i++) {
    ord[pos[i]] = i;
  }
}
inline pair<int, int> compute(pair<int, int> range1, pair<int, int> range2,
                              int len) {
  if (range1.first == -1 || range2.first == -1) return {-1, -1};
  pair<int, int> ret = {-1, -1};
  {
    int low = range1.first, hig = range1.second;
    while (low < hig) {
      int mid = (low + hig) / 2;
      if (ord[mid] + len < sz && range2.first <= pos[ord[mid] + len]) {
        hig = mid;
      } else {
        low = mid + 1;
      }
    }
    ret.first = low;
  }
  {
    int low = range1.first, hig = range1.second;
    while (low < hig) {
      int mid = (low + hig + 1) / 2;
      if (ord[mid] + len >= sz || pos[ord[mid] + len] <= range2.second) {
        low = mid;
      } else {
        hig = mid - 1;
      }
    }
    ret.second = low;
  }
  if (ret.first > ret.second) {
    ret = {-1, -1};
  }
  return ret;
}
inline int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  int diff = dep[u] - dep[v];
  for (int i = logN - 1; i >= 0; i--) {
    if ((diff >> i) & 1) u = par[u][i];
  }
  if (u == v) return u;
  for (int i = logN - 1; i >= 0; i--) {
    if (par[u][i] != par[v][i]) {
      u = par[u][i];
      v = par[v][i];
    }
  }
  return par[u][0];
}
pair<int, int> get(int u, int v) {
  int w = lca(u, v);
  pair<int, int> range1 = {0, sz - 1};
  pair<int, int> range2 = {0, sz - 1};
  int len = 0;
  {
    int dist = dep[u] - dep[w];
    for (int i = logN - 1; i >= 0; i--) {
      if ((dist >> i) & 1) {
        range1 = compute(range1, orange[u][i], len);
        len += (1 << i);
        u = par[u][i];
      }
    }
  }
  {
    int dist = dep[v] - dep[w];
    for (int i = logN - 1; i >= 0; i--) {
      if ((dist >> i) & 1) {
        range2 = compute(rrange[v][i], range2, 1 << i);
        v = par[v][i];
      }
    }
  }
  return compute(range1, range2, len);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> q;
  for (int i = 1; i < n; i++) {
    int u, v;
    char ch;
    cin >> u >> v >> ch;
    g[u].emplace_back(v, ch);
    g[v].emplace_back(u, ch);
  }
  dep[1] = 0;
  dfs(1, 1);
  for (int k = 1; k < logN; k++) {
    par[1][k] = 1;
    for (int i = 2; i <= n; i++) {
      par[i][k] = par[par[i][k - 1]][k - 1];
    }
  }
  string s = "";
  memset(ind, -1, sizeof(ind));
  for (int i = 1; i <= m; i++) {
    string t;
    cin >> t;
    for (int j = 0; j < (int)t.size(); j++) {
      ind[j + (int)s.size()] = i;
    }
    s += t;
    s += "#";
  }
  sz = (int)s.size();
  buildSuffixArray(s);
  memset(orange, -1, sizeof(orange));
  memset(rrange, -1, sizeof(rrange));
  {
    vector<int> lo(26, -1);
    vector<int> hi(26, -1);
    for (int i = 0; i < sz; i++) {
      if (s[ord[i]] == '#') continue;
      if (lo[s[ord[i]] - 'a'] == -1) {
        lo[s[ord[i]] - 'a'] = i;
      }
      hi[s[ord[i]] - 'a'] = i;
    }
    for (int i = 2; i <= n; i++) {
      orange[i][0] = {lo[pch[i] - 'a'], hi[pch[i] - 'a']};
      rrange[i][0] = {lo[pch[i] - 'a'], hi[pch[i] - 'a']};
    }
  }
  for (int k = 1; k < logN; k++) {
    for (int u = 1; u <= n; u++) {
      int v = par[u][k - 1];
      orange[u][k] = compute(orange[u][k - 1], orange[v][k - 1], 1 << (k - 1));
    }
    for (int u = 1; u <= n; u++) {
      int v = par[u][k - 1];
      rrange[u][k] = compute(rrange[v][k - 1], rrange[u][k - 1], 1 << (k - 1));
    }
  }
  memset(ans, 0, sizeof(ans));
  for (int i = 1; i <= q; i++) {
    int u, v, l, r;
    cin >> u >> v >> l >> r;
    pair<int, int> range = get(u, v);
    if (range.first == -1) {
      continue;
    }
    if (i == 153 && n == 15) {
      cout << u << " " << v << " " << l << " " << r << " " << range.first << " "
           << range.second << endl;
    }
    queries[range.second].push_back({l, r, i, 1});
    if (range.first > 0) {
      queries[range.first - 1].push_back({l, r, i, -1});
    }
  }
  memset(f, 0, sizeof(f));
  for (int i = 0; i < sz; i++) {
    if (ind[ord[i]] != -1) {
      update(ind[ord[i]], 1);
    }
    for (auto x : queries[i]) {
      ans[x[2]] += x[3] * (query(x[1]) - query(x[0] - 1));
    }
  }
  for (int i = 1; i <= q; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}
