#include <bits/stdc++.h>
using namespace std;
int read() {
  char ch = getchar();
  int x = 1, s = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') x = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return x * s;
}
struct node {
  int maxn, minn;
  node *ls, *rs;
} pool[1200005 << 1], *root;
node *newnode() {
  static int cnt = 1;
  return &pool[cnt++];
}
node *build(int l, int r) {
  node *i = newnode();
  if (l < r) {
    i->ls = build(l, ((l + r) >> 1));
    i->rs = build(((l + r) >> 1) + 1, r);
  }
  i->maxn = 0, i->minn = 0x3f3f3f3f;
  return i;
}
void maintain(node *i) {
  i->maxn = max(i->ls->maxn, i->rs->maxn);
  i->minn = min(i->ls->minn, i->rs->minn);
}
void update(node *i, int l, int r, int pos, int x) {
  if (l == r) {
    if (x == 0)
      i->maxn = i->minn = l;
    else
      i->maxn = 0, i->minn = 0x3f3f3f3f;
    return;
  }
  if (pos <= ((l + r) >> 1))
    update(i->ls, l, ((l + r) >> 1), pos, x);
  else
    update(i->rs, ((l + r) >> 1) + 1, r, pos, x);
  maintain(i);
}
int query_p(node *i, int l, int r, int pos) {
  if (l == r) return i->maxn;
  if (pos <= ((l + r) >> 1)) {
    return query_p(i->ls, l, ((l + r) >> 1), pos);
  } else {
    int tmp = i->ls->maxn;
    return max(tmp, query_p(i->rs, ((l + r) >> 1) + 1, r, pos));
  }
}
int query_s(node *i, int l, int r, int pos) {
  if (l == r) return i->minn;
  if (pos <= ((l + r) >> 1)) {
    int tmp = i->rs->minn;
    return min(tmp, query_s(i->ls, l, ((l + r) >> 1), pos));
  } else {
    return query_s(i->rs, ((l + r) >> 1) + 1, r, pos);
  }
}
struct Edge {
  int id, l, r;
  bool operator<(const Edge &a) const { return id < a.id; }
} edge[1200005];
struct EDGE {
  int to, nex;
} E[1200005 << 1];
int head[1200005];
void add(int i, int j) {
  static int t = 1;
  E[++t] = (EDGE){j, head[i]};
  head[i] = t;
}
int p[1200005], in[1200005], perf[1200005], dp[1200005], vis[1200005];
vector<int> vec_in[1200005], vec_out[1200005];
queue<int> que;
int main() {
  int n = read(), m = read(), cnt = 0;
  for (int i = 1; i <= m; i++) {
    edge[i].id = read(), edge[i].l = p[++cnt] = read(),
    edge[i].r = p[++cnt] = read();
  }
  sort(p + 1, p + 1 + cnt);
  int k = unique(p + 1, p + 1 + cnt) - p - 1;
  for (int i = 1; i <= m; i++) {
    edge[i].l = lower_bound(p + 1, p + 1 + k, edge[i].l) - p;
    edge[i].r = lower_bound(p + 1, p + 1 + k, edge[i].r) - p;
    vec_in[edge[i].l].push_back(edge[i].id);
    vec_out[edge[i].r].push_back(edge[i].id);
  }
  root = build(1, n);
  for (int i = 1; i <= k; i++) {
    if (!vec_in[i].empty())
      for (int j = 0; j <= (int)vec_in[i].size() - 1; j++) {
        int tmp = vec_in[i][j], pre = query_p(root, 1, n, tmp),
            suf = query_s(root, 1, n, tmp);
        if (pre == 0) pre = 0;
        if (suf == 0x3f3f3f3f) suf = n + 1;
        add(pre, tmp);
        add(tmp, suf);
        in[tmp]++;
        in[suf]++;
        update(root, 1, n, tmp, 0);
      }
    if (!vec_out[i].empty())
      for (int j = 0; j <= (int)vec_out[i].size() - 1; j++) {
        int tmp = vec_out[i][j];
        update(root, 1, n, tmp, 1);
      }
  }
  que.push(0);
  while (!que.empty()) {
    int now = que.front();
    que.pop();
    for (int i = head[now]; i; i = E[i].nex) {
      in[E[i].to]--;
      if (dp[E[i].to] < dp[now] + 1) {
        perf[E[i].to] = now;
        dp[E[i].to] = dp[now] + 1;
      }
      if (in[E[i].to] == 0) que.push(E[i].to);
    }
  }
  int tmp = n + 1, ans = -1;
  while (tmp) {
    tmp = perf[tmp];
    vis[tmp] = 1;
    ans++;
  }
  printf("%d\n", n - ans);
  for (int i = 1; i <= n; i++)
    if (!vis[i]) printf("%d ", i);
  return 0;
}
