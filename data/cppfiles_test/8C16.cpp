#include <bits/stdc++.h>
using namespace std;
struct SegmentTreeNode {
  long long int valueSum;
  int height;
  int node;
  SegmentTreeNode() {
    valueSum = 0;
    height = INT_MAX / 2;
  }
  SegmentTreeNode(long long int valueSum, int height, int node) {
    this->valueSum = valueSum;
    this->height = height;
    this->node = node;
  }
};
SegmentTreeNode merge(SegmentTreeNode a, SegmentTreeNode b) {
  a.valueSum += b.valueSum;
  if (a.height >= b.height) a.node = b.node;
  a.height = min(a.height, b.height);
  return a;
}
SegmentTreeNode tree[4 * 3 * 100005];
void update(int n, int st, int en, int idx, SegmentTreeNode val) {
  if (st == en) {
    if (val.height == -1) val.height = tree[n].height;
    tree[n] = val;
    return;
  }
  int mid = (st + en) / 2, lc = 2 * n, rc = lc + 1;
  if (idx <= mid)
    update(lc, st, mid, idx, val);
  else
    update(rc, mid + 1, en, idx, val);
  tree[n] = merge(tree[lc], tree[rc]);
}
SegmentTreeNode query(int n, int st, int en, int l, int r) {
  if (r < st || en < l) return SegmentTreeNode();
  if (l <= st && en <= r) return tree[n];
  int mid = (st + en) / 2, lc = 2 * n, rc = lc + 1;
  auto q1 = query(lc, st, mid, l, r);
  auto q2 = query(rc, mid + 1, en, l, r);
  return merge(q1, q2);
}
int dfsTime;
int starTime[3 * 100005];
int endTime[3 * 100005];
int value[3 * 100005];
vector<int> v[3 * 100005];
void dfs(int node, int height = 0, int par = 1) {
  starTime[node] = dfsTime++;
  update(1, 1, 3 * 100005, starTime[node], {value[node], height, node});
  for (auto child : v[node]) {
    if (child == par) continue;
    dfs(child, height + 1, node);
    update(1, 1, 3 * 100005, dfsTime, {0, height, node});
    dfsTime++;
  }
  endTime[node] = dfsTime++;
  update(1, 1, 3 * 100005, endTime[node], {-value[node], height, node});
}
void init() { dfsTime = 1; }
int getLCA(int a, int b) {
  if (starTime[a] > starTime[b]) swap(a, b);
  SegmentTreeNode q = query(1, 1, 3 * 100005, starTime[a], starTime[b]);
  return q.node;
}
void update(int node, int newValue) {
  value[node] = newValue;
  update(1, 1, 3 * 100005, starTime[node], {value[node], -1, node});
  update(1, 1, 3 * 100005, endTime[node], {-value[node], -1, node});
}
long long int getPathSum(int a, int b) {
  int lca = getLCA(a, b);
  long long int aSum =
      query(1, 1, 3 * 100005, starTime[lca], starTime[a]).valueSum;
  long long int bSum =
      query(1, 1, 3 * 100005, starTime[lca], starTime[b]).valueSum;
  return aSum + bSum - value[lca];
}
int main() {
  init();
  int a, b, n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i < n + 1; i++) {
    scanf("%d", &value[i]);
    value[i] = abs(value[i]);
  }
  for (int i = 0; i < n - 1; i++) {
    scanf("%d %d", &a, &b);
    v[a].push_back(b);
    v[b].push_back(a);
  }
  dfs(1);
  int op;
  while (q--) {
    scanf("%d %d %d", &op, &a, &b);
    if (op == 2)
      printf("%lld\n", 2 * getPathSum(a, b) - value[a] - value[b]);
    else
      update(a, abs(b));
  }
  return 0;
}
