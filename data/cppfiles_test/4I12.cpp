#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10, mod = 1e9 + 7;
long long head[N], to[N << 1], nex[N << 1], value[N << 1], cnt = 1;
long long a[N], n, k, ans;
long long sz[N], msz[N], vis[N], dis[N], cost[N], stk[N], top, root, sum;
void Add(long long x, long long y, long long w) {
  to[cnt] = y;
  nex[cnt] = head[x];
  value[cnt] = w;
  head[x] = cnt++;
}
inline long long add(long long x, long long y) {
  return x + y < mod ? x + y : x + y - mod;
}
inline long long sub(long long x, long long y) {
  return x >= y ? x - y : x - y + mod;
}
struct Res {
  long long sum[N], cnt[N];
  inline long long lowbit(long long x) { return x & (-x); }
  void update(long long x, long long v, long long op) {
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
  pair<long long, long long> query(long long x) {
    long long ans = 0, res = 0;
    while (x) {
      ans = add(ans, sum[x]);
      res += cnt[x];
      x -= lowbit(x);
    }
    return {ans, res};
  }
} A, B;
void get_root(long long rt, long long fa) {
  sz[rt] = 1, msz[rt] = 0;
  for (long long i = head[rt]; i; i = nex[i]) {
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
void get_dis(long long rt, long long fa, long long pre) {
  stk[++top] = rt;
  for (long long i = head[rt]; i; i = nex[i]) {
    if (to[i] == fa || vis[to[i]]) {
      continue;
    }
    dis[to[i]] += pre != value[i], cost[to[i]] = add(cost[rt], a[to[i]]);
    get_dis(to[i], rt, value[i]);
  }
}
void calc(long long rt) {
  top = 0;
  vector<pair<long long, long long> > vt;
  for (long long i = head[rt]; i; i = nex[i]) {
    if (vis[to[i]]) {
      continue;
    }
    long long l = top + 1;
    dis[to[i]] = 0, cost[to[i]] = a[to[i]];
    get_dis(to[i], rt, value[i]);
    long long r = top;
    if (value[i] == 0) {
      for (long long j = l; j <= r; j++) {
        if (k - dis[stk[j]] >= 0) {
          long long need = k - dis[stk[j]];
          pair<long long, long long> cur = A.query(need + 1);
          ans = add(add(ans, cur.first),
                    1ll * add(cost[stk[j]], a[rt]) * cur.second % mod);
        }
        if (k - dis[stk[j]] - 1 >= 0) {
          long long need = k - dis[stk[j]] - 1;
          pair<long long, long long> cur = B.query(need + 1);
          ans = add(add(ans, cur.first),
                    1ll * add(cost[stk[j]], a[rt]) * cur.second % mod);
        }
      }
    } else {
      for (long long j = l; j <= r; j++) {
        if (k - dis[stk[j]] - 1 >= 0) {
          long long need = k - dis[stk[j]] - 1;
          pair<long long, long long> cur = A.query(need + 1);
          ans = add(add(ans, cur.first),
                    1ll * add(cost[stk[j]], a[rt]) * cur.second % mod);
        }
        if (k - dis[stk[j]] >= 0) {
          long long need = k - dis[stk[j]];
          pair<long long, long long> cur = B.query(need + 1);
          ans = add(add(ans, cur.first),
                    1ll * add(cost[stk[j]], a[rt]) * cur.second % mod);
        }
      }
    }
    for (long long j = l; j <= r; j++) {
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
  long long p = 0;
  for (long long i = head[rt]; i; i = nex[i]) {
    if (vis[to[i]]) {
      continue;
    }
    long long l = vt[p].first, r = vt[p].second;
    p++;
    for (long long j = l; j <= r; j++) {
      if (value[i] == 0) {
        A.update(dis[stk[j]] + 1, cost[stk[j]], -1);
      } else {
        B.update(dis[stk[j]] + 1, cost[stk[j]], -1);
      }
    }
  }
}
void solve(long long rt) {
  vis[rt] = 1;
  calc(rt);
  for (long long i = head[rt]; i; i = nex[i]) {
    if (vis[to[i]]) {
      continue;
    }
    root = 0, sum = sz[to[i]];
    get_root(to[i], rt);
    solve(root);
  }
}
signed main() {
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (long long i = 1, u, v, w; i < n; i++) {
    cin >> u >> v >> w;
    Add(u, v, w);
    Add(v, u, w);
  }
  sum = n, root = 0, msz[0] = 0x3f3f3f3f;
  get_root(1, 0);
  solve(root);
  for (long long i = 1; i <= n; i++) {
    ans = add(ans, a[i]);
  }
  cout << ans << "\n";
  return 0;
}
