#include <bits/stdc++.h>
struct SegTree {
  struct Node {
    int l = 0, r = 0;
    std::pair<int, int> v = {0, -1}, p = {0, -1};
  };
  std::vector<Node> tree = {{}, {}};
  void visit(int n, int l, int m, int r) {
    if (!tree[n].l && l <= m) tree[n].l = tree.size(), tree.emplace_back();
    if (!tree[n].r && m + 1 <= r) tree[n].r = tree.size(), tree.emplace_back();
    setMax(tree[n].l, l, m, l, r, tree[n].p);
    setMax(tree[n].r, m + 1, r, l, r, tree[n].p);
    tree[n].p = Node().p;
  }
  void setMax(int n, int l, int r, int lq, int rq, std::pair<int, int> v) {
    if (!n || r < lq || rq < l || rq < lq) {
      return;
    } else if (lq <= l && r <= rq) {
      tree[n].v = std::max(tree[n].v, v);
      tree[n].p = std::max(tree[n].p, v);
    } else {
      int m = l + (r - l) / 2;
      visit(n, l, m, r);
      setMax(tree[n].l, l, m, lq, rq, v);
      setMax(tree[n].r, m + 1, r, lq, rq, v);
      tree[n].v = std::max(tree[tree[n].l].v, tree[tree[n].r].v);
    }
  }
  std::pair<int, int> getMax(int n, int l, int r, int lq, int rq) {
    if (!n || r < lq || rq < l || rq < lq)
      return Node().v;
    else if (lq <= l && r <= rq)
      return tree[n].v;
    int m = l + (r - l) / 2;
    visit(n, l, m, r);
    return std::max(getMax(tree[n].l, l, m, lq, rq),
                    getMax(tree[n].r, m + 1, r, lq, rq));
  }
};
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  std::map<int, int> relpoint;
  std::vector<std::vector<std::pair<int, int>>> intervals(n + 1);
  for (int x = 0, i, l, r; x < m; ++x) {
    scanf("%d %d %d", &i, &l, &r);
    intervals[i].push_back({l, r});
    relpoint[l] = relpoint[r] = 0;
  }
  int points = 0;
  for (auto &kv : relpoint) kv.second = ++points;
  SegTree tree;
  std::vector<int> bptr(n + 1, -1);
  for (int row = 1; row <= n; ++row) {
    std::pair<int, int> dp = {0, -1};
    for (auto &lr : intervals[row])
      dp = std::max(dp, tree.getMax(1, 1, points, relpoint[lr.first],
                                    relpoint[lr.second]));
    for (auto &lr : intervals[row]) {
      tree.setMax(1, 1, points, relpoint[lr.first], relpoint[lr.second],
                  {dp.first + 1, row});
    }
    bptr[row] = dp.second;
  }
  auto ans = tree.getMax(1, 1, points, 1, points);
  printf("%d\n", n - ans.first);
  for (int i = ans.second, j; i != -1;) i = bptr[j = i], bptr[j] = 0;
  for (int row = 1; row <= n; ++row)
    if (bptr[row] != 0) printf("%d ", row);
  if (ans.first != n) printf("\n");
}
