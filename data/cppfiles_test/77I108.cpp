#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() { cerr << "\e[39m" << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
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
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  dsu d(n * m);
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  auto ok = [&](int x, int y) {
    if (x < 0 or y < 0 or x >= n or y >= m) return false;
    return true;
  };
  auto no_wall = [&](int x, int y, int nx, int ny) {
    if (x != nx) {
      assert(y == ny);
      if (x > nx) {
        swap(x, nx);
        swap(y, ny);
      }
      bitset<4> up(a[x][y]);
      bitset<4> down(a[nx][ny]);
      if (up[1] == 0 and down[3] == 0) {
        return true;
      }
    } else {
      assert(x == nx);
      if (y > ny) {
        swap(x, nx);
        swap(y, ny);
      }
      bitset<4> left(a[x][y]);
      bitset<4> right(a[nx][ny]);
      if (left[2] == 0 and right[0] == 0) {
        return true;
      }
    }
    return false;
  };
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k < 4; ++k) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (ok(ni, nj)) {
          if (no_wall(i, j, ni, nj)) {
            d.merge(m * i + j, m * ni + nj);
          }
        }
      }
    }
  }
  set<int> roots;
  for (int i = 0; i < n * m; i++) {
    roots.insert(d.root(i));
  }
  vector<int> ans;
  for (int root : roots) {
    ans.push_back(d.get_set_size(root));
  }
  sort(ans.rbegin(), ans.rend());
  for (int i = 0; i < (int)ans.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << ans[i];
  }
  cout << '\n';
  return 0;
}
