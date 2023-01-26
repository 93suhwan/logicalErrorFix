#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
int n, m, ls[maxn * 3], pos, dp[maxn], last[maxn];
bool vis[maxn];
int madoka[maxn];
struct Node {
  int l, r;
  Node() {}
  Node(int l, int r) : l(l), r(r) {}
};
struct node {
  int l, r, id;
  int val;
} fbk[maxn << 4];
struct LLL {
  int id;
  int w;
} lazy[maxn << 4];
void pushup(int x) {
  if (fbk[x << 1].val >= fbk[x << 1 | 1].val)
    fbk[x].id = fbk[x << 1].id;
  else
    fbk[x].id = fbk[x << 1 | 1].id;
  fbk[x].val = max(fbk[x << 1].val, fbk[x << 1 | 1].val);
  return;
}
void pushdown(int x) {
  if (lazy[x].w) {
    int w = lazy[x].w;
    int id = lazy[x].id;
    lazy[x].w = lazy[x].id = 0;
    if (w > lazy[x << 1].w) {
      lazy[x << 1].w = w;
      lazy[x << 1].id = id;
    }
    if (w > lazy[x << 1 | 1].w) {
      lazy[x << 1 | 1].w = w;
      lazy[x << 1 | 1].id = id;
    }
    if (w > fbk[x << 1].val) {
      fbk[x << 1].val = w;
      fbk[x << 1].id = id;
    }
    if (w > fbk[x << 1 | 1].val) {
      fbk[x << 1 | 1].val = w;
      fbk[x << 1 | 1].id = id;
    }
  }
  return;
}
void build(int l, int r, int x) {
  fbk[x].l = l;
  fbk[x].r = r;
  fbk[x].val = fbk[x].id = 0;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(l, mid, x << 1);
  build(mid + 1, r, x << 1 | 1);
  return;
}
node query(int L, int R, int x) {
  int l = fbk[x].l;
  int r = fbk[x].r;
  if (l >= L && r <= R) return fbk[x];
  pushdown(x);
  int mid = (l + r) >> 1;
  if (L > mid)
    return query(L, R, x << 1 | 1);
  else if (R <= mid)
    return query(L, R, x << 1);
  else {
    node a = query(L, mid, x << 1);
    node b = query(mid + 1, R, x << 1 | 1);
    if (a.val > b.val)
      return a;
    else
      return b;
  }
}
void update(int L, int R, int x, int Max, int idx) {
  int l = fbk[x].l;
  int r = fbk[x].r;
  if (l >= L && r <= R) {
    if (Max > lazy[x].w) {
      lazy[x].w = Max;
      lazy[x].id = idx;
    }
    if (Max > fbk[x].val) {
      fbk[x].val = Max;
      fbk[x].id = idx;
    }
    return;
  }
  pushdown(x);
  int mid = (l + r) >> 1;
  if (L > mid)
    update(L, R, x << 1 | 1, Max, idx);
  else if (R <= mid)
    update(L, R, x << 1, Max, idx);
  else {
    update(L, mid, x << 1, Max, idx);
    update(mid + 1, R, x << 1 | 1, Max, idx);
  }
  return;
}
vector<Node> E[maxn];
int main() {
  cin >> n >> m;
  int i, j, k, x, l, r;
  for (i = 1; i <= m; i++) {
    scanf("%d%d%d", &x, &l, &r);
    E[x].push_back(Node(l, r));
    ls[++pos] = l;
    ls[++pos] = r;
  }
  sort(ls + 1, ls + pos + 1);
  pos = unique(ls + 1, ls + pos + 1) - ls - 1;
  for (i = 1; i <= n; i++) {
    for (j = 0; j < E[i].size(); j++) {
      l = E[i][j].l;
      r = E[i][j].r;
      E[i][j].l = lower_bound(ls + 1, ls + pos + 1, l) - ls;
      E[i][j].r = lower_bound(ls + 1, ls + pos + 1, r) - ls;
    }
  }
  int ans = 0;
  build(1, pos, 1);
  for (i = 1; i <= n; i++) {
    dp[i] = 0;
    node t;
    t.id = 0;
    t.val = 1;
    for (j = 0; j < E[i].size(); j++) {
      l = E[i][j].l;
      r = E[i][j].r;
      node tt = query(l, r, 1);
      if (t.val < tt.val + 1) {
        t = tt;
        t.val++;
      }
    }
    dp[i] = t.val;
    last[i] = t.id;
    for (j = 0; j < E[i].size(); j++) {
      l = E[i][j].l;
      r = E[i][j].r;
      update(l, r, 1, dp[i], i);
    }
    ans = max(ans, dp[i]);
  }
  int root = 0;
  for (i = 1; i <= n; i++) {
    if (ans == dp[i]) {
      root = i;
      break;
    }
  }
  while (root != 0) {
    vis[root] = 1;
    root = last[root];
  }
  int len = 0;
  for (i = 1; i <= n; i++) {
    if (!vis[i]) madoka[++len] = i;
  }
  cout << len << endl;
  for (i = 1; i <= len; i++) printf(i == len ? "%d\n" : "%d ", madoka[i]);
  return 0;
}
