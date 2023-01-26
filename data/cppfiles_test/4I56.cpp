#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 50, mod = 1e9 + 7;
long long n, k, a[N], sz[N], dat, sum, rt, nn[N][2], ss[N][2], mxx, ans;
bool vis[N];
struct node {
  long long a[N], st[N], tp;
  void add(long long x, long long y) {
    st[++tp] = x;
    for (; x <= n; x += x & -x) (a[x] += y) %= mod;
  }
  long long ask(long long x) {
    long long z = 0;
    for (; x; x -= x & -x) z += a[x];
    return z % mod;
  }
  long long query(long long x) { return x > 0 ? ask(x) : 0; }
  void clear(long long x) {
    for (; x <= n; x += x & -x) a[x] = 0;
  }
  void clear() {
    while (tp) clear(st[tp--]);
  }
} sm[2], num[2];
vector<pair<long long, long long> > v[N];
void cmax(long long &x, long long y) { y > x ? x = y : 0; }
void findr(long long x, long long ff) {
  sz[x] = 1;
  long long now = 0;
  for (long long i = 0; i < v[x].size(); i++) {
    long long y = v[x][i].first;
    if (y == ff || vis[y]) continue;
    findr(y, x);
    cmax(now, sz[y]);
    sz[x] += sz[y];
  }
  cmax(now, sum - sz[x]);
  if (now < dat) dat = now, rt = x;
}
void dfs(long long x, long long ff, long long la, long long z, long long zu,
         long long quan) {
  nn[z][zu]++;
  (ss[z][zu] += quan) %= mod;
  cmax(mxx, z);
  for (long long i = 0; i < v[x].size(); i++) {
    long long y = v[x][i].first;
    if (y == ff || vis[y]) continue;
    if (v[x][i].second == la)
      dfs(y, x, la, z, zu, (quan + a[y]) % mod);
    else
      dfs(y, x, v[x][i].second, z + 1, zu, (quan + a[y]) % mod);
  }
}
void solve(long long x) {
  vis[x] = 1;
  for (long long i = 0; i < v[x].size(); i++) {
    long long y = v[x][i].first, op = v[x][i].second;
    if (vis[y]) continue;
    mxx = 0;
    dfs(y, x, op, 1, op, a[y]);
    for (long long j = 1; j <= mxx; j++) {
      ans = (ans + 1ll * ss[j][op] * num[op ^ 1].query(k + 1 - j) +
             1ll * nn[j][op] * sm[op ^ 1].query(k + 1 - j)) %
            mod;
      ans = (ans + 1ll * ss[j][op] * num[op].query(k + 2 - j) +
             1ll * nn[j][op] * sm[op].query(k + 2 - j)) %
            mod;
    }
    for (long long j = 1; j <= mxx; j++) {
      num[op].add(j, nn[j][op]);
      sm[op].add(j, (ss[j][op] + a[x]) % mod);
      ss[j][op] = nn[j][op] = 0;
    }
  }
  ans = (0ll + ans + sm[0].query(k + 1) + sm[1].query(k + 1)) % mod;
  sm[0].clear();
  sm[1].clear();
  num[0].clear();
  num[1].clear();
  for (long long i = 0; i < v[x].size(); i++) {
    long long y = v[x][i].first;
    if (vis[y]) continue;
    sum = sz[y];
    dat = 1e9;
    findr(y, x);
    solve(rt);
  }
}
signed main() {
  sm[0].clear();
  sm[1].clear();
  num[0].clear();
  num[1].clear();
  scanf("%lld%lld", &n, &k);
  for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]), (ans += a[i]) %= mod;
  for (long long i = 1, x, y, z; i < n; i++) {
    scanf("%lld%lld%lld", &x, &y, &z);
    v[x].push_back(make_pair(y, z));
    v[y].push_back(make_pair(x, z));
  }
  dat = 1e9;
  sum = n;
  findr(1, 0);
  solve(rt);
  printf("%lld\n", ans);
  return 0;
}
