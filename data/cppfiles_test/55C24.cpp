#include <bits/stdc++.h>
const int32_t INF = 2e9;
const int32_t MAX_N = 6e5;
template <typename T>
struct SegmentTree {
  int32_t treeSize;
  T data[4 * MAX_N + 5], lazy[4 * MAX_N + 5];
  void init(int32_t _treeSize) { treeSize = _treeSize; }
  void push_lazy(int32_t node, int32_t low, int32_t high) {
    if (lazy[node].first == 0) {
      return;
    }
    data[node] = lazy[node];
    if (low != high) {
      lazy[2 * node] = lazy[node];
      lazy[2 * node + 1] = lazy[node];
    }
    lazy[node] = {0, 0};
  }
  void update(int32_t node, int32_t low, int32_t high, int32_t qLow,
              int32_t qHigh, T qVal) {
    push_lazy(node, low, high);
    if (low > qHigh || high < qLow) {
      return;
    }
    if (low >= qLow && high <= qHigh) {
      lazy[node] = qVal;
      push_lazy(node, low, high);
      return;
    }
    int32_t mid = ((low + high) >> 1);
    update((node << 1), low, mid, qLow, qHigh, qVal);
    update((node << 1) + 1, mid + 1, high, qLow, qHigh, qVal);
    data[node] = std::max(data[(node << 1)], data[(node << 1) + 1]);
  }
  void update(int32_t low, int32_t high, T val) {
    update(1, 1, treeSize, low, high, val);
  }
  T query(int32_t node, int32_t low, int32_t high, int32_t qLow,
          int32_t qHigh) {
    push_lazy(node, low, high);
    if (low > qHigh || high < qLow) {
      return {-INF, 0};
    }
    if (low >= qLow && high <= qHigh) {
      return data[node];
    }
    int32_t mid = ((low + high) >> 1);
    return std::max(query((node << 1), low, mid, qLow, qHigh),
                    query((node << 1) + 1, mid + 1, high, qLow, qHigh));
  }
  T query(int32_t low, int32_t high) {
    return query(1, 1, treeSize, low, high);
  }
};
SegmentTree<std::pair<int32_t, int32_t> > segTree;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int32_t n, m;
  std::cin >> n >> m;
  std::set<int32_t> rows;
  std::map<int32_t, std::vector<std::pair<int32_t, int32_t> > > segments;
  std::set<int32_t> indices;
  std::vector<int32_t> row(m), ls(m), rs(m);
  for (int32_t i = 0; i < m; i++) {
    std::cin >> row[i] >> ls[i] >> rs[i];
    indices.insert(ls[i]);
    indices.insert(rs[i]);
    rows.insert(row[i]);
  }
  std::map<int32_t, int32_t> encoded;
  int32_t nxt = 1;
  for (auto &x : indices) {
    encoded[x] = nxt++;
  }
  segTree.init(nxt - 1);
  for (int32_t i = 0; i < m; i++) {
    segments[row[i]].push_back(std::make_pair(encoded[ls[i]], encoded[rs[i]]));
  }
  std::map<int32_t, int32_t> prevRow;
  for (auto &r : rows) {
    std::pair<int32_t, int32_t> currMax = {0, 0};
    for (auto &s : segments[r]) {
      auto curr = segTree.query(s.first, s.second);
      curr.first++;
      currMax = std::max(curr, currMax);
    }
    prevRow[r] = currMax.second;
    for (auto &s : segments[r]) {
      segTree.update(s.first, s.second, std::make_pair(currMax.first, r));
    }
  }
  auto ans = segTree.query(1, MAX_N);
  std::cout << n - ans.first << '\n';
  if (n - ans.first == 0) {
    return 0;
  }
  int32_t r = n + 1, nxtR = ans.second;
  while (r > 0) {
    while (r > nxtR) {
      r--;
      if (r != nxtR) {
        std::cout << r << " ";
      }
    }
    nxtR = prevRow[nxtR];
  }
  std::cout << '\n';
}
