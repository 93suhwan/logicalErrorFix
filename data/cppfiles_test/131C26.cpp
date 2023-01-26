#include <bits/stdc++.h>
using namespace std;
const int MOD = 2004010501;
template <typename T>
void maximize(T& var, const T& val) {
  if (val > var) var = val;
}
const int LOG = 31;
const int N = 2e5 + 100;
const int TREE = LOG * N;
const int root = 0;
vector<int> adj[TREE];
int depth[TREE], idx[TREE];
pair<int, int> ans[TREE];
int insert(const vector<int>& a, int i) {
  int node = root;
  for (auto child : a) depth[child] = depth[node] + 1, node = child;
  idx[node] = i;
  ans[node] = make_pair(depth[node], i);
  return node;
}
void dfs(int u) {
  for (auto v : adj[u]) dfs(v), maximize(ans[u], ans[v]);
}
pair<int, int> query(const vector<int>& a, int u) {
  pair<int, int> res;
  int node = root;
  for (auto child : a) {
    pair<int, int> other_branch;
    for (auto v : adj[node])
      if (v != child) maximize(other_branch, ans[v]);
    if (other_branch.first) {
      int dist = depth[u] + other_branch.first - 2 * depth[node];
      maximize(res, make_pair(dist, other_branch.second));
    }
    if (idx[node]) maximize(res, make_pair(depth[u] - depth[node], idx[node]));
    node = child;
  }
  maximize(res, make_pair(ans[u].first - depth[u], ans[u].second));
  return res;
}
vector<int> all;
int get_index(int x) {
  return lower_bound(all.begin(), all.end(), x) - all.begin();
}
vector<int> a[N];
int label[N];
int main() {
  cerr << "test " << (1 << 30) << '\n';
  int num_elems;
  scanf("%d", &num_elems);
  all.push_back(0);
  for (int i = 1; i <= num_elems; i++) {
    int val;
    scanf("%d", &val);
    while (val > 0) {
      a[i].push_back(val);
      all.push_back(val);
      for (int tier = 0; tier < LOG; tier++)
        if ((1 << tier) >= val) {
          val = (1 << tier) - val;
          break;
        }
    }
    reverse(a[i].begin(), a[i].end());
  }
  sort(all.begin(), all.end());
  all.resize(unique(all.begin(), all.end()) - all.begin());
  for (int i = 1; i <= num_elems; i++) {
    for (auto& x : a[i]) x = get_index(x);
    const int n = a[i].size();
    if (n) adj[0].push_back(a[i][0]);
    for (int j = 0; j + 1 < n; j++) adj[a[i][j]].push_back(a[i][j + 1]);
  }
  int num_nodes = all.size();
  for (int i = 0; i < num_nodes; i++) {
    sort(adj[i].begin(), adj[i].end());
    adj[i].resize(unique(adj[i].begin(), adj[i].end()) - adj[i].begin());
  }
  for (int i = 1; i <= num_elems; i++) label[i] = insert(a[i], i);
  dfs(root);
  int u = -1;
  pair<int, int> res;
  for (int i = 1; i <= num_elems; i++) {
    auto get = query(a[i], label[i]);
    if (get.first > res.first) res = get, u = i;
  }
  printf("%d %d %d", u, res.second, res.first);
}
