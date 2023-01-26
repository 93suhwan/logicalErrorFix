#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, M = N << 1, mod = 1e9 + 7;
int n, k;
int head[N], to[M], nxt[M], val[M], tot;
bool st[N];
pair<int, int> p1[N], p0[N];
int pt0, pt1;
long long tr0_cnt[N];
long long tr1_cnt[N];
long long tr0[N];
long long tr1[N];
int a[N];
int lowbit(int first) { return first & (-first); }
void update(long long tr[], int pos, long long dx) {
  pos++;
  for (int i = pos; i < N; i += lowbit(i)) {
    tr[i] = (tr[i] + dx) % mod;
  }
}
long long query(long long tr[], int pos) {
  pos++;
  long long res = 0;
  for (int i = pos; i; i -= lowbit(i)) {
    res += tr[i];
    res %= mod;
  }
  return res;
}
void add(int u, int v, int w) {
  nxt[++tot] = head[u];
  to[tot] = v;
  head[u] = tot;
  val[tot] = w;
}
int getsz(int u, int pre) {
  if (st[u]) return 0;
  int sum = 1;
  for (int i = head[u]; ~i; i = nxt[i]) {
    int j = to[i];
    if (j == pre) continue;
    sum += getsz(j, u);
  }
  return sum;
}
int getwc(int u, int pre, int tol, int &wc) {
  if (st[u]) return 0;
  int res = 1, ms = 0;
  for (int i = head[u]; ~i; i = nxt[i]) {
    int j = to[i];
    if (j == pre) continue;
    int t = getwc(j, u, tol, wc);
    res += t;
    ms = max(t, ms);
  }
  ms = max(ms, tol - res);
  if (ms <= tol / 2) wc = u;
  return res;
}
void dfs(int u, int pre, int cost, int last_edge, long long tolw,
         pair<int, int> p[], int &pt) {
  if (st[u]) return;
  if (cost <= k) p[++pt] = {cost, (tolw + a[u]) % mod};
  for (int i = head[u]; ~i; i = nxt[i]) {
    int j = to[i];
    if (j == pre) continue;
    dfs(j, u, cost + (last_edge == val[i] ? 0 : 1), val[i], (tolw + a[u]) % mod,
        p, pt);
  }
}
struct docu {
  int type;
  int pos;
  long long dx;
};
long long calc(int u) {
  if (st[u]) return 0;
  getwc(u, -1, getsz(u, -1), u);
  st[u] = 1;
  long long res = 0;
  vector<docu> temp;
  for (int i = head[u]; ~i; i = nxt[i]) {
    pt0 = 0, pt1 = 0;
    if (val[i])
      dfs(to[i], u, 0, val[i], 0, p1, pt1);
    else
      dfs(to[i], u, 0, val[i], 0, p0, pt0);
    for (int j = 1; j <= pt0; ++j) {
      res = (res + p0[j].second + a[u]) % mod;
      res = (res + query(tr0, k - p0[j].first)) % mod;
      res = (res + query(tr1, k - p0[j].first - 1)) % mod;
      res = (res + query(tr0_cnt, k - p0[j].first) * p0[j].second % mod) % mod;
      res = (res + query(tr1_cnt, k - p0[j].first - 1) * p0[j].second % mod) %
            mod;
    }
    for (int j = 1; j <= pt1; ++j) {
      res = ((res + p1[j].second) % mod + a[u]) % mod;
      res = (res + query(tr1, k - p1[j].first)) % mod;
      res = (res + query(tr0, k - p1[j].first - 1)) % mod;
      res = (res + query(tr1_cnt, k - p1[j].first) * p1[j].second % mod) % mod;
      res = (res + query(tr0_cnt, k - p1[j].first - 1) * p1[j].second % mod) %
            mod;
    }
    for (int j = 1; j <= pt0; ++j) {
      update(tr0, p0[j].first, p0[j].second + a[u]);
      temp.push_back({0, p0[j].first, p0[j].second + a[u]});
      update(tr0_cnt, p0[j].first, 1);
      temp.push_back({2, p0[j].first, 1});
    }
    for (int j = 1; j <= pt1; ++j) {
      update(tr1, p1[j].first, p1[j].second + a[u]);
      temp.push_back({1, p1[j].first, p1[j].second + a[u]});
      update(tr1_cnt, p1[j].first, 1);
      temp.push_back({3, p1[j].first, 1});
    }
  }
  for (auto &w : temp) {
    if (w.type == 0) {
      update(tr0, w.pos, -w.dx);
    } else if (w.type == 1) {
      update(tr1, w.pos, -w.dx);
    } else if (w.type == 2) {
      update(tr0_cnt, w.pos, -w.dx);
    } else {
      update(tr1_cnt, w.pos, -w.dx);
    }
  }
  for (int i = head[u]; ~i; i = nxt[i]) {
    int j = to[i];
    res = (res + calc(j)) % mod;
  }
  return res;
}
int main() {
  memset(head, -1, sizeof head);
  long long sum = 0;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    sum = (sum + a[i]) % mod;
  }
  for (int i = 1; i < n; ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    add(u, v, w);
    add(v, u, w);
  }
  printf("%lld", (calc(1) + sum) % mod);
  return 0;
}
