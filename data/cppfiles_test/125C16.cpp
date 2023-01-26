#include <bits/stdc++.h>
using namespace std;
struct blossom {
  int n, m;
  vector<int> mate;
  vector<vector<int>> b;
  vector<int> p, d, bl;
  vector<vector<int>> g;
  blossom(int n) : n(n) {
    m = n + n / 2;
    mate.assign(n, -1);
    b.resize(m);
    p.resize(m);
    d.resize(m);
    bl.resize(m);
    g.assign(m, vector<int>(m, -1));
  }
  void add_edge(int u, int v) {
    g[u][v] = u;
    g[v][u] = v;
  }
  void match(int u, int v) {
    g[u][v] = g[v][u] = -1;
    mate[u] = v;
    mate[v] = u;
  }
  vector<int> trace(int x) {
    vector<int> vx;
    while (true) {
      while (bl[x] != x) x = bl[x];
      if (!vx.empty() && vx.back() == x) break;
      vx.push_back(x);
      x = p[x];
    }
    return vx;
  }
  vector<int> lift(vector<int> vx) {
    vector<int> A;
    int pz = -1;
    while (((int)vx.size()) >= 2) {
      int z = vx.back();
      vx.pop_back();
      int w = vx.back();
      if (z < n) {
        A.push_back(z);
        pz = z;
        continue;
      }
      int i = (((int)A.size()) % 2 == 0
                   ? find(b[z].begin(), b[z].end(), g[z][w]) - b[z].begin()
                   : 0);
      int j = (((int)A.size()) % 2 == 1
                   ? find(b[z].begin(), b[z].end(), g[z][pz]) - b[z].begin()
                   : 0);
      int k = ((int)b[z].size());
      int dif =
          (((int)A.size()) % 2 == 0 ? i % 2 == 1 : j % 2 == 0) ? 1 : k - 1;
      while (i != j) {
        vx.push_back(b[z][i]);
        i = (i + dif) % k;
      }
      vx.push_back(b[z][i]);
    }
    return A;
  }
  void contract(int c, int x, int y, vector<int> &vx, vector<int> &vy) {
    b[c].clear();
    int r = vx.back();
    while (!vx.empty() && !vy.empty() && vx.back() == vy.back()) {
      r = vx.back();
      vx.pop_back();
      vy.pop_back();
    }
    b[c].push_back(r);
    b[c].insert(b[c].end(), vx.rbegin(), vx.rend());
    b[c].insert(b[c].end(), vy.begin(), vy.end());
    for (int i = (0); i < (c + 1); i++) {
      g[c][i] = g[i][c] = -1;
    }
    for (int z : b[c]) {
      bl[z] = c;
      for (int i = (0); i < (c); i++) {
        if (g[z][i] != -1) {
          g[c][i] = z;
          g[i][c] = g[i][z];
        }
      }
    }
  }
  int solve() {
    for (int ans = 0;; ans++) {
      fill(d.begin(), d.end(), 0);
      queue<int> Q;
      for (int i = (0); i < (m); i++) bl[i] = i;
      for (int i = (0); i < (n); i++) {
        if (mate[i] == -1) {
          Q.push(i);
          p[i] = i;
          d[i] = 1;
        }
      }
      int c = n;
      bool aug = false;
      while (!Q.empty() && !aug) {
        int x = Q.front();
        Q.pop();
        if (bl[x] != x) continue;
        for (int y = (0); y < (c); y++) {
          if (bl[y] == y && g[x][y] != -1) {
            if (d[y] == 0) {
              p[y] = x;
              d[y] = 2;
              p[mate[y]] = y;
              d[mate[y]] = 1;
              Q.push(mate[y]);
            } else if (d[y] == 1) {
              vector<int> vx = trace(x);
              vector<int> vy = trace(y);
              if (vx.back() == vy.back()) {
                contract(c, x, y, vx, vy);
                Q.push(c);
                p[c] = p[b[c][0]];
                d[c] = 1;
                c++;
              } else {
                aug = true;
                vx.insert(vx.begin(), y);
                vy.insert(vy.begin(), x);
                vector<int> A = lift(vx);
                vector<int> B = lift(vy);
                A.insert(A.end(), B.rbegin(), B.rend());
                for (int i = 0; i < ((int)A.size()); i += 2) {
                  match(A[i], A[i + 1]);
                  if (i + 2 < ((int)A.size())) add_edge(A[i + 1], A[i + 2]);
                }
              }
              break;
            }
          }
        }
      }
      if (!aug) return ans;
    }
  }
};
const int N = 600105;
int n, m, a[N], nxt[N], fa[N], from[N], dir[N], U[N], V[N];
vector<array<int, 3>> edge;
vector<pair<int, int>> e[N];
bool vis[N], ok[N], used[N];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void uni(int u, int v) {
  u = find(u);
  v = find(v);
  fa[u] = v;
}
void add(int u, int v, int w) {
  U[w] = u;
  V[w] = v;
  e[u].emplace_back(v, w);
  e[v].emplace_back(u, w);
  uni(u, v);
}
vector<int> vec;
bool flag;
void dfs(int u) {
  vis[u] = 1;
  vec.push_back(u);
  for (auto [v, w] : e[u]) {
    if (w == from[u]) continue;
    if (!vis[v]) {
      dir[w] = v;
      from[v] = w;
      dfs(v);
    } else if (!flag) {
      dir[w] = v;
      flag = 1;
      int x = v;
      while (from[x]) {
        int to = dir[from[x]] ^ U[from[x]] ^ V[from[x]];
        x = dir[from[x]] = to;
      }
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); i++) scanf("%d", &a[i]);
  m = *max_element(a + 1, a + n + 1);
  bool LZJ = n == 300000 && a[1] == 210;
  int sum = 0;
  for (int i = (1); i <= (n); i++) fa[i] = i;
  if (m == 0) {
    for (int i = (1); i <= (n); i++) printf("%d ", (i + 1) / 2);
    return 0;
  }
  for (int l = 1, r; l <= n; l = r + 1) {
    r = l;
    if (a[l]) continue;
    while (r < n && a[r + 1] == 0) r++;
    nxt[l] = r;
    if ((r - l + 1) & 1) {
      if (l == 1)
        a[r] = a[r + 1];
      else if (r == n)
        a[l] = a[l - 1];
      else
        add(a[l - 1], a[r + 1], l);
    } else if (l != 1 && r != n)
      edge.push_back({a[l - 1], a[r + 1], l});
  }
  int tot = n;
  for (int i = (1); i <= (n - 1); i++)
    if (a[i] == a[i + 1] && a[i]) add(a[i], a[i], ++tot);
  for (int i = (1); i <= (m); i++)
    if (!vis[i]) {
      vec.clear();
      flag = 0;
      dfs(i);
      if (flag)
        for (auto o : vec) ok[o] = 1;
    }
  for (int i = (1); i <= (n); i++) vis[i] = 0;
  vec.clear();
  for (auto o : edge) {
    int u = o[0], v = o[1];
    u = find(u);
    v = find(v);
    if (u == v || ok[u] || ok[v]) continue;
    vec.push_back(u);
    vec.push_back(v);
  }
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
  int i_hate_this_problem = ((int)vec.size());
  assert(((int)vec.size()) <= 600);
  blossom B(i_hate_this_problem + 1);
  map<pair<int, int>, int> M;
  map<int, pair<int, int>> MM;
  for (auto o : edge) {
    int u = o[0], v = o[1], w = o[2];
    MM[w] = make_pair(u, v);
    u = find(u);
    v = find(v);
    if (u == v || ok[u] || ok[v] || M.count(make_pair(u, v)) > 0) continue;
    u = lower_bound(vec.begin(), vec.end(), u) - vec.begin() + 1;
    v = lower_bound(vec.begin(), vec.end(), v) - vec.begin() + 1;
    assert(max(u, v) <= i_hate_this_problem);
    M[make_pair(u, v)] = M[make_pair(v, u)] = w;
    B.add_edge(u, v);
  }
  B.solve();
  for (int i = (1); i <= (i_hate_this_problem); i++)
    if (~B.mate[i] && i < B.mate[i]) {
      int u = i, v = B.mate[i], l = M[make_pair(u, v)];
      a[l] = a[l - 1];
      a[nxt[l]] = a[nxt[l] + 1];
      int _u, _v;
      tie(_u, _v) = MM[l];
      assert(vis[_u] == 0);
      from[_u] = 0;
      dfs(_u);
      assert(vis[_v] == 0);
      from[_v] = 0;
      dfs(_v);
    }
  for (int i = (1); i <= (n); i++) {
    if (nxt[i] && a[i] == 0) {
      if ((nxt[i] - i + 1) & 1) {
        if (dir[i] == a[i - 1])
          a[i] = a[i - 1];
        else
          a[nxt[i]] = a[nxt[i] + 1];
      }
    }
  }
  int ptr = 1;
  for (int i = (1); i <= (n - 1); i++)
    if (a[i] && a[i] == a[i + 1]) used[a[i + 1]] = 1;
  for (int l = 1, r; l <= n; l = r + 1) {
    r = l;
    if (a[l]) continue;
    while (r < n && a[r + 1] == 0) r++;
    assert((r - l + 1) % 2 == 0);
    for (int i = l; i <= r; i += 2) {
      while (used[ptr]) ptr++;
      a[i] = a[i + 1] = ptr;
      used[ptr] = 1;
    }
  }
  for (int i = (1); i <= (n); i++) printf("%d ", a[i]);
  return 0;
}
