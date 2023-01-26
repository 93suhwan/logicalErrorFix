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
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 1; ++j) {
      {
        int nxt = a[i][j + 1];
        bitset<4> left(a[i][j]);
        bitset<4> right(nxt);
        if (left[2] == 0 and right[0] == 0) {
          d.merge(i * m + j, i * m + (j + 1));
        }
      }
      {
        int nxt = a[i + 1][j];
        bitset<4> top(a[i][j]);
        bitset<4> down(nxt);
        if (top[1] == 0 and down[3] == 0) {
          d.merge(i * m + j, (i + 1) * m + j);
        }
      }
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; ++j) {
      {
        bitset<4> left(a[i][j - 1]);
        bitset<4> right(a[i][j]);
        if (left[2] == 0 and right[0] == 0) {
          d.merge(i * m + j, i * m + (j - 1));
        }
      }
      {
        bitset<4> top(a[i - 1][j]);
        bitset<4> down(a[i][j]);
        if (top[1] == 0 and down[3] == 0) {
          d.merge(i * m + j, (i - 1) * m + j);
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
