#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
struct union_find {
  vector<int> par;
  void init(int size) {
    par.resize(size);
    for (int i = 0; i < size; i++) {
      par[i] = i;
    }
  }
  int find(int x) { return x == par[x] ? x : par[x] = find(par[x]); }
  void merge(int x, int y) { par[find(x)] = find(y); }
};
int N, M;
unordered_map<int, int> weight[MAXN];
vector<int> adj[MAXN];
int parity[MAXN];
union_find uf;
void add_parity_info(int x, int y, int p) {
  if (p) {
    uf.merge(2 * x, 2 * y + 1);
    uf.merge(2 * x + 1, 2 * y);
  } else {
    uf.merge(2 * x, 2 * y);
    uf.merge(2 * x + 1, 2 * y + 1);
  }
}
void cleanup() {
  for (int i = 0; i < N; i++) {
    weight[i].clear();
    adj[i].clear();
  }
}
void dfs(int x, int p) {
  for (int y : adj[x]) {
    if (y == p) continue;
    int &ref = weight[x][y];
    if (ref == -1) {
      ref = weight[y][x] = parity[y] ^ parity[x];
    }
    dfs(y, x);
  }
}
void solve() {
  cin >> N >> M;
  uf.init(2 * N);
  for (int i = 0; i < N - 1; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    x--;
    y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
    weight[x][y] = weight[y][x] = w;
    if (w != -1) {
      int p = __builtin_popcount(w) % 2;
      add_parity_info(x, y, w);
    }
  }
  for (int i = 0; i < M; i++) {
    int x, y, p;
    cin >> x >> y >> p;
    x--;
    y--;
    add_parity_info(x, y, p);
  }
  for (int i = 0; i < N; i++) {
    if (uf.find(2 * i) == uf.find(2 * i + 1)) {
      cout << "NO\n";
      return;
    }
  }
  vector<vector<int>> nodes(2 * N);
  for (int i = 0; i < 2 * N; i++) {
    nodes[uf.find(i)].push_back(i);
  }
  for (int i = 0; i < N; i++) {
    parity[i] = -1;
  }
  for (int node : nodes[uf.find(0)]) {
    parity[node / 2] = node % 2;
  }
  for (int i = 1; i < N; i++) {
    if (parity[i] != -1) continue;
    for (int node : nodes[uf.find(2 * i)]) {
      parity[node / 2] = node % 2;
    }
  }
  dfs(0, -1);
  cout << "YES\n";
  for (int x = 0; x < N; x++) {
    for (int y : adj[x]) {
      if (x < y) {
        cout << x + 1 << ' ' << y + 1 << ' ' << weight[x][y] << '\n';
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
    cleanup();
  }
}
