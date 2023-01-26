#include <bits/stdc++.h>
using namespace std;
const long long N = 2 * 1e5 + 100;
long long n, Q, id[N], dfn[N], out[N], cnt, ans[N];
vector<long long> e[N];
struct node {
  long long a, b;
};
bool operator<(node a, node b) { return a.a * b.b < a.b * b.a; }
node operator+(node a, node b) {
  a.a += b.a;
  a.b += b.b;
  return a;
}
priority_queue<node> q[N];
vector<pair<node, long long> > F;
inline long long read() {
  long long f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
struct bit {
  long long sh[N];
  inline long long lowbit(long long x) { return x & (-x); }
  inline void change(long long x, long long v) {
    while (x <= n) sh[x] += v, x += lowbit(x);
  }
  inline long long query(long long x) {
    long long ans = 0;
    while (x) ans += sh[x], x -= lowbit(x);
    return ans;
  }
} A;
bit B;
struct QQ {
  long long v, k, id;
} sh[N];
bool operator<(QQ a, QQ b) { return a.k > b.k; }
void dfs(long long x, long long fa) {
  dfn[x] = ++cnt;
  if (x != 1) e[x].erase(find(e[x].begin(), e[x].end(), fa));
  for (long long u : e[x]) {
    dfs(u, x);
    if ((long long)q[id[x]].size() < (long long)q[id[u]].size())
      swap(id[x], id[u]);
    while (!q[id[u]].empty()) q[id[x]].push(q[id[u]].top()), q[id[u]].pop();
  }
  out[x] = cnt;
  node now = (node){(long long)e[x].size() - 1, 1};
  long long r = id[x];
  while (!q[r].empty() && now < q[r].top()) {
    node tmp = q[r].top();
    q[r].pop();
    now = now + tmp;
    F.emplace_back(tmp, -fa);
    q[r].pop();
  }
  q[r].push(now);
  F.emplace_back(now, fa);
}
signed main() {
  n = read();
  for (long long i = 1; i < n; i++) {
    long long u = read(), v = read();
    e[u].push_back(v);
    e[v].push_back(u);
  }
  for (long long i = 1; i <= n; i++) id[i] = i;
  dfs(1, 0);
  Q = read();
  for (long long i = 1; i <= Q; i++) sh[i] = (QQ){read(), read(), i};
  sort(sh + 1, sh + 1 + Q);
  sort(F.begin(), F.end());
  for (long long i = 1; i <= Q; i++) {
    long long k = sh[i].k, v = sh[i].v;
    node now = (node){k, 1};
    while (!F.empty() && now < F.back().first) {
      node tmp = F.back().first;
      long long x = F.back().second;
      F.pop_back();
      if (x == 0) continue;
      long long op = 1;
      if (x < 0) x = -x, op = -1;
      A.change(dfn[x], op * tmp.a);
      B.change(dfn[x], op * tmp.b);
    }
    ans[sh[i].id] = A.query(out[v]) - A.query(dfn[v] - 1) -
                    k * (B.query(out[v]) - B.query(dfn[v] - 1));
    ans[sh[i].id] += (long long)e[v].size();
  }
  for (long long i = 1; i <= Q; i++) printf("%lld\n", ans[i]);
}
