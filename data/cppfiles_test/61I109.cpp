#include <bits/stdc++.h>
using namespace std;
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
void file() {}
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
}
template <typename T>
class fenwick_tree {
  int n;
  vector<T> x, y;
  T getAccum(vector<T>& BIT, int idx) {
    T sum = 0;
    while (idx) {
      sum += BIT[idx];
      idx -= (idx & -idx);
    }
    return sum;
  }
  void add(vector<T>& BIT, int idx, T val) {
    assert(idx != 0);
    while (idx <= n) {
      BIT[idx] += val;
      idx += (idx & -idx);
    }
  }
  T prefix_sum(int idx) { return getAccum(x, idx) * idx - getAccum(y, idx); }

 public:
  fenwick_tree(int n) : n(n), x(n + 1), y(n + 1) {}
  void update_range(int l, int r, T val) {
    if (l > r) return;
    add(x, l, val);
    add(x, r + 1, -val);
    add(y, l, val * (l - 1));
    add(y, r + 1, -val * r);
  }
  T range_sum(int l, int r) { return prefix_sum(r) - prefix_sum(l - 1); }
};
struct Node {
  long long val, lazy, leaf;
  Node() { val = lazy = leaf = 0; }
  static Node merge(const Node& L, const Node& R) {
    Node ret;
    ret.val = (L.val + R.val);
    ret.leaf = (L.leaf + R.leaf);
    return ret;
  }
};
template <typename Node>
class SegmentTree {
 private:
  int leftRange, rightRange;
  vector<Node> tree;
  void unLockLazy(int segIdx, int startNode, int endNode) {
    if (!tree[segIdx].lazy) return;
    tree[segIdx].val += tree[segIdx].leaf * 1LL * tree[segIdx].lazy;
    if (startNode == endNode) {
      tree[segIdx].lazy = 0;
      return;
    }
    tree[(segIdx << 1)].lazy = (tree[(segIdx << 1)].lazy + tree[segIdx].lazy);
    tree[(segIdx << 1 | 1)].lazy =
        (tree[(segIdx << 1 | 1)].lazy + tree[segIdx].lazy);
    tree[segIdx].lazy = 0;
  }
  template <typename T>
  void update(int segIdx, int startNode, int endNode, int qS, int qE, T qVal) {
    unLockLazy(segIdx, startNode, endNode);
    if (qE < startNode || qS > endNode) return;
    if (qS <= startNode && qE >= endNode) {
      tree[segIdx].lazy += qVal;
      unLockLazy(segIdx, startNode, endNode);
      return;
    }
    update((segIdx << 1), startNode, (startNode + ((endNode - startNode) >> 1)),
           qS, qE, qVal);
    update((segIdx << 1 | 1), (startNode + ((endNode - startNode) >> 1)) + 1,
           endNode, qS, qE, qVal);
    tree[segIdx] = Node::merge(tree[(segIdx << 1)], tree[(segIdx << 1 | 1)]);
  }
  Node query(int segIdx, int startNode, int endNode, int qS, int qE) {
    unLockLazy(segIdx, startNode, endNode);
    if (qS <= startNode && qE >= endNode) return tree[segIdx];
    if (qE <= (startNode + ((endNode - startNode) >> 1)))
      return query((segIdx << 1), startNode,
                   (startNode + ((endNode - startNode) >> 1)), qS, qE);
    if (qS > (startNode + ((endNode - startNode) >> 1)))
      return query((segIdx << 1 | 1),
                   (startNode + ((endNode - startNode) >> 1)) + 1, endNode, qS,
                   qE);
    return Node::merge(
        query((segIdx << 1), startNode,
              (startNode + ((endNode - startNode) >> 1)), qS, qE),
        query((segIdx << 1 | 1), (startNode + ((endNode - startNode) >> 1)) + 1,
              endNode, qS, qE));
  }
  void update_leaf(int segIdx, int startNode, int endNode, int qS, int qE) {
    unLockLazy(segIdx, startNode, endNode);
    if (qE < startNode || qS > endNode) return;
    if (qS <= startNode && qE >= endNode) {
      tree[segIdx].leaf = 1;
      return;
    }
    update_leaf((segIdx << 1), startNode,
                (startNode + ((endNode - startNode) >> 1)), qS, qE);
    update_leaf((segIdx << 1 | 1),
                (startNode + ((endNode - startNode) >> 1)) + 1, endNode, qS,
                qE);
    tree[segIdx] = Node::merge(tree[(segIdx << 1)], tree[(segIdx << 1 | 1)]);
  }

 public:
  void init(int l, int r) {
    leftRange = l, rightRange = r;
    tree = vector<Node>(abs(r - l + 1) << 2);
  }
  SegmentTree() {}
  SegmentTree(int l, int r) { init(l, r); }
  template <typename T>
  SegmentTree(int l, int r, const vector<T>& arr) {
    init(l, r);
    build(1, leftRange, rightRange, arr);
  }
  Node query(int qS, int qE) { return query(1, leftRange, rightRange, qS, qE); }
  template <typename T>
  void update(int qS, int qE, T val) {
    update(1, leftRange, rightRange, qS, qE, val);
  }
  void update_leaf(int qS, int qE) {
    update_leaf(1, leftRange, rightRange, qS, qE);
  }
};
void test_case() {
  int n;
  cin >> n;
  vector<vector<int> > adjL(n + 1);
  vector<pair<int, int> > v1;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    adjL[a].push_back(b);
    v1.push_back({a, b});
  }
  for (int i = 1; i <= n; i++) sort(adjL[i].begin(), adjL[i].end());
  fenwick_tree<long long> xx(n), xy(n);
  vector<int> fre(n + 1);
  long long cntfr = 0;
  SegmentTree<Node> yx(1, n);
  long long ans = 0;
  for (int i = n; i >= 1; i--) {
    for (auto& it : adjL[i]) {
      ans += xx.range_sum(1, n);
      ans += xy.range_sum(it, it);
      ans += yx.query(it, it).val;
    }
    for (auto& it : adjL[i]) {
      xx.update_range(it, it, fre[it]);
      xy.update_range(it, it, cntfr - fre[it]);
      yx.update(1, it - 1, 1);
      yx.update(it + 1, n, 1);
    }
    for (auto& it : adjL[i]) {
      if (fre[it] == 0) yx.update_leaf(it, it);
      fre[it]++;
      cntfr++;
    }
  }
  adjL = vector<vector<int> >(n + 1);
  for (auto& it : v1) adjL[it.second].push_back(it.first);
  for (int i = 1; i <= n; i++) sort(adjL[i].begin(), adjL[i].end());
  long long pir = 0, cnt = 0;
  for (int i = n; i >= 1; i--) {
    ans += (int)(adjL[i].size()) * pir;
    pir += (int)(adjL[i].size()) * cnt;
    cnt += (int)(adjL[i].size());
  }
  cout << ans << '\n';
}
int main() {
  file();
  fast();
  int t;
  cin >> t;
  while (t--) {
    test_case();
  }
  return 0;
}
