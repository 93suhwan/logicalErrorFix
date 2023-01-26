#include <bits/stdc++.h>
struct Node {
  int l = 0, r = 0;
  std::pair<int, int> v = {0, 0}, p = {0, 0};
} static_tree[(int)1e7];
struct SegTree {
  Node *t = static_tree;
  int sz = 2;
  SegTree() { t[0] = t[1] = Node(); }
  inline void visit(int n, int l, int m, int r) {
    if (l <= m) {
      if (!t[n].l) t[n].l = sz++, t[t[n].l] = Node();
      t[t[n].l].v = std::max(t[t[n].l].v, t[n].p);
      t[t[n].l].p = std::max(t[t[n].l].p, t[n].p);
    }
    if (m + 1 <= r) {
      if (!t[n].r) t[n].r = sz++, t[t[n].r] = Node();
      t[t[n].r].v = std::max(t[t[n].r].v, t[n].p);
      t[t[n].r].p = std::max(t[t[n].r].p, t[n].p);
    }
    t[n].p = {0, 0};
  }
  std::pair<int, int> query(int n, int l, int r, int lq, int rq) {
    if (r < lq || rq < l)
      return {0, 0};
    else if (lq <= l && r <= rq)
      return t[n].v;
    int m = l + (r - l) / 2;
    visit(n, l, m, r);
    return std::max(query(t[n].l, l, m, lq, rq),
                    query(t[n].r, m + 1, r, lq, rq));
  }
  void update(int n, int l, int r, int lq, int rq, std::pair<int, int> mx) {
    if (r < lq || rq < l) {
      return;
    } else if (lq <= l && r <= rq) {
      t[n].v = std::max(t[n].v, mx);
      t[n].p = std::max(t[n].p, mx);
    } else {
      int m = l + (r - l) / 2;
      visit(n, l, m, r);
      update(t[n].l, l, m, lq, rq, mx);
      update(t[n].r, m + 1, r, lq, rq, mx);
      t[n].v = std::max(t[t[n].l].v, t[t[n].r].v);
    }
  }
};
int bptr[(int)3e5 + 10]{};
std::vector<std::pair<int, int>> intervals[(int)3e5 + 10];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int x = 0; x < m; ++x) {
    int i, l, r;
    scanf("%d %d %d", &i, &l, &r);
    intervals[i].push_back({l, r});
  }
  SegTree tree;
  for (int i = 1; i <= n; ++i) {
    if (!intervals[i].size()) {
      bptr[i] = -1;
      continue;
    }
    auto &v = intervals[i];
    std::vector<std::pair<int, int>> merged;
    std::sort(v.begin(), v.end(), std::greater<std::pair<int, int>>{});
    while (!v.empty()) {
      int l = v.back().first, r = v.back().second;
      v.pop_back();
      while (!v.empty() && v.back().first <= r) {
        r = std::max(r, v.back().second);
        v.pop_back();
      }
      merged.push_back({l, r});
    }
    std::pair<int, int> dp = {0, 0};
    for (auto &lr : merged) {
      int l = lr.first, r = lr.second;
      dp = std::max(dp, tree.query(1, 1, 1e9 + 10, l, r));
    }
    for (auto &lr : merged) {
      int l = lr.first, r = lr.second;
      tree.update(1, 1, 1e9 + 10, l, r, {dp.first + 1, i});
    }
    bptr[i] = dp.second == 0 ? -1 : dp.second;
  }
  int ans = 0;
  for (int i = tree.query(1, 1, 1e9 + 10, 1, 1e9 + 10).second; i != -1; ++ans) {
    int j = i;
    i = bptr[i];
    bptr[j] = 0;
  }
  printf("%d\n", n - ans);
  if (ans != n) {
    for (int i = 1; i <= n; ++i)
      if (bptr[i] != 0) printf("%d ", i);
    printf("\n");
  }
}
