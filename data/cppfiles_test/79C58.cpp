#include <bits/stdc++.h>
using namespace std;
class SegmentTree {
 private:
  int n_leaves, first_leaf, n_nodes;
  vector<bool> tree;
  void get_range_impl(int l, int r, vector<int>& inds, int ss, int se, int si) {
    if ((ss >= r) || (se <= l)) return;
    if ((ss >= l) && (se <= r) && !tree[si]) return;
    if ((se - ss) == 1) {
      inds.push_back(si - first_leaf);
      return;
    }
    int mid = (ss + se) >> 1;
    get_range_impl(l, r, inds, ss, mid, si * 2 + 1);
    get_range_impl(l, r, inds, mid, se, si * 2 + 2);
  }

 public:
  SegmentTree(int n) {
    int depth = 0;
    while ((1 << depth) < n) depth++;
    n_leaves = 1 << depth;
    first_leaf = n_leaves - 1;
    n_nodes = n_leaves + first_leaf;
    tree.resize(n_nodes, false);
    for (int i = 0; i < n; ++i) {
      tree[first_leaf + i] = true;
    }
    for (int i = first_leaf - 1; i >= 0; --i) {
      tree[i] = tree[i * 2 + 1] || tree[i * 2 + 2];
    }
  }
  void set(int i) {
    int node = first_leaf + i;
    tree[first_leaf + i] = false;
    while (node > 0) {
      node = (node - 1) >> 1;
      tree[node] = tree[node * 2 + 1] || tree[node * 2 + 2];
    }
  }
  vector<int> get_range(int l, int r) {
    vector<int> inds;
    get_range_impl(l, r, inds, 0, n_leaves, 0);
    return inds;
  }
};
vector<int> solve(const vector<int>& a, const vector<int>& b) {
  const int INF = 1e9;
  int n = a.size();
  vector<int> q;
  q.reserve(n + 1);
  q.push_back(n);
  vector<int> dist(n + 1, INF);
  dist[n] = 0;
  SegmentTree segtree(n + 1);
  segtree.set(n);
  vector<int> prv(n + 1, -1);
  for (int i = 0; i < int(q.size()); ++i) {
    int cur = q[i];
    if (cur == 0) {
      vector<int> pth;
      while (cur < n) {
        pth.push_back(cur);
        cur = prv[cur];
      }
      reverse(pth.begin(), pth.end());
      return pth;
    }
    int orig = cur;
    cur += b[cur - 1];
    vector<int> inds = segtree.get_range(cur - a[cur - 1], cur);
    for (int j : inds) {
      dist[j] = dist[cur] + 1;
      prv[j] = orig;
      segtree.set(j);
      q.push_back(j);
    }
  }
  return {};
}
void test_case() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  vector<int> ans = solve(a, b);
  if (ans.empty()) {
    cout << "-1\n";
  } else {
    int k = ans.size();
    cout << k << "\n";
    for (int i = 0; i < k; ++i) {
      if (i > 0) cout << " ";
      cout << ans[i];
    }
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  test_case();
}
