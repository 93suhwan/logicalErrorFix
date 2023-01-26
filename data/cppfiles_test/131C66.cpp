#include <bits/stdc++.h>
using namespace std;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
unordered_set<int, custom_hash> vtxs;
unordered_map<int, vector<int>, custom_hash> adj;
int parent(int k) {
  if (k <= 1) return 0;
  return (1 << (32 - __builtin_clz(k - 1))) - k;
}
int lca(int x, int y) {
  if (x == y) return x;
  if (x > y) swap(x, y);
  return lca(x, parent(y));
}
pair<int, int> farthest(int v, int p) {
  pair<int, int> ans = {0, v};
  for (int u : adj[v]) {
    if (u != p) {
      pair<int, int> s = farthest(u, v);
      s.first++;
      ans = max(ans, s);
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int root = a[0];
  for (int i = 1; i < n; i++) {
    root = lca(root, a[i]);
  }
  vtxs.insert(root);
  for (int x : a) {
    while (x != root) {
      vtxs.insert(x);
      x = parent(x);
    }
  }
  for (int x : vtxs) {
    if (x != root) {
      int y = parent(x);
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
  }
  pair<int, int> first_end = farthest(root, root);
  pair<int, int> second_end = farthest(first_end.second, first_end.second);
  int u, v;
  for (int i = 0; i < n; i++) {
    if (a[i] == first_end.second) u = i + 1;
    if (a[i] == second_end.second) v = i + 1;
  }
  cout << u << ' ' << v << ' ' << second_end.first << endl;
}
