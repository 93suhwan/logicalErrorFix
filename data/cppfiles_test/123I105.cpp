#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 10;
long long n, k;
struct Edge {
  long long v, nxt;
} e[maxn << 1];
long long h[maxn], cnt_e;
void add(long long u, long long v) {
  e[++cnt_e] = {v, h[u]};
  h[u] = cnt_e;
}
long long dep[200010], maxd[200010];
void predfs(long long u, long long fa) {
  dep[u] = dep[fa] + 1;
  for (long long i = h[u]; i; i = e[i].nxt)
    if (e[i].v != fa) predfs(e[i].v, u), maxd[u] = max(maxd[u], maxd[e[i].v]);
  maxd[u]++;
}
vector<long long> a;
void dfs(long long u, long long top, long long fa) {
  if (!e[h[u]].nxt && u != 1) {
    a.push_back(dep[u] - dep[top] + 1);
    return;
  }
  long long id = 0;
  for (long long i = h[u]; i; i = e[i].nxt)
    if (e[i].v != fa && maxd[e[i].v] > maxd[id]) id = e[i].v;
  dfs(id, top, u);
  for (long long i = h[u]; i; i = e[i].nxt)
    if (e[i].v != fa && e[i].v != id) dfs(e[i].v, e[i].v, u);
}
int main() {
  scanf("%lld%lld", &n, &k);
  for (long long i = 1; i < n; ++i) {
    long long u, v;
    scanf("%lld%lld", &u, &v);
    add(u, v), add(v, u);
  }
  predfs(1, 0);
  dfs(1, 1, 0);
  long long w = 0, b, r;
  if (k > (long long)a.size())
    r = max(min(k, n / 2), (long long)a.size()), b = 0, w = n - r;
  else {
    sort(a.begin(), a.end(), greater<long long>());
    r = k;
    for (long long i = 0; i < k; ++i) w += a[i] - 1;
    b = min(n / 2, n - w - r);
  }
  printf("%lld\n", w * (r - b));
  return 0;
}
