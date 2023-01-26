#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 100;
const int MOD = 1e9 + 7;
int n, k, step = 0, ans = 0;
vector<int> lst;
int a[N], sz[N], huprev[N], used[N], hap[N], col[N], sum[N];
vector<pair<int, int> > g[N];
int fen_used[2][N];
pair<int, int> fen[2][N];
void init() {}
void dfs1(int v, int pv, int cur_hap, int cur_col, int last_col, int cur_sum) {
  used[v] = step;
  huprev[v] = pv;
  hap[v] = cur_hap;
  col[v] = cur_col;
  sum[v] = cur_sum;
  if (pv != -1) {
    lst.push_back(v);
  }
  for (const pair<int, int>& e : g[v]) {
    if (used[e.first] != step) {
      if (cur_col == -1) {
        assert(pv == -1);
        dfs1(e.first, e.first, (cur_hap + a[e.first]) % MOD, e.second, e.second,
             cur_sum);
      } else {
        assert(pv != -1);
        dfs1(e.first, pv, (cur_hap + a[e.first]) % MOD, cur_col, e.second,
             cur_sum + (e.second != last_col));
      }
    }
  }
}
pair<int, int> get(int c, int pos) {
  pair<int, int> res(0, 0);
  while (pos >= 0) {
    if (fen_used[c][pos] != step) {
      fen_used[c][pos] = step;
      fen[c][pos] = make_pair(0, 0);
    }
    res.first += fen[c][pos].first;
    if (res.first >= MOD) {
      res.first -= MOD;
    }
    res.second += fen[c][pos].second;
    pos = (pos & (pos + 1)) - 1;
  }
  return res;
}
void update(int c, int pos, pair<int, int> val) {
  while (pos < n) {
    if (fen_used[c][pos] != step) {
      fen_used[c][pos] = step;
      fen[c][pos] = make_pair(0, 0);
    }
    fen[c][pos].first += val.first;
    if (fen[c][pos].first >= MOD) {
      fen[c][pos].first -= MOD;
    }
    fen[c][pos].second += val.second;
    pos = (pos | (pos + 1));
  }
}
void dfs0(int v) {
  used[v] = step;
  sum[v] = 1;
  lst.push_back(v);
  for (const pair<int, int>& e : g[v]) {
    if (used[e.first] != step) {
      huprev[e.first] = v;
      dfs0(e.first);
      sum[v] += sum[e.first];
    }
  }
}
void solve(int v) {
  ++step;
  lst.clear();
  huprev[v] = -1;
  dfs0(v);
  pair<int, int> best(1e9, -1);
  for (int u : lst) {
    int sz = sum[v] - sum[u];
    for (const pair<int, int>& e : g[u]) {
      if (huprev[e.first] == u) {
        sz = max(sz, sum[e.first]);
      }
    }
    best = min(best, make_pair(sz, u));
  }
  v = best.second;
  ++step;
  lst.clear();
  dfs1(v, -1, 0, -1, -1, 0);
  ans = (ans + a[v]) % MOD;
  int i = 0;
  while (i < ((int)(lst).size())) {
    int j = i;
    while (j + 1 < ((int)(lst).size()) &&
           huprev[lst[i]] == huprev[lst[j + 1]]) {
      ++j;
    }
    for (int z = i; z <= j; ++z) {
      assert(sum[lst[z]] < n);
      if (sum[lst[z]] <= k) {
        ans = (ans + ll(hap[lst[z]]) + a[v]) % MOD;
      }
      pair<int, int> res = get(col[lst[z]], k - sum[lst[z]]);
      ans = (ans + res.first + ll(res.second) * (a[v] + hap[lst[z]])) % MOD;
      res = get(col[lst[z]] ^ 1, k - sum[lst[z]] - 1);
      ans = (ans + res.first + ll(res.second) * (a[v] + hap[lst[z]])) % MOD;
    }
    for (int z = i; z <= j; ++z) {
      update(col[lst[z]], sum[lst[z]], make_pair(hap[lst[z]], 1));
    }
    i = j + 1;
  }
  for (const pair<int, int>& e : g[v]) {
    g[e.first].erase(
        find((g[e.first]).begin(), (g[e.first]).end(), make_pair(v, e.second)));
    solve(e.first);
  }
}
void dfs2(int v, vector<bool>& used, vector<int>& huprev, vector<int>& prev_col,
          vector<int>& h) {
  used[v] = true;
  for (const pair<int, int>& e : g[v]) {
    if (!used[e.first]) {
      huprev[e.first] = v;
      h[e.first] = h[v] + 1;
      prev_col[e.first] = e.second;
      dfs2(e.first, used, huprev, prev_col, h);
    }
  }
}
int get_lca(const vector<int>& huprev, const vector<int>& h, int a, int b) {
  if (h[a] < h[b]) {
    swap(a, b);
  }
  while (h[a] > h[b]) {
    a = huprev[a];
  }
  assert(h[a] == h[b]);
  while (a != b) {
    assert(a != -1 && b != -1);
    a = huprev[a];
    b = huprev[b];
  }
  assert(a == b);
  assert(a != -1);
  return a;
}
pair<int, int> walk(const vector<int>& huprev, const vector<int>& prev_col,
                    int a, int c, int b) {
  int a_col = -1;
  int sum = ::a[c] % MOD, cnt = 0;
  while (a != c) {
    sum = (sum + ::a[a]) % MOD;
    if (a_col != -1 && a_col != prev_col[a]) {
      ++cnt;
    }
    a_col = prev_col[a];
    a = huprev[a];
  }
  assert(a == c);
  int b_col = -1;
  while (b != c) {
    sum = (sum + ::a[b]) % MOD;
    if (b_col != -1 && b_col != prev_col[b]) {
      ++cnt;
    }
    b_col = prev_col[b];
    b = huprev[b];
  }
  assert(b == c);
  if (a_col != -1 && b_col != -1 && a_col != b_col) {
    ++cnt;
  }
  return make_pair(sum, cnt);
}
int stup(int n) {
  int res2 = 0;
  vector<bool> used(n, false);
  vector<int> huprev(n, -1);
  vector<int> prev_col(n, -1);
  vector<int> h(n, 0);
  dfs2(0, used, huprev, prev_col, h);
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      int z = get_lca(huprev, h, i, j);
      pair<int, int> res = walk(huprev, prev_col, i, z, j);
      if (res.second <= k) {
        res2 = (res2 + res.first) % MOD;
      }
    }
  }
  return res2;
}
int get(vector<int>& p, int v) {
  if (p[v] == v) {
    return v;
  }
  return p[v] = get(p, p[v]);
}
void merge(vector<int>& p, vector<int>& r, int a, int b) {
  a = get(p, a);
  b = get(p, b);
  assert(a != b);
  if (r[a] < r[b]) {
    swap(a, b);
  }
  if (r[a] == r[b]) {
    ++r[a];
  }
  p[b] = a;
}
void solve() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    g[i].clear();
  }
  for (int i = 0; i < n - 1; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    --a;
    --b;
    g[a].push_back(make_pair(b, c));
    g[b].push_back(make_pair(a, c));
  }
  ans = 0;
  solve(0);
  printf("%d\n", ans);
}
int main() {
  init();
  int t = 1;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
