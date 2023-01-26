#include <bits/stdc++.h>
using namespace std;
long long int tree[4 * 100005];
void update(int n, int st, int en, int idx, int val) {
  if (st == en) {
    tree[n] = val;
    return;
  }
  int mid = (st + en) / 2, lc = 2 * n, rc = lc + 1;
  if (idx <= mid)
    update(lc, st, mid, idx, val);
  else
    update(rc, mid + 1, en, idx, val);
  tree[n] = tree[lc] + tree[rc];
}
long long int query(int n, int st, int en, int l, int r) {
  if (r < st || en < l) return 0;
  if (l <= st && en <= r) return tree[n];
  int mid = (st + en) / 2, lc = 2 * n, rc = lc + 1;
  long long int q1 = query(lc, st, mid, l, r);
  long long int q2 = query(rc, mid + 1, en, l, r);
  return q1 + q2;
}
int n;
int par[100005];
int szz[100005];
vector<int> v[100005];
int depth[100005];
int nxt[100005];
void dfs(int n, int pp = 0) {
  par[n] = pp;
  szz[n] = 1;
  for (int i = 0; i < v[n].size(); i++) {
    int vv = v[n][i];
    if (vv == pp) continue;
    depth[vv] = depth[n] + 1;
    dfs(vv, n);
    szz[n] += szz[vv];
    if (nxt[n] == -1 || szz[vv] > szz[nxt[n]]) nxt[n] = vv;
  }
}
int chain[100005];
int num[100005];
int csz[100005];
int top[100005];
int cnt = 1;
int all;
void hld(int n, int pp = -1) {
  chain[n] = cnt - 1;
  num[n] = all++;
  if (!csz[cnt - 1]) top[cnt - 1] = n;
  csz[cnt - 1]++;
  if (nxt[n] != -1) hld(nxt[n], n);
  for (int i = 0; i < v[n].size(); i++) {
    int vv = v[n][i];
    if (vv == pp || vv == nxt[n]) continue;
    cnt++;
    hld(vv, n);
  }
}
long long int tot[100005];
long long int go(int a, int b) {
  long long int ans = 0;
  while (chain[a] != chain[b]) {
    if (depth[top[chain[a]]] < depth[top[chain[b]]]) swap(a, b);
    int start = top[chain[a]];
    if (num[a] == num[start] + csz[chain[a]] - 1)
      ans += tot[chain[a]];
    else
      ans += query(1, 1, n, num[start], num[a]);
    a = par[start];
  }
  if (depth[a] > depth[b]) swap(a, b);
  ans += query(1, 1, n, num[a], num[b]);
  return ans;
}
void modify(int node, int val) {
  update(1, 1, n, num[node], val);
  int st = num[top[chain[node]]];
  int en = st + csz[chain[node]] - 1;
  tot[chain[node]] = query(1, 1, n, st, en);
}
void ini() {
  memset(nxt, -1, sizeof(nxt));
  memset(v, NULL, sizeof(v));
  memset(csz, 0, sizeof(csz));
  cnt = 2;
  all = 1;
}
int cost[100005];
int main() {
  int t, a, b, q, op;
  t = 1;
  while (t--) {
    ini();
    scanf("%d %d", &n, &q);
    for (int i = 1; i < n + 1; i++) {
      scanf("%d", &cost[i]);
      cost[i] = abs(cost[i]);
    }
    for (int i = 0; i < n - 1; i++) {
      scanf("%d %d", &a, &b);
      v[a].push_back(b);
      v[b].push_back(a);
    }
    dfs(1);
    hld(1);
    for (int i = 1; i < n + 1; i++) modify(i, cost[i]);
    while (q--) {
      scanf("%d %d %d", &op, &a, &b);
      if (op == 1) {
        cost[a] = abs(b);
        modify(a, cost[a]);
      } else
        printf("%lld\n", 2 * go(a, b) - cost[a] - cost[b]);
    }
  }
  return 0;
}
