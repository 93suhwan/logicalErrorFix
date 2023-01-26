#include <bits/stdc++.h>
using namespace std;
struct dsu {
  struct node {
    int p, sz;
  };
  vector<node> nd;
  int cc;
  node &operator[](int id) { return nd[root(id)]; }
  explicit dsu(int n) : cc(n) {
    nd = vector<node>(n);
    for (int i = 0; i < n; i++) {
      nd[i].p = i;
      nd[i].sz = 1;
    }
  }
  inline int root(int u) {
    return (nd[u].p == u) ? u : nd[u].p = root(nd[u].p);
  }
  inline bool sameSet(int u, int v) { return root(u) == root(v); }
  void merge(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return;
    if (nd[u].sz < nd[v].sz) swap(u, v);
    nd[v].p = u;
    nd[u].sz += nd[v].sz;
    cc--;
  }
  inline int get_set_size(int u) { return nd[root(u)].sz; }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  dsu d(n * m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; ++j) {
      if (j + 1 < m) {
        bitset<4> left(a[i][j]);
        bitset<4> right(a[i][j + 1]);
        if (left[2] == 0 and right[0] == 0) {
          d.merge(m * i + j, m * i + (j + 1));
        }
      }
      if (i + 1 < n) {
        bitset<4> up(a[i][j]);
        bitset<4> down(a[i + 1][j]);
        if (up[1] == 0 and down[3] == 0) {
          d.merge(m * i + j, m * (i + 1) + j);
        }
      }
    }
  }
  set<int> has;
  for (int i = 0; i < n * m; i++) {
    has.insert(d.root(i));
  }
  vector<int> ans;
  for (int i : has) {
    ans.push_back(d.get_set_size(i));
  }
  sort(ans.rbegin(), ans.rend());
  for (int i : ans) {
    cout << i << " ";
  }
  cout << '\n';
  return 0;
}
