#include <bits/stdc++.h>
using namespace std;
struct way {
  int a, b, x;
  way(int a, int b, int x) : a(a), b(b), x(x) {}
};
vector<vector<int>> tree;
vector<vector<int>> graph_diff;
vector<int> p;
int get(int v) {
  if (v == p[v]) return v;
  p[v] = get(p[v]);
  return p[v];
}
void merge(int u, int v) { p[get(v)] = get(u); }
vector<int> colors;
bool dfs(int v, int col) {
  colors[v] = col;
  for (int i : graph_diff[v]) {
    if (colors[i] == -1) {
      if (!dfs(i, 1 - col)) return false;
    } else if (colors[i] == col)
      return false;
  }
  return true;
}
map<pair<int, int>, int> reserved;
vector<int> val;
void gen_values(int v, int p) {
  if (p != -1) {
    if (reserved.count({v, p}) > 0) {
      cout << v + 1 << " " << p + 1 << " " << reserved[{v, p}] << "\n";
    } else if (reserved.count({p, v}) > 0) {
      cout << v + 1 << " " << p + 1 << " " << reserved[{p, v}] << "\n";
    } else {
      if (val[v] != val[p]) {
        cout << v + 1 << " " << p + 1 << " " << 1 << "\n";
      } else
        cout << v + 1 << " " << p + 1 << " " << 0 << "\n";
    }
  }
  for (int i : tree[v]) {
    if (i == p) continue;
    gen_values(i, v);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int useless = 0; useless < t; useless++) {
    reserved.clear();
    int n, m;
    cin >> n >> m;
    tree.assign(n, vector<int>());
    vector<way> ways;
    for (int i = 0; i < n - 1; i++) {
      int x, y, v;
      cin >> x >> y >> v;
      tree[x - 1].push_back(y - 1);
      tree[y - 1].push_back(x - 1);
      if (v != -1) {
        if (__builtin_popcount(v) % 2 == 0)
          ways.push_back(way(x - 1, y - 1, 0));
        else
          ways.push_back(way(x - 1, y - 1, 1));
        reserved[{x - 1, y - 1}] = v;
      }
    }
    for (int i = 0; i < m; i++) {
      int a, b, p;
      cin >> a >> b >> p;
      ways.push_back(way(a - 1, b - 1, p));
    }
    graph_diff.assign(n, vector<int>());
    p.assign(n, -1);
    for (int i = 0; i < n; i++) p[i] = i;
    for (auto w : ways) {
      if (w.x == 0) merge(w.a, w.b);
    }
    for (auto w : ways) {
      if (w.x == 1) {
        graph_diff[get(w.a)].push_back(get(w.b));
        graph_diff[get(w.b)].push_back(get(w.a));
      }
    }
    bool good = true;
    colors.assign(n, -1);
    for (int i = 0; i < n; i++) {
      if (colors[get(i)] == -1) {
        if (!dfs(get(i), 0)) {
          good = false;
          break;
        }
      }
    }
    if (!good) {
      cout << "NO\n";
      continue;
    }
    val.assign(n, 0);
    for (int i = 0; i < n; i++) {
      val[i] = colors[get(i)];
    }
    cout << "YES\n";
    gen_values(0, -1);
  }
}
