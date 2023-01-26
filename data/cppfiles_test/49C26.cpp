#include <bits/stdc++.h>
using namespace std;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
ostream &operator<<(ostream &os, min_heap<T> H) {
  while (!H.empty()) {
    os << H.top() << " ";
    H.pop();
  }
  os << "\n";
  return os << "";
}
template <typename T>
ostream &operator<<(ostream &os, max_heap<T> H) {
  while (!H.empty()) {
    os << H.top() << " ";
    H.pop();
  }
  os << "\n";
  return os << "";
}
template <typename F, typename S>
ostream &operator<<(ostream &os, pair<F, S> P) {
  return os << P.first << " " << P.second;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> arr) {
  for (int i = 0; i < (int)arr.size(); i++) {
    os << arr[i] << " ";
  }
  return os << "";
}
template <typename T>
ostream &operator<<(ostream &os, vector<vector<T>> matrix) {
  os << "\n";
  for (int i = 0; i < (int)matrix.size(); i++) {
    for (int j = 0; j < (int)matrix[i].size(); j++) {
      os << matrix[i][j] << " ";
    }
    os << "\n";
  }
  return os << "";
}
template <typename T>
ostream &operator<<(ostream &os, set<T> S) {
  for (auto s : S) {
    os << s << " ";
  }
  return os << "";
}
template <typename T>
ostream &operator<<(ostream &os, multiset<T> S) {
  for (auto s : S) {
    os << s << " ";
  }
  return os << "";
}
template <typename F, typename S>
ostream &operator<<(ostream &os, map<F, S> M) {
  os << "\n";
  for (auto m : M) {
    os << m << "\n";
  }
  return os << "";
}
template <typename F, typename S>
ostream &operator<<(ostream &os, multimap<F, S> M) {
  os << "\n";
  for (auto m : M) {
    os << m << "\n";
  }
  return os << "";
}
struct segment_tree {
  int N;
  int def_val;
  vector<int> tree;
  inline int merge_nodes(int left, int right) { return left + right; }
  segment_tree() {}
  segment_tree(int len, int val) {
    N = (1LL << (int)(ceill(log2(len))));
    def_val = val;
    tree.resize(N << 1, def_val);
  }
  segment_tree(vector<int> &elements, int val) {
    N = (1 << (int)(ceill(log2((int)elements.size()))));
    def_val = val;
    tree.resize(N << 1, def_val);
    for (int i = 0; i < (int)elements.size(); i++) {
      tree[N + i] = elements[i];
    }
    build_inner(1);
  }
  int query(int l, int r) { return query_inner(1, l, r, 0, N - 1); }
  int walk(int want) {
    int loc = 1;
    int has = 0;
    while (loc < N) {
      if (has + tree[2 * loc] >= want) {
        loc *= 2;
      } else {
        has += tree[2 * loc];
        loc = 2 * loc + 1;
      }
    }
    return loc - N;
  }
  void update(int pos, int val) {
    tree[N + pos] = val;
    update_inner((N + pos) >> 1);
  }
  void add(int pos, int val) {
    tree[N + pos] += val;
    update_inner((N + pos) >> 1);
  }

 private:
  int build_inner(int current_node) {
    if (current_node >= N) {
      return tree[current_node];
    }
    tree[current_node] = merge_nodes(build_inner((current_node << 1)),
                                     build_inner((current_node << 1) + 1));
    return tree[current_node];
  }
  void update_inner(int current_node) {
    if (current_node == 0) {
      return;
    }
    tree[current_node] =
        merge_nodes(tree[(current_node << 1)], tree[(current_node << 1) + 1]);
    update_inner((current_node >> 1));
  }
  int query_inner(int current_node, int query_l, int query_r, int tree_l,
                  int tree_r) {
    if (query_l <= tree_l && tree_r <= query_r) {
      return tree[current_node];
    }
    if (query_l > tree_r || query_r < tree_l) {
      return def_val;
    }
    int mid = ((tree_l + tree_r) >> 1);
    return merge_nodes(
        query_inner((current_node << 1), query_l, query_r, tree_l, mid),
        query_inner((current_node << 1) + 1, query_l, query_r, mid + 1,
                    tree_r));
  }
};
int n, q;
vector<vector<int>> adj;
vector<int> arr;
vector<set<int>> mp;
vector<vector<int>> query;
vector<int> ans;
vector<pair<int, int>> og;
void dfs(int node, int par, vector<int> &cnt, segment_tree &tree) {
  if (cnt[arr[node]] != 0) {
    mp[cnt[arr[node]]].erase(arr[node]);
    tree.add(cnt[arr[node]], -1);
  }
  cnt[arr[node]]++;
  mp[cnt[arr[node]]].insert(arr[node]);
  tree.add(cnt[arr[node]], 1);
  for (const auto &ind : query[node]) {
    int extra = tree.query(0, og[ind].first - 1);
    int want = extra + og[ind].second;
    if (tree.query(0, n) < want) {
      ans[ind] = -1;
    } else {
      ans[ind] = *mp[tree.walk(want)].begin();
    }
  }
  for (const auto &nxt : adj[node]) {
    if (nxt != par) {
      dfs(nxt, node, cnt, tree);
    }
  }
  mp[cnt[arr[node]]].erase(arr[node]);
  tree.add(cnt[arr[node]], -1);
  cnt[arr[node]]--;
  if (cnt[arr[node]] != 0) {
    mp[cnt[arr[node]]].insert(arr[node]);
    tree.add(cnt[arr[node]], 1);
  }
}
void solve() {
  adj.clear();
  arr.clear();
  mp.clear();
  query.clear();
  ans.clear();
  og.clear();
  cin >> n >> q;
  adj.resize(n + 1);
  arr.resize(n + 1);
  mp.resize(n + 1);
  query.resize(n + 1);
  ans.resize(q);
  og.resize(q);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    adj[p].push_back(i);
  }
  for (int i = 0; i < q; i++) {
    int v, l, k;
    cin >> v >> l >> k;
    og[i] = {l, k};
    query[v].push_back(i);
  }
  segment_tree tree(n + 1, 0);
  vector<int> cnt(n + 1);
  dfs(1, 0, cnt, tree);
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int no_of_testcases = 1;
  cin >> no_of_testcases;
  for (int i = 1; i <= no_of_testcases; i++) {
    solve();
  }
  return 0;
}
