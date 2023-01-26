#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, mod = 1e9 + 7;
int head[N], to[N << 1], nex[N << 1], value[N << 1], cnt = 1;
int a[N], n, k, ans;
int sz[N], msz[N], vis[N], dis[N], cost[N], stk[N], top, root, sum;
void Add(int x, int y, int w) {
  to[cnt] = y;
  nex[cnt] = head[x];
  value[cnt] = w;
  head[x] = cnt++;
}
inline int add(int x, int y) { return x + y < mod ? x + y : x + y - mod; }
inline int sub(int x, int y) { return x >= y ? x - y : x - y + mod; }
struct Res {
  int sum[N], cnt[N];
  inline int lowbit(int x) { return x & (-x); }
  void update(int x, int v, int op) {
    while (x <= n) {
      if (op == 1) {
        sum[x] = add(sum[x], v);
        cnt[x] += 1;
      } else {
        sum[x] = sub(sum[x], v);
        cnt[x] -= 1;
      }
      x += lowbit(x);
    }
  }
  pair<int, int> query(int x) {
    int ans = 0, res = 0;
    while (x) {
      ans = add(ans, sum[x]);
      res += cnt[x];
      x -= lowbit(x);
    }
    return {ans, res};
  }
} A, B;
void get_root(int rt, int fa) {
  sz[rt] = 1, msz[rt] = 0;
  for (int i = head[rt]; i; i = nex[i]) {
    if (vis[to[i]] || to[i] == fa) {
      continue;
    }
    get_root(to[i], rt);
    msz[rt] = max(msz[rt], sz[to[i]]);
    sz[rt] += sz[to[i]];
  }
  msz[rt] = max(msz[rt], sum - sz[rt]);
  if (msz[rt] < msz[root]) {
    root = rt;
  }
}
void get_dis(int rt, int fa, int pre) {
  stk[++top] = rt;
  for (int i = head[rt]; i; i = nex[i]) {
    if (to[i] == fa || vis[to[i]]) {
      continue;
    }
    dis[to[i]] += pre != value[i], cost[to[i]] = add(cost[rt], a[to[i]]);
    get_dis(to[i], rt, value[i]);
  }
}
void calc(int rt) {
  top = 0;
  vector<pair<int, int> > vt;
  for (int i = head[rt]; i; i = nex[i]) {
    if (vis[to[i]]) {
      continue;
    }
    int l = top + 1;
    dis[to[i]] = 0, cost[to[i]] = a[to[i]];
    get_dis(to[i], rt, value[i]);
    int r = top;
    if (value[i] == 0) {
      for (int j = l; j <= r; j++) {
        if (k - dis[stk[j]] >= 0) {
          int need = k - dis[stk[j]];
          pair<int, int> cur = A.query(need + 1);
          ans = add(add(ans, cur.first),
                    1ll * add(cost[stk[j]], a[rt]) * cur.second % mod);
        }
        if (k - dis[stk[j]] - 1 >= 0) {
          int need = k - dis[stk[j]] - 1;
          pair<int, int> cur = B.query(need + 1);
          ans = add(add(ans, cur.first),
                    1ll * add(cost[stk[j]], a[rt]) * cur.second % mod);
        }
      }
    } else {
      for (int j = l; j <= r; j++) {
        if (k - dis[stk[j]] - 1 >= 0) {
          int need = k - dis[stk[j]] - 1;
          pair<int, int> cur = A.query(need + 1);
          ans = add(add(ans, cur.first),
                    1ll * add(cost[stk[j]], a[rt]) * cur.second % mod);
        }
        if (k - dis[stk[j]] >= 0) {
          int need = k - dis[stk[j]];
          pair<int, int> cur = B.query(need + 1);
          ans = add(add(ans, cur.first),
                    1ll * add(cost[stk[j]], a[rt]) * cur.second % mod);
        }
      }
    }
    for (int j = l; j <= r; j++) {
      if (dis[stk[j]] <= k) {
        ans = add(ans, add(cost[stk[j]], a[rt]));
      }
      if (value[i] == 0) {
        A.update(dis[stk[j]] + 1, cost[stk[j]], 1);
      } else {
        B.update(dis[stk[j]] + 1, cost[stk[j]], 1);
      }
    }
    vt.push_back({l, r});
  }
  int p = 0;
  for (int i = head[rt]; i; i = nex[i]) {
    if (vis[to[i]]) {
      continue;
    }
    int l = vt[p].first, r = vt[p].second;
    p++;
    for (int j = l; j <= r; j++) {
      if (value[i] == 0) {
        A.update(dis[stk[j]] + 1, cost[stk[j]], -1);
      } else {
        B.update(dis[stk[j]] + 1, cost[stk[j]], -1);
      }
    }
  }
}
void solve(int rt) {
  vis[rt] = 1;
  calc(rt);
  for (int i = head[rt]; i; i = nex[i]) {
    if (vis[to[i]]) {
      continue;
    }
    root = 0, sum = sz[to[i]];
    get_root(to[i], rt);
    solve(root);
  }
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1, u, v, w; i < n; i++) {
    scanf("%d %d %d", &u, &v, &w);
    Add(u, v, w);
    Add(v, u, w);
  }
  sum = n, root = 0, msz[0] = 0x3f3f3f3f;
  get_root(1, 0);
  solve(root);
  for (int i = 1; i <= n; i++) {
    ans = add(ans, a[i]);
  }
  printf("%d\n", ans);
  return 0;
}
