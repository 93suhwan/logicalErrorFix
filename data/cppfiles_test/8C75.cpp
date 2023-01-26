#include <bits/stdc++.h>
using namespace std;
const long long linf = 4000000000000000000LL;
const long long inf = 1000000007;
void pv(vector<int> a) {
  for (auto& x : a) cout << x << " ";
  cout << '\n';
}
void pv(vector<long long> a) {
  for (auto& x : a) cout << x << " ";
  cout << '\n';
}
void pv(vector<vector<int>> a) {
  for (int i = (0); i < (int(a.size())); ++i) {
    cout << i << '\n';
    pv(a[i]);
    cout << '\n';
  }
}
void pv(vector<vector<long long>> a) {
  for (int i = (0); i < (int(a.size())); ++i) {
    cout << i << '\n';
    pv(a[i]);
  }
  cout << '\n';
}
void pv(vector<string> a) {
  for (auto& x : a) cout << x << '\n';
  cout << '\n';
}
void setIO(string second) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
template <int SZ>
struct hld {
  struct item {
    long long sum;
  };
  item single(long long i) { return {i}; }
  item merge(item x, item y) {
    item ans;
    ans.sum = x.sum + y.sum;
    return ans;
  }
  vector<item> tree;
  vector<item> A;
  int height;
  item neutral = {0};
  void build(vector<item>& A, int v, int tl, int tr) {
    if (tl == tr)
      tree[v] = A[tl];
    else {
      int mid = (tl + tr) / 2;
      build(A, 2 * v + 1, tl, mid);
      build(A, 2 * v + 2, mid + 1, tr);
      tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
    }
  }
  void build(vector<long long>& B) {
    int n = B.size();
    height = log2(n + 1) + 1;
    A.resize(n);
    tree.resize((1 << height + 1) - 1);
    for (int i = (0); i < (n); ++i) A[i] = single(B[i]);
    A.resize(1 << height, neutral);
    build(A, 0, 0, (1 << height) - 1);
  }
  item query(int v, int tl, int tr, int l, int r) {
    if (r < tl || l > tr) return neutral;
    if (l <= tl && r >= tr) {
      return tree[v];
    }
    int mid = (tl + tr) / 2;
    return merge(query(2 * v + 1, tl, mid, l, r),
                 query(2 * v + 2, mid + 1, tr, l, r));
  }
  long long query(int l, int r) {
    return query(0, 0, (1 << height) - 1, l, r).sum;
  }
  void update(int v, int tl, int tr, int pos, item val) {
    if (tl == tr) {
      tree[v] = val;
    } else {
      int mid = (tl + tr) / 2;
      if (pos <= mid)
        update(2 * v + 1, tl, mid, pos, val);
      else
        update(2 * v + 2, mid + 1, tr, pos, val);
      tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
    }
  }
  void update(int pos, long long val) {
    update(0, 0, (1 << height) - 1, pos, single(val));
  }
  int n;
  vector<vector<int>> adj;
  vector<long long> a;
  vector<int> label, sizes, depth, heavy_child, parent, head, dist;
  vector<vector<int>> jump;
  int get(int a, int b) {
    for (int j = (0); j < (SZ); ++j) {
      if (b & (1 << j)) {
        a = jump[a][j];
      }
    }
    return a;
  }
  int LCA(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    a = get(a, depth[a] - depth[b]);
    if (a == b) return a;
    int j = SZ;
    while (j) {
      j--;
      int ta = jump[a][j], tb = jump[b][j];
      if (ta != tb) a = ta, b = tb;
    }
    return parent[a];
  }
  void dfs0(int i, int p) {
    parent[i] = p;
    sizes[i] = 1;
    for (auto& x : adj[i]) {
      if (x == p) continue;
      depth[x] = depth[i] + 1;
      dfs0(x, i);
      sizes[i] += sizes[x];
    }
  }
  int cur = 0;
  void dfs1(int i, int p) {
    label[i] = cur++;
    if (heavy_child[i] != -1) {
      head[heavy_child[i]] = head[i];
      dfs1(heavy_child[i], i);
      dist[i] = 1 + dist[heavy_child[i]];
    }
    for (auto& x : adj[i]) {
      if (x != heavy_child[i] && x != p) {
        head[x] = x;
        dfs1(x, i);
      }
    }
  }
  void init(vector<long long>& y, vector<vector<int>>& x) {
    adj = x;
    n = int(adj.size());
    a = y;
    sizes.resize(n);
    depth.resize(n);
    parent.resize(n);
    dfs0(0, -1);
    jump.resize(n, vector<int>(SZ));
    for (int i = (0); i < (n); ++i) jump[i][0] = parent[i];
    for (int i = (0); i < (SZ - 1); ++i) {
      for (int j = (0); j < (n); ++j)
        jump[j][i + 1] = (jump[j][i] == -1 ? -1 : jump[jump[j][i]][i]);
    }
    heavy_child.resize(n);
    for (int i = (0); i < (n); ++i) {
      vector<pair<int, int>> t;
      for (auto& x : adj[i])
        if (parent[i] != x) t.push_back({sizes[x], x});
      sort(t.begin(), t.end(), greater<pair<int, int>>());
      if (int(t.size()))
        heavy_child[i] = t[0].second;
      else
        heavy_child[i] = -1;
    }
    label.resize(n);
    head.resize(n);
    dist.resize(n);
    dfs1(0, -1);
    vector<long long> t(n);
    for (int i = (0); i < (n); ++i) t[label[i]] = y[i];
    build(t);
  }
  long long solve(int x, int l) {
    long long ans = 0;
    while (1) {
      if (x == l) return ans;
      if (head[x] == x) {
        ans += a[x];
        x = parent[x];
        continue;
      }
      int h = head[x];
      if (depth[h] > depth[l]) {
        ans += query(label[h], label[x]);
        x = parent[h];
        continue;
      }
      ans += query(label[l] + 1, label[x]);
      x = l;
    }
    return ans;
  }
  long long query_path(int x, int y) {
    int l = LCA(x, y);
    return solve(x, l) + solve(y, l) + a[l];
  }
  void update_path(int x, int y) {
    a[x] = y;
    update(label[x], y);
  }
};
int n, q;
vector<long long> a;
vector<vector<int>> adj;
int main() {
  setIO("test1");
  cin >> n >> q;
  a.resize(n);
  for (auto& x : a) cin >> x, x = abs(x);
  adj.resize(n);
  vector<long long> t(n);
  for (int i = (0); i < (n); ++i) t[i] = 2 * a[i];
  for (int i = (0); i < (n - 1); ++i) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  hld<20> g;
  g.init(t, adj);
  for (int i = (0); i < (q); ++i) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      y = abs(y);
      x--;
      a[x] = y;
      g.update_path(x, 2 * y);
    } else {
      x--, y--;
      cout << g.query_path(x, y) - a[x] - a[y] << '\n';
    }
  }
}
