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
long long len[maxn], son[maxn];
void dfs1(long long u, long long pre) {
  for (long long j = h[u]; j; j = e[j].nxt) {
    long long v = e[j].v;
    if (v == pre) continue;
    dfs1(v, u);
    if (len[u] < len[v]) len[u] = len[v], son[u] = v;
  }
  ++len[u];
}
vector<long long> a;
void dfs2(long long u, long long pre, long long t) {
  if (t == u) a.push_back(len[u]);
  if (son[u]) dfs2(son[u], u, t);
  for (long long j = h[u]; j; j = e[j].nxt) {
    long long v = e[j].v;
    if (v == pre || v == son[u]) continue;
    dfs2(v, u, v);
  }
}
int main() {
  scanf("%lld%lld", &n, &k);
  for (long long i = 1; i < n; ++i) {
    long long u, v;
    scanf("%lld%lld", &u, &v);
    add(u, v), add(v, u);
  }
  dfs1(1, 0);
  dfs2(1, 0, 1);
  long long w = 0, b = n, r = k;
  sort(a.begin(), a.end(), greater<int>());
  for (long long i = 0; i < (long long)a.size() && i < k; ++i) w += a[i] - 1;
  b = min(n >> 1, n - r - w);
  if ((long long)a.size() <= k) r = max(min(n >> 1, k), (long long)a.size());
  printf("%lld\n", w * (r - b));
  return 0;
}
